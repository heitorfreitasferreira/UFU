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
  % ?- fazpl(X).
  % X = maria ;
  % X = rui ;
  % X = manuel ;
  % X = pedro.