
## Vantagens

## Desvantagem

## Visão estruturada

* Dispersão de dados e funções
  * Todos podem entrar e acessar os dados
    * Dificulta a depuração
  * Não há *encapsulamento*
* Decomposição de problema (Exemplo de gestão academica)
  * Funcionalidades
    * Lançar diciplinas
    * Associar alunos a diciplinas 
    * Efetuar matriculas
    * lançar notas
    * Consultar médias
    * Lançar faltas

## Visão Orientada a Objetos

* Tentar aproximar o real do virtual
* Utilizar objetos, que formam o mundo
* Programador molda os objetos e define as interações entre objetos
* Permite baixo acomplamento
  * Código não depende um do outro
  * Maior reutilização de código
  * Cada objeto tem uma responsabilidade clara
* Decomposição de problema (Exemplo de gestão academica)
  * Componentes do problema
    * Diciplina
    * Alunos
    * Professor
  * Comunicação entre componentes
    * Mensagens
* Trazer a solução para junto do problema
  * Objeto: pequena parte do problema
    * Informações especificas (dados), estados e operações a serem executadas

### Vantagens

* Mais intuitiva
  * Bom para cliente
  * Bom para o analista e desenvolvedor
* Facil de manter e atualizar
* Mais coesa

### Programa em linguagem OO

* Definição
  * Conjunto de objetos dizendo uns para os outros o que fazer atráves de envio de mensagens
    * Mensagens seriam analogas a funções (métodos) que pertencem a um objeto em particular
* Cada Objeto
  * Tem sua própria memória
  * Tem um conjunto de operações que ele realiza e que afetam seus dados
  * Possui:
    * um tipo que é chamado de  **CLASSE**
    * Identidade
    * Estado
    * Comportamento
* Transferencia de responsabilidade do procedimento para o próprio dado (objeto)
  
## Programação tradicional VS POO

### Tradicional
Sistema esperando que uma sequencia de operações seja executada e apresente o resultado esperado
* Dados e funções: entidades diferentes
* Não sabemos a relação entre si


### OO
Sistema possui um conjunto de objetos que possuem determinados comportamentos que interagem entre si
* Dados e funções: partes de um elemento básico (objeto)

## Vantagens técnicas da OO

* Código enxuto
  * Sistemas OO não precisam se preocupar com loop ou desvios, e sim com eventos que alteram um objeto
  * Alteração do estado de um objeto
* Caixa preta
  * Depois de um objeto ser contruído, testado e eliminado os bugs, não se precisa se preocupar com a implementação da criação do objeto
* Maneira natural de pensar
  * É mais intuitivo pensar na solução lidando com objetos e responsabilidades desses
  * Mais perto do linguajar comum
* Dados e funcionalidades encapsuladas
  * Para alterar atributos de um objeto somente com funções
  * Somente alguns atores do sistema podem alterar certos dados
    * Ex: somente pode mudar a marcha do carro o motorista e se o carro estiver em movimento
    * Ex: somente o dono da conta pode acessar a interface que faz saque, e somente se ouver saldo suficiente
* Cada objeto é independente
* Reusabilidade
  * Utilizar uma classe aluno no portal do aluno e no app da ufu
  * Criar bibliotecas é mais simples

## Criação de um Sistema OO

### Modelagem conceitual

> Análise dos objetos do mundo real envolvidos no problema e suas relações

### Representação da visão
* Descobrir os conceitos 
* Definir os elementos básicos