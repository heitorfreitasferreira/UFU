trad(eins,um).
trad(zwei,dois).
trad(drei,tres).
trad(vier,quatro).
trad(fuenf,cinco).
trad(sechs,seis).
trad(sieben,sete).
trad(acht,oito).
trad(neun,nove).

tradLista([],[]).

tradLista([A|As],[P|Ps]):- 
  trad(A,P),
  tradLista(As,Ps).
