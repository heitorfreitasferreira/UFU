# Heitor Freitas Ferreira - 11921BCC026

## Ex1

![Imagem EER](EER.png)

## Ex2

```sql
CREATE SCHEMA SFP;
SET search_path TO SFP;
-- PESSOA E SEUS DERIVADOS
CREATE TYPE tipoTitulacao AS ENUM
('GRADUADO', 'MESTRE', 'DOUTOR');

CREATE TABLE FUNCIONARIO
(
  id SERIAL PRIMARY KEY NOT NULL,
  fk_pessoa INT NOT NULL,
  salario DECIMAL (10,2) NOT NULL CHECK(salario>0)
);
CREATE TABLE BOLSISTA
(
  id SERIAL PRIMARY KEY NOT NULL,
  fk_pessoa INT NOT NULL,
  bolsa DECIMAL
(10,2) NOT NULL CHECK(bolsa>0)
);
CREATE TABLE PESSOA
(
  id SERIAL PRIMARY KEY NOT NULL,
  cpf VARCHAR(11) UNIQUE NOT NULL,
  nome VARCHAR(50),
  titulacao tipoTitulacao,
  fk_funcionario INT,
  fk_bolsista INT
);
ALTER TABLE PESSOA ADD CONSTRAINT fk_funcionario FOREIGN KEY (fk_funcionario) REFERENCES FUNCIONARIO(id);
ALTER TABLE PESSOA ADD CONSTRAINT fk_bolsista FOREIGN KEY(fk_bolsista) REFERENCES BOLSISTA(id);
ALTER TABLE BOLSISTA ADD CONSTRAINT fk_pessoa FOREIGN KEY(fk_pessoa) REFERENCES PESSOA(id);
ALTER TABLE FUNCIONARIO ADD CONSTRAINT fk_pessoa FOREIGN KEY(fk_pessoa) REFERENCES PESSOA(id);

-- AGÊNCIA

CREATE TYPE tipoAgencia AS ENUM
('PRIVADA', 'MUNICIPAL', 'ESTADUAL', 'FEDERAL');

CREATE TABLE AGENCIA
(
  id SERIAL PRIMARY KEY NOT NULL,
  nome VARCHAR(50) UNIQUE,
  dataInicial DATE NOT NULL,
  duracao INT NOT NULL,
  tipo tipoAgencia NOT NULL,
  orcamentoAnual DECIMAL(10,2) NOT NULL
);

--PROJETO

CREATE TABLE PROJETO
(
  id SERIAL PRIMARY KEY NOT NULL,
  nome VARCHAR(50),
  dataInicial DATE NOT NULL,
  duracao INT NOT NULL CHECK(duracao>0),

  coordenador INT NOT NULL,
  CONSTRAINT fk_funcionario
    FOREIGN KEY(coordenador)
      REFERENCES FUNCIONARIO(id),

  patrocinador INT NOT NULL,
  CONSTRAINT fk_agencia
    FOREIGN KEY (patrocinador)
      REFERENCES AGENCIA (id)
);

CREATE TABLE ATIVIDADE
(
  id SERIAL PRIMARY KEY NOT NULL,
  nome VARCHAR(50),

  projeto INT NOT NULL,
  CONSTRAINT fk_projeto
    FOREIGN KEY(projeto)
      REFERENCES PROJETO(id),

  atividade_pai INT,
  CONSTRAINT fk_atividade_pai
    FOREIGN KEY(atividade_pai)
      REFERENCES ATIVIDADE(id)
);

CREATE TABLE PARTICIPACAO
(
  atividade INT NOT NULL,
  CONSTRAINT fk_atividade
    FOREIGN KEY(atividade)
      REFERENCES ATIVIDADE(id),

  pessoa INT NOT NULL,
  CONSTRAINT fk_pessoa
    FOREIGN KEY(pessoa)
      REFERENCES PESSOA(id),

  PRIMARY KEY (atividade,pessoa)
);
```

## Ex 3

### A

```
π (nomepes,titulospil((ζtitulospil>5 ∧ pontuacaopil>50)⋈idpes(piloto)))
```

### B

```
π(nomeesqui,nomepes(((mecanico)⋈(idpes(pessoa)))⋈(idequ(equipe))))
```

### C

```
(circuito)∪(<131, AutodromodeUberlandia, Brasil>)
```