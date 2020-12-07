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

get_index([],_,_):-false,!.
get_index([H|_],1,H).

get_index([_|T],I,X):-Is is I-1,get_index(T,Is,X).
/*
Params: ([],I,X)
Retorno: X será unificado com o item na posição I da lista
*/
disjuntas([],_).
disjuntas(_,[]).
disjuntas([H|T],C2) :- not(member(H,C2)), disjuntas(T,C2).
/*
Params: ([],[])
Retorno: true false se a lista é disjunta
*/

intersec([],[],[]).
intersec([],_,[]).
intersec(_,[],[]).

intersec([H|T],L2,[H|Tr]) :- member(H,L2),intersec(T,L2,Tr),!.
intersec([_|T],L2,Tr) :- intersec(T,L2,Tr),!.
/*
Params: ([],[],X)
Retorno: X será a lista com a interseção das outras duas listas
*/

difersec([],[],[]).
difersec([],_,[]).
difersec(_,[],_).

difersec([H|T],L2,[H|Tr]) :- not(member(H,L2)),difersec(T,L2,Tr),!.
difersec([_|T],L2,Tr) :- difersec(T,L2,Tr),!.
/*
Params: ([],[],X)
Retorno: X será a lista com a diferença das outras duas listas
*/

duplica([],[]).
duplica([X|Xs],[X,X|Ys]) :- duplica(Xs,Ys).
/*
Params: ([],X)
Retorno: X será a lista com a com os elementos copiados da outra lista [1,2,3]-> [1, 1, 2, 2, 3, 3]
*/

retira_duplicata([],[]).
retira_duplicata([X],[X]).
retira_duplicata([X,X|Xs],W) :- retira_duplicata([X|Xs],W).
retira_duplicata([X,Y|U],[X|W]) :- X \= Y, retira_duplicata([Y|U],W).
/*
Params: ([],X)
Retorno: X será a lista sem os elementos duplicados da outra lista [1,2,2,3]-> [1,2,3]
*/

inverte_lista(L1,L2) :- inverte_lista(L1,L2,[]).
inverte_lista([],L2,L2) :- !.
inverte_lista([X|Xs],L2,Z) :- inverte_lista(Xs,L2,[X|Z]).
/*
Params: ([],X)
Retorno: X será a lista com os elementos invertidos da outra lista [1,2,3]-> [3,2,1]
*/

retira_duplicata_sequencial([],[]).
retira_duplicata_sequencial([X],[X]).
retira_duplicata_sequencial([X,X|Xs],Zs) :- retira_duplicata_sequencial([X|Xs],Zs).
retira_duplicata_sequencial([X,Y|Ys],[X|Zs]) :- X \= Y, retira_duplicata_sequencial([Y|Ys],Zs).
/*
Params: ([],X)
Retorno: X será a lista sem os elementos duplicados da outra lista que estejam adjacentes [1,2,2,3]-> [1,2,3]
*/

supra_crescente([X],N) :- X>=N,!.
supra_crescente([H|T],N) :- H>=N, N1 is N+H,supra_crescente(T,N1).
supra_crescente([H|T]) :- supra_crescente(T,H).
/*
Params: ([])
Retorno: true ou false se a lista for supra crescente
*/