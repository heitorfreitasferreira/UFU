# Aula 2

## Vantagens

## Desvantagem

## Visão estruturada

* Dispersão de dados e funções
  * Todos podem entrar e acessar os dados
    * Dificulta a depuração
  * Não há *encapsulamento*
* Decomposição de problema (Exemplo de gestão académica)
  * Funcionalidades
    * Lançar disciplinas
    * Associar alunos a disciplinas
    * Efetuar matriculas
    * lançar notas
    * Consultar médias
    * Lançar faltas

## Visão Orientada a Objetos

* Tentar aproximar o real do virtual
* Utilizar objetos, que formam o mundo
* Programador molda os objetos e define as interações entre objetos
* Permite baixo acoplamento
  * Código não depende um do outro
  * Maior reutilização de código
  * Cada objeto tem uma responsabilidade clara
* Decomposição de problema (Exemplo de gestão académica)
  * Componentes do problema
    * Disciplina
    * Alunos
    * Professor
  * Comunicação entre componentes
    * Mensagens
* Trazer a solução para junto do problema
  * Objeto: pequena parte do problema
    * Informações especificas (dados), estados e operações a serem executadas

### Vantagens da OO

* Mais intuitiva
  * Bom para cliente
  * Bom para o analista e desenvolvedores
* Fácil de manter e atualizar
* Mais coesa

### Programa em linguagem OO

* Definição
  * Conjunto de objetos dizendo uns para os outros o que fazer através de envio de mensagens
    * Mensagens seriam análogas a funções (métodos) que pertencem a um objeto em particular
* Cada Objeto
  * Tem sua própria memória
  * Tem um conjunto de operações que ele realiza e que afetam seus dados
  * Possui:
    * um tipo que é chamado de  **CLASSE**
    * Identidade
    * Estado
    * Comportamento
* Transferência de responsabilidade do procedimento para o próprio dado (objeto)
  
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
  * Depois de um objeto ser construido, testado e eliminado os bugs, não se precisa se preocupar com a implementação da criação do objeto
* Maneira natural de pensar
  * É mais intuitivo pensar na solução lidando com objetos e responsabilidades desses
  * Mais perto do linguajar comum
* Dados e funcionalidades encapsuladas
  * Para alterar atributos de um objeto somente com funções
  * Somente alguns atores do sistema podem alterar certos dados
    * Ex: somente pode mudar a marcha do carro o motorista e se o carro estiver em movimento
    * Ex: somente o dono da conta pode acessar a interface que faz saque, e somente se houver saldo suficiente
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

# Aula 3

## Introdução

* Ao escrever um programa OO, cria um modelo do mundo real
  * Modelo descrito por partes, que são ***objetos***
  * Os **Objetos** possuem características próprias: **atributos**
  * Os **Objetos** possuem funções próprias: **métodos**
  * Os **Objetos** podem ser categorizados: **classe**

## Objetos

>Elementos componentes de um problema

* Representação de algo do mundo real no código
* Quando um objeto conversa com outro, ele quer alterar o estado desse objeto
  * Alteração de estado = mudar algum atributo
  * Exemplo: alguém alterar o saldo de uma conta
* Métodos
  * Meio por qual se altera o estado de algum objeto
* Identidade
  * Unívoca
  * Distinção por sua própria existência
    * Dois objetos são distintos mesmo que todos os seus atributos sejam iguais
  * Identificador único para cada objeto
  * Persistência
    * Tempo de vida de um objeto
      * Temporário
        * Existe enquanto o programa ta em execução
      * Permanente
        * Armazenar o objeto em meio físico (arquivos ou bancos de dados)

## Comunicação entre objetos

* Mensagens
  * Elemento para promover comunicação entre objetos
  * Definem
    * Nome do serviço requisita
    * Informação necessária para a execução do serviço
    * Nome do requisitante

## Classe

* Objetos de um mesmo tipo possuem os mesmos comportamentos
* Objetos do mesmo tipo pertencem à mesma classe
  * NomeDaClasse nomeObjeto
* Define
  * Atributos
  * Métodos
* Exemplo
  * Classe: cachorro
  * Objetos: Rex, Monalisa, Manuela
  * Atributos: peso, altura, nome, cor, pelagem
* Ao criar um objeto a partir da classe, damos valor a cada um dos atributos
  * Exemplo de instanciar classe:

  * ```javascript
      Rex = {
        peso: 20,
        nome: "rex",
        cor: "marrom",
        altura: 0.6,
        pelagem: "curta"
      }
      ```

### Atributos

* Definições: classes
* Valores associados: objetos
* Atributos de objetos (individuais)
  * Atributo individual armazenado no objeto
  * Cada Objeto define um valor inicial, que pode coincidir com valor de outros objetos
  * Área de memória reservada
* Atributo de classe (coletivos)
  * Palavra reservada ```static```
  * Mesmo valor **inicial** é dividido entre todos os objetos
  * Valores armazenados na classe (mesma área de memória)

### Métodos

>Serviço que o objeto fornece

* Comportamentos, ações, reações dos objetos
* Pode manipular os atributos do seu objeto
  * Altera estado
* Exemplo
  * Objeto carro tem o método acelerar, frenar, virar para esquerda, virar pra direita

## Classes do Java para fazer leitura de dados do teclado

### Scanner

```java
  import java.util.Scanner;
  Scanner entrada = new Scanner(System.in);
  String nomeCurso = entrada.nextLine();
  System.out.println(nomeCurso)
```

## String

>Existem 2 formas de criar uma string

```java
  String ola1 = new String("Hello World1");
  String ola2 = "Hello World2"
```

A primeira forma tem a vantagem de poder usar os métodos da classe String

* length;
* concat();
* contains(String s);
* string1.equal(String string2);
* indexOf(int ch);
* toLowerCase();
* toUpperCase();
* trim();
* replace(char oldChar, char newChar);
* substring(int ini, int fim);
* lastIndexOf(int ch)

### Formatação de dados (string)

* System.out.printf()
  * Igual printf do C
* format
  * Método da classe string

      ```java
        String name = "Heitor";
        String sf1 = String.format("Meu nome é %s",name);
      ```
