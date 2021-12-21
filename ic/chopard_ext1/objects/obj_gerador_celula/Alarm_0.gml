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
	var total = (n==queima)+(s==queima)+(o==queima)+(l==queima)+(ne==queima)+(no==queima)+(se==queima)+(so==queima)
	if(centro == queima) return solo_exposto
	if(centro == arvore_viva and total>0) return queima
	if(centro == solo_exposto and p<=0.01) return arvore_viva
	if(centro == arvore_viva and f<=0.0005) return queima//0.0005
	return centro
}
function chopard2(n,s,o,l,ne,no,se,so,centro){
	var p = random_range(0,1)
	var f = random_range(0,1)
	var g = random_range(0,1)
	var total = (n==queima)+(s==queima)+(o==queima)+(l==queima)+(ne==queima)+(no==queima)+(se==queima)+(so==queima)
	if(centro == queima) return solo_exposto
	if(centro == arvore_viva and (total>0)*(1-g) > 0.7) return queima
	if(centro == solo_exposto and p<=0.01) return arvore_viva
	if(centro == arvore_viva and f<=0.0005) return queima
	return centro
}
function chopard_ext1(n,s,o,l,ne,no,se,so,centro){
	var total_fogo = (n>=queima and n<=queima3)+(s>=queima and s<=queima3)+(o>=queima and o<=queima3)+(l>=queima and l<=queima3)+(ne>=queima and ne<=queima3)+(no>=queima and no<=queima3)+(se>=queima and se<=queima3)+(so>=queima and so<=queima3)
	var total_arvore = (n==arvore_viva)+(s==arvore_viva)+(o==arvore_viva)+(l==arvore_viva)+(ne==arvore_viva)+(no==arvore_viva)+(se==arvore_viva)+(so==arvore_viva)
	var total_casa = (n==casa)+(s==casa)+(o==casa)+(l==casa)+(ne==casa)+(no==casa)+(se==casa)+(so==casa)
	
	var purb = random_range(0,1)
	var pinc = random_range(0,1)
	var p = random_range(0,1)
	
	if(centro == agua) return agua
	if(centro == asfalto) return asfalto
	if(centro == casa and total_fogo>0) return queima
	if(centro == arvore_viva and total_fogo>0) return queima
	if(centro == solo_exposto and total_arvore>0) return arvore_viva
	if(centro == solo_exposto and total_casa>0) return casa
	if(centro == queima) return queima2
	if(centro == queima2) return queima3
	if(centro == queima3) return solo_exposto
	if((centro == arvore_viva or centro == solo_exposto) and purb<0.0001) return casa
	if((centro == casa or centro == arvore_viva) and pinc<0.0001) return queima
	if(centro == solo_exposto and p<0.0001) return arvore_viva
	return centro
}
/*
i) uma celula de estado agua ou estrada não é alterada (inicialmente o modelo n não está tratando mudança de volume de corpos d’agua e construção de novas estradas/vias);
ii) uma célula de estado casa ou arvore, com vizinha de estado fogo, transforma-se em célula de estado fogo; 
iii) uma celula de estado solo, transforma-se em arvore, se na sua vizinhança houver mais celulas de estado arvore, ou transforma-se em casa, se na sua vizinhança houver mais celulas de estado casa; 
iv) uma celula de estado fogo permanece fogo, por um espaco de tempo t, depois transforma-se em solo; 
v) nas celulas cujos estados arvore e solo há uma probabilidade purb deles tornarem-se casa; 
vi) nos estados casa e arvore há uma probabilidade pinc de tornarem-se fogo
vii) no estado solo ha a probabilidade p de tornar-se arvore.


*/
//Remover Borda FEITO
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
		if(i == 0) var cima = VERTICAL
		else var cima = i-1
		/*if(i == VERTICAL-1) var baixo = VERTICAL
		else*/ var baixo = i +1
		if(j==0) var esquerda = HORIZONTAL
		else var esquerda = j-1
		/*if(j == HORIZONTAL-1) var direita = HORIZONTAL
		else*/ var direita = j +1
		#endregion
		novosEstados[i][j] = chopard_ext1(	celulas[cima][j].estado,
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