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
/*
for(var i = 0;i<TOTAL;i++){
	if(i == 0) var anterior = array_length(celulas)-1
	else var anterior = i-1
	if(i == array_length(celulas)-1) var proximo = 0
	else var proximo = i +1
	
	 
}




*/
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
		novosEstados[i][j] = life(	celulas[cima][j].estado,
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