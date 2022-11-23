# Cap 1

> Assuntos importantes

- Execução de instrução
- Formas de executar entrada e saída
- Interrupção
- DMA
  - Programada
  - Controlada por interrupção
  - Acesso direto à memória

> Exercícios para revisar

- [ ] Exercício 1
  - Passos de execução com instruções mais simples (busca e executa *sem interrupção*)
  - slides 1 pg 16

# Cap 2

> Assuntos importantes

- Visão geral de um SO
  - Interface humano máquina
- Sistema serial
  - Rudmentar
- Sistema em lote
  - Se carrega cada processo na memória principal e executa um por vez
- Sistema Multiprogramado
  - Vários códigos na memória principal	
  - Não cunfundir com multiprocessado (vários núcleos)
  - Acomodar vários processos na memória principal dividindo o tempo de CPU entre eles
  - Executar o maior número de tarefas no menor tempo possível
  - Não há interação com usuário
  - Dados entram e saem da memória principal
- Sistema de tempo compartilhado
  - Melhoria no desempenho
  - Cada vez que o usuário fornece o dado, o sistema o processa
  - Enquanto o usuário está gerando os dados, o sistema espera
  - **Minimiza o tempo de resposta**
- Memória
  - Página
  - Frame (mesmo tamanho da página)
  - Várias páginas geram um bloco
  - Unidade de gerenciamento de memória
- Diferentes níveis de escalonamento
  - *Long* term queue
  - *Short* term queue
    - Estão na memória principal
    - São passíveis de se executarem diretamente
- Threads/Unidades escalonáveis

# Cap 3

- Estados de um processo
  - Modelo de 7 estados e suas transições
- Mode de execução de um processo
  - Kernel mode
  - User mode
- Serviços do SO

# Cap 4

- Threads
- Estados pelos quais uma thread passa
  - Como isso se relaciona com o estado do processo
  - Arranjos 1:1, M:1, 1:M, N:M
    - Cap 4 pag 38


# Prova 2

Capitulo 5, 6, 7, 8

Comunicação e sincronização

Deadlock starvation