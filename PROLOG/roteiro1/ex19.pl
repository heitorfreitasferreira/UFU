aluno(joao,poo).
aluno(pedro,poo).
aluno(maria,pl).
aluno(rui,pl).
aluno(manuel,pl).
aluno(pedro,pl).
aluno(rui,ed1).
estuda(joao).
estuda(maria).
estuda(manuel).
faz(A,D):-estuda(A),aluno(A,D).
  % ?- aluno(X,pl), estuda(X).
  % X = maria ;
  % X = manuel ;
  % false.
  % PERMITE SABER OS ALUNOS QUE FAZEM A MATÉRIA PL E ESTUDAM AO MESMO TEMPO