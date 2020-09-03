deCarro(auckland,hamilton).
deCarro(hamilton,raglan).
deCarro(valmont,saarbruecken).
deCarro(valmont,metz).

deTrem(metz,frankfurt).
deTrem(saarbruecken,frankfurt).
deTrem(metz,paris).
deTrem(saarbruecken,paris).

deAviao(frankfurt,bangkok).
deAviao(frankfurt,singapore).
deAviao(paris,losAngeles).
deAviao(bangkok,auckland).
deAviao(losAngeles,auckland).

viagem(X,Y):-deAviao(X,Y);deTrem(X,Y);deCarro(X,Y).
viagem(X,Y):-
  (deAviao(X,Z);deTrem(X,Z);deCarro(X,Z))
  ,
  (viagem(Z,Y)).