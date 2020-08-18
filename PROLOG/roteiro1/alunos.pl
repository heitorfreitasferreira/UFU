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
fazpl(A):-aluno(A,pl).
% ex.12
  % aluno(joao,poo).
  % aluno(pedro,poo).
  % aluno(maria,pl).
  % aluno(rui,pl).
  % aluno(manuel,pl).
  % aluno(pedro,pl).
  % aluno(rui,ed1).
% ex.13
  % ?- aluno(joao,pl).
  % false.

% ex.14
  % ?- aluno(rui,poo).
  % false.

% ex.15
  % ?- aluno(ana,ed1),aluno(joao,ed1).
  % false.

% ex.16
  % ?- aluno(X,pl).
  % X = maria ;
  % X = rui ;
  % X = manuel ;
  % X = pedro.

% ex.17
  % ?- aluno(rui,X).
  % X = pl ;
  % X = ed1.

% ex.18
  % ?- faz(maria,pl).
  % true.

% ex.19
  % ?- aluno(X,pl), estuda(X).
  % X = maria ;
  % X = manuel ;
  % false.
  % PERMITE SABER OS ALUNOS QUE FAZEM A MATÉRIA PL E ESTUDAM AO MESMO TEMPO

% ex.20
  % ?- fazpl(X).
  % X = maria ;
  % X = rui ;
  % X = manuel ;
  % X = pedro.