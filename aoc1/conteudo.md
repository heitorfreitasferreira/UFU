# O que é AOC

> Arte de interconectar componentes de hardware

## O que aprenderemos

> Software de qualidade é o que extrai 100% da máquina

Conceitos básicos de AOC em busca de uma visão clara de como um computador funciona

## Visão abrangente

* Resolver problemas
* Como o computador resolve problemas?
  * Ideia de uso geral (pervasiva):
* Abstração e hierarquia
  * Abstração: forma de lidar com sistemas complexos
  * Hierarquia: divide problemas em partes, cada parte define sua **Interface** e sua **Implementação**
* Black box model
  * Somente especialistas lidam com implementação e o resto de nós com a interface
* Motivação
  * Apresentar desafios e soluções para obter arquiteturas eficientes e confiáveis
  * __Desempenho__
    * Velocidade do processador
    * Velocidade e capacidade de memória
    * Velocidade do sistema de interconexão
  * Desafio é criar um sistema balanceado que considere todos esses aspectos

# Capitulo 1

## Objetivo

* Estudo de um sistema de computação passa em dois pontos
  * Arquitetura
    * Atributos visíveis (pode usar quando estar codificando)
  * Organização
    * Unidades operacionais e a interconexão, relacionado a otimização
  
>Ao conhecer os dois, se pode tirar 100% da máquina ao programar para ela
  
## Estrutura e função de um computador

* Estrutura
  * Forma em que os componentes estão interconectados
* Função
  * A operação de cada compontente individualmente
* Cada componente pode ser decomposto em subcomponete

>O computador é uma coleção de elementos, e os elementos são conectados entre sí

## Arquitetura x Organização

### Arquietura

* Tem impacto direto na lógica do programa
  * ISA -> Interface entre hardware e software
* Uma vez que eu tenha uma arquitetura padrão, um código feito para essa arquitetura pode ser usado amplamente
  * Ex.: Tanto Intel quanto AMD usam a arquitetura x86, o LOL roda em qualquer um dos processadores
* Número de bits (16/32/64)
  * Quanto maior o número de bits do processador, maior a capacidade de representar valores
* Operações de entrada e saída
  * Com interrupção
  * Com acesso direto a memória
  * etc...
* Técnicas de endereçamento de memória

### Organização

>Como uma adição é realizada a nível de hardware

* Unidades operacionais e suas interconexões que realizam as especificações arquiteturais
* Detalhes do hardware transparente
  * Programador normalmente não sabe como as operações são realizadas
* Programador utiliza um comando, o compilador traduz esse comando para os comandos a nível arquiteturais

>Até anos 90 não existia float, era necessário emular o float usando inteiro

### Exemplo

É questão **arquitetural** se o computador terá uma instrição de multiplicação, mas é **organizacional** se a instrução deve ser implementada com várias somas ou uma unidade dedicada a multiplicação

## Estrutura e Função

* Em cada nível o projetista se preocupa com a estrutura e a função
  * Estrutura
    * Maneira em que os compontentes são inter-relacionados
  * Função
    * A operação de cada componente individualmente, como parte da estrutura

## Principais funções do computador

Função|Nome
------|----
Processamento de dados|data processing
Armazenamento de dados|data storage
Movimento de dados|data movement - I/O
Controle|control

## Principais componentes **estruturais**

* CPU
  * Controla a operação do computador e realização do processamento de dados
* Memória
  * Armazena dados e instruções
* I/O
  * Movimento de dados entre o computador e o ambiente externo
* Sistema de Interconexão
  * Prove o caminho **físico** para cominicação entre os componentes estruturais

## Esquemas de operações

INSERIR OS PRINTS DE ALGUMA FORMA AQUI

## Componentes da CPU

>É um mini computador

* Internal CPU Interconnection
  * Liga tudo
* Arithmetic and Login Unit
  * Onde a operação é realmente feita
  * Faz operações lógicas e aritiméticas
  * Ex.: Adição
* Registers
  * Dependendo da máquina se tem N quantidade de registradores, quanto mais antiga menos registradores
* Control Unit
  * Sequencing Logic
  * Control Unit Registers and Decoder
    * Executa os micro comando um a um
    * Ex.: Adição
      * É decodificado que a operação a ser feita é adição
      * Como é adição é necessário 2 operandos
      * Pega quais registradores e seus conteúdos e leva até a unidade aritmética
      * Com os 2 registradores e a informação de o que é pra fazer a unidade de controle faz a operação e devolve para os registradores

# IAS

>**Dps anota aqui seu tonto**  
>Busca->Decodifica->Processa->Busca

# Evolução dos processadores

## Gerações

1. Válvulas
2. Transistores
   * Linguagens de alto nível
   * Aritimética de float
3. Circuito integrado
   * Semicondutor
   * Microprogramming
   * Multiprogramming
4. Presente
   * PCs
   * Integração
   * Single board computer
5. Ultra large Scale Integration
   * IA
   * Network
   * Processamento paralelo

## Moore's Law

* Goordon Moore - fundador da intel
* Aumento da densidade de componentes em um chip
* Número de transistores dobra a cada 18 meses
* Custo permanece o mesmo
* Maior densidade é igual a mais integrações com menor caminho físico entre elas
* Está chegando no seu limite físico
  * Componentes já estão no limite do que é possível

## Gargalo de Von Neuman

>Para cada instrução de 40 bits o processador acessa a memória 6x

* Com a lei de Moore o processador se tornou muito rápido
* Porém *a memória **não***
* Logo o processador tem que ficar esperando a memória responder para poder fazer seu processo
* A distância da velocidade do processador e da memória RAM só aumenta
* Para evitar esse gargalo foi criada a memória em cachem, ou *Dynamic RAM*
  * Cara
  * Extremamente rápida
  * Associativa (outra forma de acesso)
  * Não tem grande capacidade de armazenamento
