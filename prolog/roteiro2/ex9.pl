duasVezes([],[]).
duasVezes([X|Xs],[X,X|Y]):-
  duasVezes(Xs,Y).