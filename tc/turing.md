# Soluções para Máquinas de Turing

## Ex1: $L = {a^n b^m | n < m}$

Para aceitar a linguagem $L = {a^n b^m | n < m}$, precisamos de uma máquina de Turing que verifique se o número de `b`s é maior que o número de `a`s. A estratégia envolve marcar um `a` e um `b` por vez, assegurando que existam mais `b`s que `a`s.

1. **Estado inicial:** Mover da esquerda para a direita, buscando pelo primeiro `a` não marcado.
2. **Marcação:** Ao encontrar um `a`, marcar (ex., mudando `a` para `x`) e mover para a direita.
3. **Procurar `b`:** Continuar movendo para a direita até encontrar um `b` não marcado.
4. **Marcação `b`:** Ao encontrar um `b`, marcar (ex., mudando `b` para `y`) e retornar à esquerda para buscar o próximo `a` não marcado.
5. **Repetição:** Repetir os passos até não encontrar mais `a`s não marcados antes de um `b` não marcado.
6. **Verificação:** Se restarem `b`s não marcados após todos os `a`s terem sido marcados, a cadeia é aceita. Se não, é rejeitada.

## Ex2: $L = {a^n b^n c^n}$

Para aceitar $L = {a^n b^n c^n}$, precisamos verificar se o número de `a`s, `b`s e `c`s é o mesmo. Isso requer múltiplas passagens para marcar grupos de símbolos.

1. **Estado inicial:** Mover da esquerda para a direita, marcando um `a`, um `b` e um `c` por vez.
2. **Marcação:** Marcar o primeiro `a` não marcado (ex., mudando `a` para `x`), mover para a direita até encontrar um `b` correspondente e marcar, continuar até marcar um `c`.
3. **Verificação e Repetição:** Retornar ao início da cadeia e repetir o processo até que não seja possível marcar um grupo completo de `a`, `b`, e `c`.
4. **Aceitação:** Se todas as letras forem marcadas equilibradamente, a cadeia é aceita. Se não, é rejeitada.

## Ex3: $L = {ww^R}$ com $Σ = {a, b}$

Para aceitar $L = {ww^R}$, onde $w^R$ é a string `w` invertida, precisamos verificar se a primeira metade da cadeia é o reverso da segunda metade.

1. **Estado inicial:** Mover para a direita, marcando o primeiro e o último símbolo da cadeia.
2. **Marcação:** Marcar o primeiro símbolo (ex., mudando `a` para `x` e `b` para `y`) e o correspondente no final da cadeia.
3. **Verificação e Repetição:** Continuar marcando símbolos opostos, movendo-se para dentro da cadeia a cada passo.
4. **Aceitação:** Se todos os símbolos forem corretamente marcados sem desigualdades, a cadeia é aceita. Caso contrário, é rejeitada.

Estas soluções fornecem uma base conceitual para o desenvolvimento de máquinas de Turing completas para cada linguagem.
