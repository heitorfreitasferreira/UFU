# Esquema, instância e estado em um banco de dados

## Esquma

> Modelo

O esquema é uma descrição do banco de dados

## Instância

> Ocorrência

É qualquer ocorrência de um dado em seu banco, por exemplo o registro dos dados de um aluno

## Estado

> Conjunto

Conjunto de instâncias em um determidado momento

# SGBD - Sistema de Gerenciamento de Banco de Dados

> Software que gerencia banco de dados e meta dados

- Ex:
  - Oracle
  - PostgreSQL
  - MySQL
  - Sybase
  - MS Sql Server
  - MS Access
  - Firebird
  - MongoDB
  - Cassandra
  - ...

## Definição de SBD

> SBD = BD + SGBD + Aplicação

## Alternativa à abordade de SBD

Caso não usassemos SBD's para guardar as informações tudo seria armazenado em arquivos convencionáis (.txt), ou arquivos binários, e o acesso seria diretamente pela aplicação

### Problemas de usar arquivos convencionáis

- Inconsistência e redundancia
- Acesso aos dados
- Isolamento de dados
  - Os dados só podem ser acessados e manipulados por meio a interface do SGBD, como esse sistema gerencia a baixo nível não importa pra quem o está usando
- Integridade
  - Restrições de acesso e alteração seriam implementadas pelo programador da aplicação, variando de sistema pra sistema
- Atomicidade
  - Significa que em um conjunto de comandos, ou todos são executados ou nenhum é
  - Difícil de garantir quando usando arquivos convencionáis
- Acesso concorrente
  - Duas pessoas tentarem fazer um saque ao mesmo tempo na mesma conta, como garantir que as duas operações serão feitas na ordem correta
- Escalabilidade
  - Extremamente complexo acessar e fazer operações em arquivos muito grandes
- Segurança

## Componentes de um BD

![Esquema mostrando os componentes de um SBD e como eles se relacionam](images/componentes_sbd.jpg)

## Independência de dados

- Independência ***lógica***
  - Alteração no nível lógico não afeta o programa que consome o banco
  - Exemplo: inserção de uma nova tabela
- Independência ***física***
  - Alteração na estrutura de arquivos e índices não afetam o nível lógico
  - Exemplo: criação de um índice para melhor desempenho

## Profissionais envolvidos

- Implementadores de BD
- Projetistas de BD Lógico
- Projetistas de BD Físico
- Administradores de BD (DBA)
- Programadores de aplicações e sistemas
- Usuários finais

## Histórico das arquiteturas de BD

- Sistemas monolíticos centralizados (mainframes)
- Arquitetura cliente/servidor em **duas** camadas
- Arquitetura cliente/servidor em **três** camadas
  - Cliente -> GUI/Apresentação (front-end)
  - Servidor WEB -> Aplicação e lógica de negócios 
  - Servidor BD -> SGBD/Serviços BD
- BD e Mobilidade
  - Ideia de fazer alterações na aplicação offline e quando se conectar todo trabalho feito é sincronizado
  - Exemplo: mandar mensagem no Whatsapp sem internet

## Linguagens de definição e manipulação

- DDL (**definição**)
  - esquema conceitual
  - esquema interno
  - esquema externo
- DML (**manipulação**)
  - busca
  - inserção
  - modificação
  - remoção

> Outras linguagens

- API
  - ODBC
  - JDBC
  - Outros drivers
    - Mongoose no Node para manipular e definir dados no MongoDB
- Interface
  - menus
  - formulários
  - gráficas
  - administração

## Modelos de dados - Exemplos

- Modelo ***Entidade-Relacionamento*** - ER(*)
- Modelo Orientado a Objetos
- Modelo Semântico de Dados
- Modelo Hierarquico
- Modelo de Redes
- Modelo Relacional (*)
- Modelo Relacional - Orientado a objetos

> Nesta disciplica estudaresmo o ER e o Relacional

