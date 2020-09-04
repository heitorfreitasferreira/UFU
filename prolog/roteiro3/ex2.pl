intercala([],[],[]).
intercala([X|Xs],[Y|Ys],Z):-intercala(Xs,Ys,[X,Y|Z]).