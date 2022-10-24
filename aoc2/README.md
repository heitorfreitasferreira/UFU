# ARQUITETURA E ORGANIZAÇÃO DE COMPUTADORES 2

> Importante quando a performancê é desejada. *(Sistemas de bancos de dados, jogos, bibliotecas de álgebra linear, aplicativos ciêntificos, etc.*

## Benefícios

- Fundamental para o desenvolvimento de sistemas computacionais de alto desempenho e processamento paralelo.
- Estar apto a tomar desições de compra de hardware, melhor entendimento sobre as necessidades do software alvo e as características do hardware disponível.
  - Evitar superdimensionamento de hardware
- Para aparender a utilizar técnicas de otimização de desempenho em sistemas computacionais.
- Para entender a estrutura e funcionamento de computadores.

## Deandas constantes da computação

- Melhor desempenho
- Computadores menores e mais leves
- Maior capacidade de memória e armazenamento
- Menor consumo de energia (menor dissipação de calor)

## Aperfeiçoamento em arquitetura de conjunto de instruição

- **Pipeline** para diminuir a ociosidade da CPU no ciclo de instrução.
  - Problema: um algoritmo quase nunca é linear, logo é difícil saber para onde ir nos caminhos do algoritmo
  - Solução: Branch prediction
- Emissão de várias instruições para execução, em processamento **Superescalar**.
  - Emissão das instruções em paralelo;
  - Problema: o programa é sequêncial, mas as execuções são em paralelo;
  - Gera paralelismo de instruções a nível do processador;
  - Problema do paralelismo: supondo que duas instruções são feitas, uma entre int e float, e outra entre float e float, como ambas tem tempos de execução diferentes, uma fica pronta antes da outra, logo é necessário mecânismos para verificação desses casos.
- Melhor organização dos circuitos aritméticos para se obter muitos resutlados intermediários simultâneos.

## [Hazards](https://en.wikipedia.org/wiki/Hazard_(computer_architecture)#:~:text=In%20the%20domain%20of%20central,lead%20to%20incorrect%20computation%20results.)

> Problemas com o pipeline de instruções na microarquitetura da CPU, quando a próxima instrução não possa ser executada no próximo clock.

# Capítulo 1

> Princípios quantitativos do projeto de um computador

Tcpu = #Instr * CPI * Período do clock

Pipeline: CPI se aproxime de 1

Superscalares: CPI ser menor que 1

## Tendências de projeto, eficiência energética, dependência e custo

### CPU

A capacidade de executar ciclos de instrução por segundo vem aumentando exponêncialmente em uma frequência altíssima, esse aumento vem diminuíndo após a entrada dos anos 2000.

> **Lei de Moore:** número de transistores em um único chip dobram no período de 18 a 24 meses

Garantiu a supremacia de microcomputadores com único processador, levando à queda dos, sendo substituídos por sistemas distribuídos.

#### Redução da capacidade

> Motivos

- **Superaquecimento**, necessidade de refrigeração forçada
- Saturação do **paralelismo** a nível de instrução
- Saturação da **velocidade da memória**

> Em anos recentes, o aumento da velocidade de *clock* tem caído *1%* ao ano

#### Pós redução da capacidade

Foco em construção de processadores de vários núcleos e incentivo de criação de aplicações executando em paralelo, tanto os dados quanto o processamento

### Memória primária

Aumento da capacidade e densidade de memória DRAMs, semicondutoras e flash semicondutoras

### Transistores e fios

Atrasos em fios não reduzem na mesma escala que escala nos circuitos lógicos (tamanho de chips *vs* fios deles e os que os ligam)

### Potência

Não é possível consistentemente operar em frequência altas sem alcançar os **limites de potência/térmicos**

#### Overclock

> Turbo mode na intel

CPU roda em uma taxa maior de *clock* por um curto intervalo de tempo, sneod forçado pelo usuário ou não


### Melhorar desempenho sem aumentar clock

1. Realizar **mais trabalho por** ciclo de **clock**
   - Transistores são mais rápidos e com maior eficiência energética
2. Melhorias arquiteturais
   - Explorar mais **paralelismos** em uma thread e em nível de thread
   - Melhorar **previsão de desvios**
   - Melhorar política de **cache**
   - Melhorar **organização da memória**

### Formas de melhorar o desempenho

- Multi-núcleos
- Melhores modelos de programação e eficiência em multi-thread
  - Esforço de cada programador
- Melhor hirarquia de memória
- Melhor eficiência energética
  - M**ulti-núcleos** com caracteristicas de processamento diferentes,** alguns com maior capacidade** para tarefas mais demandantes, e **outros com menor capacidade** para momentos que não necessitem de uma alta taxa de trabalho da CPU
  - **Reduzir movimentação de dados** (dados no computador é energia)
- SoC (System on a Chip) e ARM
  - Memória, processador e outros componentes juntos no mesmo chip físico
  - Proposta de ser a unificação dos diferentes tipos de chips (pcs, mobile, mainframes...)
  - Destaque para os Chips M1 e M2 da Apple

## Equação de desempenho e Benchmarks Suites

> Como definir, medir e resumir desempenho

Observaões importantes sobre projeto

- Tirar proveito do paralelismo
- Explorar o princíoio da localidade
- Foco no caso comum (Lei de Amdahl)
  - Melhorar o que é muito usado primeiro

### O que é desempenho, como medir métricas básicas

> A frequência do trabalho não impacta tanto quanto como o trabalho é feito

#### Perguntas motivacionais

- Por que alguns hardwares tem melhor desempenho para programas diferentes
  - Algumas aplicações usam diferentes partes do hardware mais que outras
- Quais fatores de desempenho do sistemas estão relacionados com hardware
  - Alguns casos o problema pode ser derivado do software e da sua implementação
- Como o conjunto de instruções da máquina afeta o desempenho?

### Tempo de resposta 

> Latência

- Quando tempo leva para executar meu programa
- QUanto tempo leva pra executar um programa qualquer
- Quanto tempo eu devo esperar para um consulta ao banco de dados

#### Tempo consumido

> Elapsed TIme

- Contabiliza vários aspectos
  - Tempo de memória
  - Outros processos na máquina
  - I/O
- Útil, mas não é bom para comparação

#### Tempo de CPU *(CPU Time)*

- Não contabiliza I/O ou tempo de outros programas
- Pode ser quebrado em tempo de sistema e tempo de usuário
  - Pode ser medido usando UNIX **time**command


### Vazão

> Throughput

- Quantos processos (threads) a máquina pode executar por vez
- Qual a taxa média de execução
- Quanto trabalho foi feito

### Ciclo de clock

- Considerar unidade de ciclos ao invés de segundos omo referência de desempenho
  - $(segundos/programa) = (ciclos/programa) * (segundos/ciclos)$
- Eventos de click indicam quando começam as atividades
- tempo de ciclo = tempo entre os eventos de clock
- Taxa de clock = ciclos/segundo
- Um clock de $500MHz$ tem um tempo de ciclo de $2ns$

> Métricas básicas

- Cycle time (segundos por ciclo)
- Clock rate (ciclos por segundo)
- CPI (ciclos por intrução)
- MIPS (Milhões de instruções por segundo)
  - Não confiavel pois cada instrução demora uma quantidade de tempo variável
- Flops (instruções de ponto flutuante por segundo)

tempo_cpu = #ciclosClock(prog) * tempoCiclo(clock)

tempo_cpu = (#ciclos_clock/frequência)

tempo_cpu = #intruçõesPorClock * ciclosPorIntruções * cicloDeClock

> Para melhorar o tempo de CPU

- Aumentar a frequência do clock = diminuir o período de clock
  - Tecnologia de organização do Hardware
  - Para obter uma melhora na performance apenas melhorando essa métrica, ela deve ser aumentada significantemente, que leva a um custo muito alto
- Reduzir o número de **ciclos por instrução**
  - Melhorar organização e arquitetura do conjunto de intruções (ISA)
- Reduzir a quantidade de intruções
  - ISA e tecnologias do compilador (implementação)

> é Dificil mudar um parâmetro de modo completamenteo isolado, as **tecnologias envolvidas** na mudanção de caracteristicas são **interdependentes**

## Arquitetura do Conjunto de instruções (***ISA***)

### O que é a ISA

> Especifica funcionalidade do processador

> Tranforma o código de montagem em movimentações da microarquitetura

- Operações suportadas
- Elementos armazenadores e como os acessar
- Como programador/compilador interage com o processador

### O que determina um bom projeto ISA

- Implementabilidade
  - Suportar várias implementações
    - Custo
    - Desempenho
    - Implementações de alto desempenho
- Programabilidade
  - Facilidade de expressar soluções algoritmicas
- Backward/Foward Compatibility

### Arquitetura de conjunto de intruções

> Parte visível ao programador

- Formatos de instruções
- Opcodes (instruções disponíveis)
- Número e tipos de 

#### Objetivos principais

- Ser implementada por hardwares
  - Simples
  - Rápidos


### Decisões de projeto de um ISA

- Tamanho da intrução
- Quantos registradores
- Formato de intrução
- Operandos
- Operações
  - Última coisa a ser escolhida

#### Exemplos de ISAs

- **VAX** da Digital (elegante)
- **Intel x86** (feia, bem sucedida)
- **MIPS** foco de texto, usado em diversas máquinas
- **PowerPC** (Mac's e supercomputadores IBM)

> CISC's (Computadores de Conjunto de Instruções **Complexas**)

- VAX
- x86


> RISC's (Computadores com Conjunto de Instruções **Reduzido**)

- MIPS
- PowerPC
- DEC Alpha (sucessor do VAX)

#### Tamanho da Instrução

- Variável
  - x86 (1 a 17 bytes)
  - VAX (1 a 54 bytes)
- Fixo
  - MIPS
  - PowerPC
  - Maioria dos RISCs
  - 4 bytes

Tamanho fixo é mais fácil de trocar de posição da instrução

#### Quantidade de registradores

> Poucos registradores: vantagem

-  Menos bits pra especificar qual
- Menor hardware
- Acesso mais rápido (fios menores e menos gates)
- Troca de contexto mais rápida

> Vantagem de um número maior

- Menos **loads** e **stores** 
- Mais fácil realizar várias operações ao mesmo tempo

#### Formado te instruções

> O que significa cada bit

- Muitos formatos
  - Complica a decodificação
  - Bits de instruição pra especificar o formato
- Máquina precisa determinar se:
  - "É uma instrução de 6 bytes"
  - "Bits 7-11 especificam um registrador

#### Quantidade de operandos

- Dois endereços de código: destino pode ser o mesmo que o operando
  - $x = x + y$
- Três o destino pode ser outro
  - $x = y + z$




## **Projeto *RISC***, implementação da ISA

# Capítulo 2

> Projeto da hierarquia da memória

## Organização Hierárquica da memória

> Endereçada a byte

Estudo de caso no MIPS

### Registradores e memória

- Operações feitas entre registradores
- Caso falte registradores realizar *spill*


### Formato das intruções tipo R

> Instruções e lógicas

- op-code (6 bits)
  - Código da operação
- rs (5 bits)
  - Registrador de origem
- rt (5 bits)
  - Registrador de origem
- rd (5 bits)
  - Registrador de destino
- shamt (5 bits)
  - Tamanho do desvio
- funct (6 bits)

### Formato das instruções tipo I

> Aritméticas e lógicas com operando imediato, loads e stores, desvios 

- op-code (6 bits)
  - Código da operação
- rs (5 bits)
  - Registrador de origem
- rt (5 bits)
  - Registrador de origem
  - Pode ser o destino
- Operador de deslocamento (16 bits)


### Formato das intruções tipo J

> Chamada de sub-rotina, desvio com endereçamento absoluto

- op-code (6 bits)
  - Código da operação
- Endereço (26 bits)

### Estágios da instrução

1. Busca de instrução
   - Controlador de programa (PC) para armazenar o endereço da instrução
   - Um somador para calcular o endereço da próxima instrução
   - Memória onde estão armazenadas as instruções
2. 

### Máquina de cicli único

- Todas operações devem ser feitas em um único ciclo
- Duração do ciclo calculada pelo pior ciclo
- Leitura da instrução e acesso à memória no mesmo ciclos duas memórias
- Cálculos de endereço e operações aritméticas no mesmo ciclo: três unidades funcionais (ALU, somadores)

> Todas intruções completam em um ciclo de relógio

Algumas instruções usam mais HW que outras, logo gastam menos que um clock para serem executadas, o load é uma que demora mais dentre as mesmas

Exemplo numérico

- 2ns para acesso s memórias
- 1ns para leitura e escrita no banco de registradores
- 2ns para a ALU
- Período de relógio no monoclico = 8ns

Imagine um programa com 24% loads, 12% stores, 44% R-format, 20% branches, todas executariam em 8ns

Se tivéssemos um rológio variável, cada instrução demoraria apenas o tempo necessário, levando a uma melhora de trazer o clock de 8ns para 6ns em média

> Surgimento de máquina ***multi-ciclo***

### Máquina multicliclo

- Vários ciclos por instrução
- Cada instrução pode ser executada num número diferente de ciclos
- **Unidades funcionais podem ser reutilizadas em ciclos distintos**
- Pequeno acréscimo de multiplexadores e registradores

### Passos das instruções

1. Busca
   1. Busca da instrução, incremento do PC
2. Decodificação
   1. Decodificação da instruição
   2. Leitura dos registradores - mesmo que não utilizados
   3. Cálculo do endereço do branch - mesmo que a instrução não seja branch
3. Execução
   1. Tipo R -- Execução da operação
   2. Load Store - Cálculo do endereço efetivo do operando
   3. Branch - Determinar se branch deve ser executado, Atualiza o PC (acaba)
   4. Jump - Atualiza o PC (acaba)
4. Memória
   1. Tipo R - Grava resultado no registrador (acaba)
   2. Store - Grava dado na memória (acaba)
   3. Load - Busca dado na memória
5. Write-Back
   1. Load - Grava resultado no registrador (acaba)


## Otimizações básicas para o **Cache**

# Capítulo 3

> Paralelismo em nível de instrução, mecanismos para melhorar o **CPI**

## Arquitetura pipelining e superscalares

## Técnicas para explorar o paralelismo

## Arquitetura VLIW(Very Large Instruction Word): Emissão múltipla

> Compilador entrega ao processador um pacote de instruções paralelizaveis

# Capítulo 4

> Paralelismo em nível de dados, entender como a GPU funciona
 =
## Arquiteturas vetoriais

## Extensões SIMD

## GPUs, Graphical Processing Units

# Capítulo 5

> Paralelismo em nível de threads

## Multiprocessadores e Paralelismo em nível de threads

# Capítulo 6

> Paralelsimo em nível de requsições

## Design of warehouse-scale machines
