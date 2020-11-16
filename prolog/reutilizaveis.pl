ordenado([_]) :- !.
ordenado([X,Y]) :- X=<Y,!.
ordenado( [X,Y|T]):- X=<Y, ordenado([Y|T]),!.
/* 
Ve se a lista é ordenada 
Params: ([])
Retorno: true ou false
*/

separa([U],P,[U]) :- U =< P,!.
separa([_],_,[]) :- !.

separa([H|T],P,[H|Tr]) :- H =< P, separa(T,P,Tr),!.
separa([_|T],P,Tr) :- separa(T,P,Tr),!.
/*
separa(L1,P,L2)  L2 terá os elementos de L1 menores ou iguais a P
Params: (L1,P,L2), sendo L1 e L2 listas
Retorno: L2
*/

soma_pares_ordenados([],0).
soma_pares_ordenados([[A,B]],B) :- A mod 2 =:= 0,!.
soma_pares_ordenados([[_,_]],0) :- !.

soma_pares_ordenados( [ [A,B]|T],X) :- A mod 2 =:= 0, soma_pares_ordenados(T,Xr), X is Xr+B,!.
soma_pares_ordenados( [ [_,_]|T],X) :- soma_pares_ordenados(T,X).
/*
Para N listas do tipo [A,B], caso A seja par, somará em todos os B em X
Params: ([[],[],...],X)
Retorno: X
*/

contem([],_) :- !,fail.
contem([X],X) :- !.
contem([X|_],X) :- !.
contem([_|T],X) :- contem(T,X).
/*
Verifica se existe um elemento X em uma lista
Params: ([],X)
Retorno: true ou false
*/

duplicado_seguido([X,X]) :- !.
duplicado_seguido([H,H|_]) :- !.
duplicado_seguido([_|T]) :- duplicado_seguido(T).
/*
Verifica se existe dois elementos seguidos que são iguais
Params: ([])
Retorno: true ou false
*/

maior_elem([X],X) :- !.

maior_elem([H|T],H) :- maior_elem(T,X), H>X,!.
maior_elem([_|T],X) :- maior_elem(T,X).
/*
Params: ([],X)
Retorno: X será o maior elemento da lista
*/

tam_par([_],0) :- !.
tam_par([_,_],1) :- !.
tam_par([_|T],0) :- tam_par(T,1),!.
tam_par([_|T],1) :- tam_par(T,0).
/*
Params: ([],X)
Retorno: X is 1 se o tamanho da lista for par, senão X is 0
*/

