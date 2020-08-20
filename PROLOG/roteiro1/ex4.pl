pai(joao,carlos).
pai(carlos,ana).
pai(carlos,juliana).
mae(joana,ana).
mae(joana,juliana).
mae(maria,joana).
mulher(juliana).
mulher(ana).
mulher(joana).
mulher(maria).
homem(joao).
homem(carlos).

%ex2
% pai(X,ana).
% pai(X,Y).
%ex3
%ex4
filho(X,Y):-pai(Y,X),homem(X).
filha(X,Y):-pai(Y,X),mulher(X).
irmao(X,Y):-pai(Z,X),pai(Z,Y),homem(X),homem(Y).
irma(X,Y):-pai(Z,X),pai(Z,Y),mulher(X),mulher(Y).
irmaos(X,Y):-pai(Z,X),pai(Z,Y).
tio(X,Y):-irmao(X,Z),pai(Z,Y).
tia(X,Y):-irma(X,Z),mae(Z,Y).
primo(X,Y):-homem(X),(pai(Z,X),tio(Z,Y));(mae(Z,X),tia(Z,Y)).
prima(X,Y):-mulher(X),(pai(Z,X),tio(Z,Y));(mae(Z,X),tia(Z,Y)).
avom(X,Y):-mulher(X),mae(X,Z),(mae(Z,Y);pai(Z,Y)).
avoh(X,Y):-homem(X),pai(X,Z),(mae(Z,Y);pai(Z,Y)).