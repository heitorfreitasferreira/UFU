# Programação Orientada a Objetos ***2***

> Como fazer um bom código orientado a objetos

## Ementa


### Livro texto da disciplina

GAMA, Erich. **Padrões de projeto: soluções reutilizáveis de software orientado a objetos.** Porto Alegre : Bookman, 2005



## Padrões de projeto

> **Reutilizar a experiência** de outros devs com problemas semelhantes
> 
> Alto nível de reuso

- Facilita a reutilização de soluções de desenho
- Estabelece um vocabulário comum, facilitando a comunicação, documentação e aprendizado de sistemas de software
- Projetar OO é difícil, projetar OO reutilizável é mais complicado ainda
- Projeto deve ser flexível para atender requisitos futuros
- Bons projetistas não caem em POG (programação orientada a gambiarra), e projetam realmente orientado a objetos

### Caracteristicas de um padrão de projeto

- Encapsulamento: um padrao encapsula um problema em uma solução bem definida
- Generalidade: todo padrão de projeto deve 
- Abstrato: representação abstratas

### Conjuntos de padrões 

- ***Criação***: criar novos objetos
- ***Estruturais***: associaçoes entre classes e objetos
  - Melhora o design
- ***Comportamentais***: interações e divisões de responsabilidades
  - Melhora em tempo de execução

## Padrão Strategy

> As vezes a herança não resolve, cria soluções inflexíveis e difíceis de manter...

Exemplo: 
Uma classe *A* implementa dois métodos, ***m1(a1)*** e ***m2(a2)***  
As seguintes subclasses de A implementam os métodos:
- B: ***m1(a1)*** e ***m2(a2)***
- C: ***m1(a1)*** e ***m2(a3)***
- D: ***m1(a4)*** e ***m2(a2)***
- E: ***m1(a4)*** e ***m2(a3)***

```js
class A{
  m1(){
    console.log("Implementa o algoritmo 1")
  }
  m2(){
    console.log("Implementa o algoritmo 2")
  }
}
class B extends A{

}
class C extends A{
  m2(){
    console.log("Implementa o algoritmo 3")
  }
}
class D extends A{
  m1(){
    console.log("Implementa o algoritmo 4")
  }
}
class E extends A{
  m1(){
    console.log("Implementa o algoritmo 4")
  }
  m2(){
    console.log("Implementa o algoritmo 3")
  }
}
```

Uma forma de melhorar é ao identificar que a classe *E* pode na realidade herdar da *D*, me diminuindo uma sobreescrita de método

```js
class E extends D{
  m2(){
    console.log("Implementa o algoritmo 3")
  }
}
```

Mas ao usar o padrão Strategy é imporatante **identificar os aspectos que variam** e separá-los do que é comum à todas sub-classes

> Usar composição no lugar de herança

Pergunta: quais aspectos variam, quantas variações temos

### Aplicando o padrão strategy

- Permite definir famílias de comportamentos, que podem ser (re)utilizados de forma intercambiável
- permite que o algoritmo varie independentemente dos clientes que o usam
- Cada comportamento é encapsulado com ***uma*** classe

> ENCAPSULAMENTO + MODULARIZAÇÃO = MANUTENIBILIDADE + REUSABILIDADE

```java

// Classe que agrupa os métodos diferentes usados
abstract class M1(){
  //Algoritmos de machine learning
  public abstract m();
}
abstract class M2(){
  //Algoritmos de criptografia
 public abstract m();
}
//Classes de suporte que implementam os diferentes algoritmos
public class A1 extends M1{
  public void m(){
    System.out.println("Implementa o algoritmo 1")
  }
}
class A2 extends M2{
  public void m(){
    System.out.println("Implementa o algoritmo 2")
  }
}
class A3 extends M2{
  public void m(){
    System.out.println("Implementa o algoritmo 3")
  }
}
class A4 extends M1{
  public void m(){
    System.out.println("Implementa o algoritmo 4")
  }
}
// Normalmente as classes acima estariam agrupadas em um pacote

// Contexts
public class A{
  private M1 estrategia1;
  private M2 estrategia2;

  public void setEstrategia1(M1 estrategia1){
    this.estrategia1 = estrategia1;
  }
  public void setEstrategia2(M1 estrategia2){
    this.estrategia2 = estrategia2;
  }
  public A(/*Não pode ter parametro*/){
    // Explicação de não poder ter parametro:
    // Ao herdar a classe A, os filhos irão tentar chamar o contrutor padrão new Nome(), logo é necessário ter um construtor padrão
    this.setEstrategia1(new M1());
    this.setEstrategia2(new M2());
  }
  public void m1(){//aprendizado de maquina
    //Delegação de resposabilidade
    this.estrategia1.m();
  }
  public void m2(){//criptografi
    //Delegação de resposabilidade
    this.estrategia2.m();
  }
}
public class B extends A{
  public B(){
    super();// Já é uma chamada implicita devido a como o java funciona
    //Toda classe em Java herda de uma classe Object
    // Como implicitamente já é chamado, todo o metodo public B() é redundante
  }
}
public class C extends A{
  public C(){
    this.setEstrategia1(new A1());
    this.setEstrategia2(new A3());
  }
}
public class D extends A{
  public D(){
    this.setEstrategia1(new A4());
    this.setEstrategia2(new A2());
  }
  
}
public class E extends A{
  public E(){
    this.setEstrategia1(new A4());
    this.setEstrategia2(new A3());
  }
}
```

Com isso caso exista um novo algoritmo a ser implementado, por exemplo um ***A5*** que faça parte de alguma estratégia, é fácil extender o projeto, basta ele herdar das classes abstratas que agrupam as estratégias

```java
public class A5 extends M1{
  public void m(){
      System.out.println("Implementa o algoritmo 5")
    }
}
```

> Ao abstrair com esse padrão iremos gerar bastantes classes

> Dica: sempre programe para o super-tipo, e não para o

### Orientações para o Strategy

- Programe sempre para interface(abstrações)
- Dê preferência para composição ao invés de herança

> Reutilizar e intercambiar comportamentos entre diversas classes, facilitando a expansão, manutenção e reuso

## Padrão Chain of Responsibility

> Obj. Evitar o  acoplamento do remetente de uma solicitação ao receptor fornecendo uma cadeia de objetos para tratar uma solicitação

- O objeto que fez a solicitação não tem conhecimento explícito de quem a tratatá - essa solicitação é dita ter um receptor implícito
- Represent um encadeamento de objetos receptores para o processamento de uma série de solicitações diferentes
- Esses objetos receptores passam a solicitação ao longo de cadeia até que um ou cários objetos a tratem.
- Cada objeto receptor possui uma lógica descrevendo os tipos de solicitação que é capaz de processar e como passar adiante aquelas que requeiram processamento por outros receptores

### Como é montado

- É uma **lista simplesmente encadeada** de objetos que podem servir um determinado pedido
- Em ve de acoplar o cliente a um objeto especifico para a execução de um determinado método
- Lista encadeada de processamento
  
### Vantagens

[TODO]
```mermaid
graph TD;
    A-->B;
    A-->C;
    B-->D;
    C-->D;
```