retira_duplicata(List,X):-sort(List,SortedList), retira_duplicataM(SortedList,X).


retira_duplicataM([],[]).
retira_duplicataM([X],[X]).
retira_duplicataM([X,X|Xs],W) :- retira_duplicataM([X|Xs],W).
retira_duplicataM([X,Y|U],[X|W]) :- X \= Y, retira_duplicataM([Y|U],W).

sudoku([X11,X12,X13,X14,X15],
       [X21,X22,X23,X24,X25],
       [X31,X32,X33,X34,X35],
       [X41,X42,X43,X44,X45],
       [X51,X52,X53,X54,X55]):-
    sort([X11,X12,X13,X14,X15],Auxlinha1),
    length([X11,X12,X13,X14,X15],Tamlinha1),
    length(Auxlinha1,TamAuxlinha1),
    Tamlinha1 =:= TamAuxlinha1,
    
    sort([X21,X22,X23,X24,X25],Auxlinha2),
    length([X21,X22,X23,X24,X25],Tamlinha2),
    length(Auxlinha2,TamAuxlinha2),
    Tamlinha2 =:= TamAuxlinha2,
    
    sort([X31,X32,X33,X34,X35],Auxlinha3),
    length([X31,X32,X33,X34,X35],Tamlinha3),
    length(Auxlinha3,TamAuxlinha3),
    Tamlinha3 =:= TamAuxlinha3,
    
    sort([X41,X42,X43,X44,X45],Auxlinha4),
    length([X41,X42,X43,X44,X45],Tamlinha4),
    length(Auxlinha4,TamAuxlinha4),
    Tamlinha4 =:= TamAuxlinha4,
    
    sort([X51,X52,X53,X54,X55],Auxlinha5),
    length([X51,X52,X53,X54,X55],Tamlinha5),
    length(Auxlinha5,TamAuxlinha5),
    Tamlinha5 =:= TamAuxlinha5,
    
    
    
    sort([X11,X21,X31,X41,X51],Auxcoluna1),
    length([X11,X21,X31,X41,X51],Tamcoluna1),
    length(Auxcoluna1,TamAuxcoluna1),
    Tamcoluna1 =:= TamAuxcoluna1,
    
    sort([X12,X22,X32,X42,X52],Auxcoluna2),
    length([X12,X22,X32,X42,X52],Tamcoluna2),
    length(Auxcoluna2,TamAuxcoluna2),
    Tamcoluna2 =:= TamAuxcoluna2,
    
    sort([X13,X23,X33,X43,X53],Auxcoluna3),
    length([X13,X23,X33,X43,X53],Tamcoluna3),
    length(Auxcoluna3,TamAuxcoluna3),
    Tamcoluna3 =:= TamAuxcoluna3,
    
    sort([X14,X23,X34,X44,X54],Auxcoluna4),
    length([X14,X23,X34,X44,X54],Tamcoluna4),
    length(Auxcoluna4,TamAuxcoluna4),
    Tamcoluna4 =:= TamAuxcoluna4,
    
    sort([X15,X25,X35,X45,X55],Auxcoluna5),
    length([X15,X25,X35,X45,X55],Tamcoluna5),
    length(Auxcoluna5,TamAuxcoluna5),
    Tamcoluna5 =:= TamAuxcoluna5,
    
    
    
    sort([X11,X21,X22,X23,X32],AuxGrupo1),
    length([X11,X21,X22,X23,X32],TamGrupo1),
    length(AuxGrupo1,TamAuxGrupo1),
    TamGrupo1 =:= TamAuxGrupo1,
    
    sort([X24,X12,X13,X14,X15],AuxGrupo2),
    length([X24,X12,X13,X14,X15],TamGrupo2),
    length(AuxGrupo2,TamAuxGrupo2),
    TamGrupo2 =:= TamAuxGrupo2,
    
    sort([X31,X41,X51,X52,X53],AuxGrupo3),
    length([X31,X41,X51,X52,X53],TamGrupo3),
    length(AuxGrupo3,TamAuxGrupo3),
    TamGrupo3 =:= TamAuxGrupo3,
    
    sort([X33,X34,X42,X43,X44],AuxGrupo4),
    length([X33,X34,X42,X43,X44],TamGrupo4),
    length(AuxGrupo4,TamAuxGrupo4),
    TamGrupo4 =:= TamAuxGrupo4,
    
    sort([X25,X35,X45,X54,X55],AuxGrupo5),
    length([X25,X35,X45,X54,X55],TamGrupo5),
    length(AuxGrupo5,TamAuxGrupo5),
    TamGrupo5 =:= TamAuxGrupo5.