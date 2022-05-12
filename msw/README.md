# Modelagem de Software

## Requisitos de software

- Engenharia de requisitos de software
- Elicitação de requisitos
  - Obtenção de informações detalhadas sobre o que iremos fazer
  - Levantamento e obtenção de problemas
  - Identificar
- Análise de requirimentos
- Especificação de Software
- Validação de requerimentos
- Gerenciamento de requerimentos

### Documento de requisito de Software

- Declaração oficial do que é demandado dos desenvolvedores
- Deve incluir uma definição de requisitos do **usuário** e uma especificação de requisitos do sistema
- **Não** é um documento de projeto
  - Defini ***O QUE*** e não o ***COMO*** fazer

### Capitulos presma
[TODO]
- Prefacio
- Introdução
- Glossário
- Difinição de usuario
- Arquitetura do sistema
- Especiicação de requisitos de sistema
- ***Modelos do sistema***
  - Você está aqui!
  - Modelos gráficos descritos no capítulo: RUP: UML
- Evolução do sistema
- Apêndices
- Índices

## RUP: *UML*

### ***Use case***

> Funcionalidade pela visão do usuário

- *MOPS*: Business Analyst: **5**
- *MOSS:* Designer: **2**
- *MOBS:* Architect: **1**

#### O Que é:

- Forma de capturar requisitos funcionais
  - Problema: e requisitos não-funcionais?
- Descreve ***interação*** entre "usuários" e os sistemas
- Prove uma narrativa de como o sitema é usado

#### Como criar

> UM caso de uso é um conjunto de roteiros ligados conjuntamente por um objetivo comum do usuário

- Roteiros:
  1. O consumidor ve o catalho e adiciona ao carrinho os itens desejados
  2. QUando o consumidor quiser pagar, irá descrever o endereço de entrega e forma de pagamento para confirmar a senha
  3. O sistema checa a autorização do cartão e confirma a senha imediatamente e por e-mail
- E se:
  1. A autorização de cartão falhar?
  2. Se o cliente já tem informação de envio e de cartão cadastradas?

#### Atores

> O sujeito do predicado que é o caso de uso

- Papéis representados por elementos que interagem em um sistema
- Um ator por interagir atráves de város casos de uso
- Um caso de uso pode ser executado por vários atores
- Ator é algo externo ao sistema
- **Um ator por der um sistema externo** (API)

#### Descrição de um caso de uso

> Mostra a interação entre cliente e sistema

Comprar um produto:

1. Cliente navega no catalogo e seleciona item
2. Cliente clica para fazer checkout
3. Cliente preenche as informações de de envio
   1. Cliente é um cliente regular
      1. [TODO]
4. Sistema apresenta informação completa do pedido, incluindo frete
5. Cliente preenche as informações de pagamento
6. Sistema autoriza a compra
7. Sistema confirma a compra
8. Sistema envia informações de confirmação da compra por e-mail

#### Outras possíveis informações

- Pré-condição: o que o sistema deve garantir antes do caso de uso começar
  - Exemplo: verificar se o cliente já está logad
- Garantia: o que o sistema vai garantir no final
  - Pós-condição
  - Após um cenário bem sucedido, o que irá acontecer
  - Exemplo: e-mail foi enviado após a compra
- Gatilho: qual evento iráiniciar o caso de uso
  - Exemplo: meia noite será enviada um e-mail com promoções

### Activity

> O fluxo dentro de um "use case" ou do sistema

- *MOPS*: Business Analyst: **5**
- *MOSS:* Designer: **2**
- *MOBS:* Architect: **1**

### ***Class***

> Classes, entidades, dominio de negocios

- *MOPS*: Business Analyst: **3**
- *MOSS:* Designer: **5**
- *MOBS:* Architect: **2**

### Sequence

> Interação entre os objetos

- *MOPS*: Business Analyst: **4**
- *MOSS:* Designer: **5**
- *MOBS:* Architect: **1**

### Interaction overview

> Interação a um alto nível 

- *MOPS*: Business Analyst: **4**
- *MOSS:* Designer: **2**
- *MOBS:* Architect: **2**

### Communication

>  Interação entre os objetos

- *MOPS*: Business Analyst: **1**
- *MOSS:* Designer: **3**
- *MOBS:* Architect: **1**


### Object

> Objetos e seus links 

- *MOPS*: Business Analyst: **1**
- *MOSS:* Designer: **5**
- *MOBS:* Architect: **3**


### State machine

>  

- *MOPS*: Business Analyst: **3**
- *MOSS:* Designer: **4**
- *MOBS:* Architect: **2**


### Composite structe

>  

- *MOPS*: Business Analyst: **1**
- *MOSS:* Designer: **5**
- *MOBS:* Architect: **4**


### Component

>  

- *MOPS*: Business Analyst: **1**
- *MOSS:* Designer: **3**
- *MOBS:* Architect: **5**


### Deployent

>  

- *MOPS*: Business Analyst: **2**
- *MOSS:* Designer: **2**
- *MOBS:* Architect: **5**


### Package

>  

- *MOPS*: Business Analyst: **3**
- *MOSS:* Designer: **2**
- *MOBS:* Architect: **4**


### Timing

>  

- *MOPS*: Business Analyst: **1**
- *MOSS:* Designer: **3**
- *MOBS:* Architect: **3**

