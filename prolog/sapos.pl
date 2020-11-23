#1961 URI
pulo_qnt(P,N,Lista):-P>=1,P=<5,N>=2,N=<10,pula_prox(Lista,0,P).
pula_prox([],_,_):-!.
pula_prox([Prox_pulo|Resto],Atual,Forca):-Forca>=(Prox_pulo-Atual),pula_prox(Resto,Prox_pulo,Forca).
