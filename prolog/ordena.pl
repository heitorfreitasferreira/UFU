w([_]) :- !.

w([X,Y]) :- X=<Y,!.

w( [X,Y|T]):- X=<Y, w([Y|T]),!.

/* Ve se a lista é ordenada */
