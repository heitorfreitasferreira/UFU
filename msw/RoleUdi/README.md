# Role Udi 

Aluno | Matricula
-|-
Heitor Freitas Ferreira | 11921BCC026
Luis Gustavo Seiji Tateishi | 11921BCC034

## TO-DO's

- [x] Texto apresentando o sistema
- [x] Escolha da ferramenta UML
- [ ] Use Case Model

## Entrega 1

### Concepção do sistema

> RoleUdi

RoleUdi será um sistema para conectar as pessoas à eventos de seu interesse e também mante-las organizadas quanto à datas, custos locais e formas de chegar.  
Ao abrir a aplicação (com front-end web e mobile (iOS e Android usando framework de desenvolvimento hibrido), o usuário deverá criar uma conta obrigatóriamente para o uso da aplicação, apenas com um e-mail, senha, confirmação de senha e aguardar confirmação via e-mail.  
Ao criar a conta a primeira ação que o usuário deverá ser escolher os nichos de eventos que irá seguir (universitário, cervejeiro, sertanejo, baile, etc), um usuário poderá seguir vários nichos ao criar a conta e mudar os nichos seguidos a qualquer momento em uma seção de configuração de perfil.  
Com a conta criada e os nichos escolhidos, haverá duas formas de visualização dos eventos, via mapa e via calendário, sendo possível alternar entre as duas livremente, eventos sem datas definidas aparecerão no mapa mas não no calendário, eventos com data definida e sem local aparecerão somente no calendário, eventos com estas informações não definidas mas já anunciados irão para uma janela separada.  
Usando a visualização de calendário será aberta uma interface similar à interface do Google Agenda, mas com as "colunas" ordenadas com os eventos com mais destaques (chamados: roles quentes) acima. Os eventos "sobem" na escala de "quente" com votos populares, média de nota das festas dos organizadores dos eventos, quantidade de usuários que marquem que estão com vontade de ir/com ingresso comprado/querendo comprar ingresso e quantidade de pessoas vendendo o ingresso (esta diminuíndo o "score" do evento).  
Visualizando em mapa, os eventos serão dispostos tais quais os locais no Google Maps com um mini banner do evento em forma de pin alocado no local onde será o evento, caso tenham vários eventos no mesmo local, o que será mostrado será o próximo que acontecerá, será possível escolher a data exata que o mapa mostrará os eventos.  
Um filtro poderá ser aplicado em qualquer tipo de visualização para visualizar somente os eventos que o usuário marcou que irá e os eventos que os usuários que a conta segue irão.  
Caso o usuário clique em um evento, será aberta uma página que mostrará os detalhes do evento, como nome, lista de contatos que marcaram que irão no evento, data, local, organizadore, será possível marcar que está com interesse de ir, presença confirmada (ingresso comprado) e lista dos perfis de instagram do evento, organizadores e das atrações.  
A forma de monetização será a venda de dados (e alma) sobre os eventos e os usuários para potênciais compradores.

### Definição da ferramenta UML

A ferramenta que usaremos para fazer a modelagem UML será o site *[Lucidchart](https://www.lucidchart.com/)*

### Modelo de casos de Uso Preliminar do Sistema

Atores:

- Usuário
  - Consumidor novo
  - Consumidor cadastrado
  - Organizador de evento
- API Agenda
- API Mapa
- Banco(À verificar)
- Serviço de OAuth

#### Register 

1. Novo usuário entra no APP pela primeira vez ou após "deslogar" e seleciona "registar"
2. Novo usuário digita email, senha, telefone, confirmação da senha
3. Sistema verifica se já existe usuário com este email
4. Sistema verifica se a senha é igual a confirmação
5. Sistema envia SMS com código verificador
6. Usuário entra com o código verificador

Extensão:

3a. Não é possível criar conta pois já existe
1. Sistema colhe as informações novamente


4a. Senha não confere com a contra senha
1. Sistema colhe as senhas novamente


5a. Erro ao enviar ou receber SMS
1. Usuário solicita outro SMS


5b. Usuário errou o número de telefone
1. Usuário corrigi o telefone e sistema envia SMS para o novo número


6a. Usuário entra com código errado
1. Sistema apaga campo, avisa que está errado e solicita re-inserção do código verificador

#### Login

1. Usuário registrado entra no APP pela primeira vez ou após "deslogar" e seleciona "login"
2. Usuário registrado digita email, senha
3. Sistema verifica se existe um cadastro com essas informações
4. Sistema da acesso à aplicação

Extensão:

3a. Usuário ou senha incorretos
1. Sistema colhe as informações novamente 

#### Filtrar por localização

1. Usuário registrado(logado) seleciona a opção de visualização por mapa
2. Sistema mostra o mapa com os eventos cadastrados

#### Filtrar por data

1. Usuário registrado(logado) seleciona a opção de visualização por data
2. Sistema mostra o mapa com os eventos cadastrados

#### Entrar na página do evento

1. Usuário registrado(logado) clica em um evento estando no modo mapa ou calendário
2. Sistema abre janela com informações detalhadas do evento

#### Fazer compra do ingresso

1. Estando na página do evento, usuário clica no botão de compra
2. Sistema redireciona ao provedor de ingressos utilizado pelo evento


#### Cadastrar um evento

1. Cliente cadastrado como organizador do evento clica em cadastrar evento
2. Cliente cadastrado insere localização, data e link para compra do evento
3. Sistema registra o evento no banco

Extensão:

2a. Localização, data ou link inválidos
1. Sistema colhe as informações novamente

#### Dar nota ao evento

1. Usuário entra na página do evento já encerrado
2. Seleciona uma nota de 1 a 5 para o evento

#### Marcar presença em evento

1. Usuário entra na página do evento que ainda não aconteceu
2. Usuário marca dentre as opções "Ingresso comprado", "Quero ir" e "Não vou" (opção padrão)

#### Selecionar nichos

1. Novo usuário ao entra na conta pela primeira vez
2. Sistema apresenta $n$ "nichos" de eventos
3. Novo usuário clica para selecionar $m$ "nichos" sendo $m<=n$ e $m>0$

Extensão

2a. Usuário não seleciona nenhum nicho
1. Sistema não permite avanço para a tela inicial enquanto não selecionar pelo menos um

#### Solicitar amizade

1. Usuário registrado entra na lista que contem os contatos dele que tem conta cadastrada no Sistema (chave->telefone)
2. Usuário clica em "Adicionar amigo"
3. Sistema envia para o "amigo" uma notificação avisando que houve a solicitação e perguntando se aceita ou não

Extensão

1a. Usuário não deu permissão à aplicação para ver seus contatos ou não possui contatos com conta no Sistema
1. Sistema mostra lista vazia de possíveis amigos

2a. Segundo clique no botão de "Adicionar amigo"
1. Sistema cancela o envio da solicitação

#### Aceitar amizade

1. Usuário recebe notificação por push e dentro do sistema que ouve uma solicitação para criar um vinculo de amizade
2. Usuário seleciona se aceita,rejeita ou bloqueia

Extensão

2a. Usuário clica em aceitar
1. Sistema cria um vinculo de amizade entre os dois nós

2b. Usuário clica em rejeitar
1. Sistema deleta a notificação e ambos conseguem solicitar a amizade posteriormente

3c. Usuário clica em bloquear
1. Sistema não permite a solicitação novamente até que o(s) usuário(s) que bloqueou(aram) retire o outro da lista de bloqueados

## Entrega 2

### Revisão da concepção e estudo de viabilidade
Sugestões do professor durante a apresentação:
- Feedback com opção de comentar o por que da avaliação
- Tirar Role Udi Maps/Role Udi Agenda
- Colocar Google Maps/Google Agenda
- Sistema de compra de ingressos(talvez)

### Especificação dos requisitos completa.

## Entrega 3

### Revisão dos artefatos anteriores

### Projeto Arquitetural Preliminar

## Entrega 4
