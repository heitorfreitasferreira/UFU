///@description Avançar o estado do reticulado
#region Funções
function regra90(esquerda,meio,direita){
	if(esquerda and meio and direita) return false
	if(esquerda and meio and not direita) return true
	if(esquerda and not meio and direita) return false
	if(esquerda and not meio and not direita) return true
	if(not esquerda and meio and direita) return true
	if(not esquerda and meio and not direita) return false
	if(not esquerda and not meio and direita) return true
	if(not esquerda and not meio and not direita) return false
}
function regra110(esquerda,meio,direita){
	if(esquerda and meio and direita) return false
	if(esquerda and meio and not direita) return true
	if(esquerda and not meio and direita) return true
	if(esquerda and not meio and not direita) return false
	if(not esquerda and meio and direita) return true
	if(not esquerda and meio and not direita) return true
	if(not esquerda and not meio and direita) return true
	if(not esquerda and not meio and not direita) return false
}
function life(n,s,o,l,ne,no,se,so,centro){
	var total = n+s+o+l+ne+no+se+so
	if(centro and (total==2 or total == 3)) return true
	if (not centro and total ==3) return true
	return false
}

function chopard(n,s,o,l,ne,no,se,so,centro){
	var p = random_range(0,1)
	var f = random_range(0,1)
	var total = (n==arvore_queimando)+(s==arvore_queimando)+(o==arvore_queimando)+(l==arvore_queimando)+(ne==arvore_queimando)+(no==arvore_queimando)+(se==arvore_queimando)+(so==arvore_queimando)
	if(centro == arvore_queimando) return solo_exposto
	if(centro == arvore_viva and total>0) return arvore_queimando
	if(centro == solo_exposto and p<=0.01) return arvore_viva
	if(centro == arvore_viva and f<=0.0005) return arvore_queimando
	return centro
}
function chopard2(n,s,o,l,ne,no,se,so,centro){
	var p = random_range(0,1)
	var f = random_range(0,1)
	var g = random_range(0,1)
	var total = (n==arvore_queimando)+(s==arvore_queimando)+(o==arvore_queimando)+(l==arvore_queimando)+(ne==arvore_queimando)+(no==arvore_queimando)+(se==arvore_queimando)+(so==arvore_queimando)
	if(centro == arvore_queimando) return solo_exposto
	if(centro == arvore_viva and (total>0)*(1-g) > 0.7) return arvore_queimando
	if(centro == solo_exposto and p<=0.01) return arvore_viva
	if(centro == arvore_viva and f<=0.0005) return arvore_queimando
	return centro
}
/*
i) uma c ´ elula de estado ´
agua ou estrada n ´ ao˜ e alterada (inicialmente o modelo n ´ ao est ˜ a tratando mudanc¸a de ´
volume de corpos d’agua e construc¸ ´ ao de novas estradas/vias);
ii) uma c ˜ elula de estado ´
casa ou arvore, com vizinha de estado fogo, transforma-se em c ´ elula de estado fogo; 
iii) ´uma celula de estado solo, transforma-se em ´ arvore, se na sua vizinhanc¸a houver mais ´
celulas de estado ´ arvore, ou transforma-se em casa, se na sua vizinhanc¸a houver mais ´
celulas de estado casa; 
iv) uma c ´ elula de estado fogo permanece fogo, por um espac¸o ´
de tempo t, depois transforma-se em solo; v) nas celulas cujos estados ´ arvore e solo h ´ a´
uma probabilidade purb deles tornarem-se casa; vi) nos estados casa e arvore h ´ a uma
*/
//Remover Borda
//Implementar o de muitos Estados
//Implementar o do Vento em cima do Chopard padrão
//Implementar o de muitos Estados com o Vento

#endregion
#region Calcular novos estados
var novosEstados = []
for(var i = 0; i<VERTICAL;i++){
	var linhas = []
	for(var j = 0;j<HORIZONTAL; j++){
		array_push(linhas,false)
	}
	array_push(novosEstados,linhas)
	array_delete(linhas,0,array_length(linhas))
}
for(var i = 0;i< VERTICAL; i++){
	
	for(var j = 0;j< HORIZONTAL; j++){
		#region Incremento circular e criação de var cima/baixo/esquerda/direita
		if(i == 0) var cima = VERTICAL -1
		else var cima = i-1
		if(i == VERTICAL-1) var baixo = 0
		else var baixo = i +1
		if(j==0) var esquerda = HORIZONTAL-1
		else var esquerda = j-1
		if(j == HORIZONTAL-1) var direita = 0
		else var direita = j +1
		#endregion
		novosEstados[i][j] = chopard2(	celulas[cima][j].estado,
									celulas[baixo][j].estado,
									celulas[i][esquerda].estado,
									celulas[i][direita].estado,
									celulas[cima][direita].estado,
									celulas[cima][esquerda].estado,
									celulas[baixo][direita].estado,
									celulas[baixo][esquerda].estado,
									celulas[i][j].estado)
	}
}
#endregion
#region Alterar o estado do reticulado
for(var i = 0;i< VERTICAL; i++){
	for(var j = 0;j< HORIZONTAL; j++){
		celulas[i][j].estado = novosEstados[i][j]
	}
}
#endregion
alarm[0] = 2