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
	if(centro == arvore_viva and f<=0.0005) return arvore_queimando//0.0005
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
function chopardVento(n,s,o,l,ne,no,se,so,centro, intensidade){
	//Função simulando vento vindo de ne
	//intensidade: 0-1
	var p = random_range(0,1)
	var f = random_range(0,1)
	var g = random_range(0,1)
	var h = random_range(0,1)
	var total = (n==arvore_queimando)+(s==arvore_queimando)+(o==arvore_queimando)+(l==arvore_queimando)+(ne==arvore_queimando)+(no==arvore_queimando)+(se==arvore_queimando)+(so==arvore_queimando)
	var fogoContraVento = (ne==arvore_queimando)
	if(centro == arvore_queimando) return solo_exposto
	if(fogoContraVento and (intensidade*h)>0.7) return arvore_queimando
	if(centro == arvore_viva and (total>0)*(1-g) > 0.7) return arvore_queimando
	if(centro == solo_exposto and p<=0.01) return arvore_viva
	//if(centro == arvore_viva and f<=0.0005) return arvore_queimando
	return centro
}

function taDandoOnda(n,s,o,l,ne,no,se,so,centro){
	//Matriz de probabilidade da posição gerar fogo no centro
	
	//Matriz de número aleatórios
	var randomM =	[	[random_range(0,1),	random_range(0,1),	random_range(0,1)],
						[random_range(0,1),			0,			random_range(0,1)],
						[random_range(0,1),	random_range(0,1),	random_range(0,1)]
					];
	//Matriz indicando onde há fogo (há fumaça)
	var ondeTemFogo = [	[(no==arvore_queimando),	(n==arvore_queimando),	(ne==arvore_queimando)],
						[(o==arvore_queimando),		false,						(l==arvore_queimando)],
						[(so==arvore_queimando),	(s==arvore_queimando),	(se==arvore_queimando)]
						]
	
	
	
	
	//Probabilidade de nascer uma árvore
	var p = random_range(0,1)
	if(centro == arvore_queimando) return solo_exposto
	//if(centro == arvore_viva and (total>0)*(1-g) > 0.7) return arvore_queimando
	if(centro == solo_exposto and p<=0.0001) return arvore_viva
	
	
	var tem_fogo = ondeTemFogo[0][0] + ondeTemFogo[0][1] + ondeTemFogo[0][2] + ondeTemFogo[1][0] + ondeTemFogo[1][1] + ondeTemFogo[1][2] + ondeTemFogo[2][0] + ondeTemFogo[2][1] + ondeTemFogo[2][1] 
	var tem_arvore = (n==arvore_viva) +(s==arvore_viva) +(l==arvore_viva) +(o==arvore_viva) + (no==arvore_viva) + (ne==arvore_viva) +(so==arvore_viva) +(se==arvore_viva)
	var f = irandom_range(0,8)
	if(centro == solo_exposto and tem_arvore>f and !tem_fogo) return arvore_viva
	
	#region Ta pegando fogo bixo
	if(centro == arvore_viva and tem_fogo >0 ){
		for(var i = 0; i<3;i++){
			for(var j = 0; j<3;j++){
				if(ondeTemFogo[i][j] and randomM[i][j]<matrixCoef[i][j]) return arvore_queimando
			}
		}
	}
	#endregion
	//if(centro == arvore_viva and f<=0.0005) return arvore_queimando
	return centro
}
function chopardVentoTunadoMatriz(n,s,o,l,ne,no,se,so,centro,tempo_desde_queima){
	
	#region Matrizes
	//Matriz de número aleatórios
	var randomM =	[	[random_range(0,1),	random_range(0,1),	random_range(0,1)],
						[random_range(0,1),			0,			random_range(0,1)],
						[random_range(0,1),	random_range(0,1),	random_range(0,1)]
					];
	//Matriz indicando onde há fogo (há fumaça)
	var ondeTemFogo = [	[(no==arvore_queimando),	(n==arvore_queimando),	(ne==arvore_queimando)],
						[(o==arvore_queimando),		false,						(l==arvore_queimando)],
						[(so==arvore_queimando),	(s==arvore_queimando),	(se==arvore_queimando)]
						]
	#endregion
	
	var p = random_range(0,1)
	if(centro == arvore_queimando) return solo_exposto
	if(centro == solo_exposto and p<=((tempo_desde_queima*tempo_desde_queima)/250000)) return arvore_viva
	
	
	
	
	var tem_fogo = ondeTemFogo[0][0] + ondeTemFogo[0][1] + ondeTemFogo[0][2] + ondeTemFogo[1][0] + ondeTemFogo[1][1] + ondeTemFogo[1][2] + ondeTemFogo[2][0] + ondeTemFogo[2][1] + ondeTemFogo[2][1] 
	//var tem_arvore = (n==arvore_viva) +(s==arvore_viva) +(l==arvore_viva) +(o==arvore_viva) + (no==arvore_viva) + (ne==arvore_viva) +(so==arvore_viva) +(se==arvore_viva)
	//var f = irandom_range(0,8)
	//if(centro == solo_exposto and tem_arvore>f and !tem_fogo) return arvore_viva
	
	#region Ta pegando fogo bixo
	if(centro == arvore_viva and tem_fogo >0 ){
		for(var i = 0; i<3;i++){
			for(var j = 0; j<3;j++){
				if(ondeTemFogo[i][j] and randomM[i][j]<matrixCoef[i][j]) return arvore_queimando
			}
		}
	}
	#endregion
	//if(centro == arvore_viva and f<=0.0005) return arvore_queimando
	return centro
}
function heitorzera1(n,s,o,l,ne,no,se,so,centro,tempo_desde_queima,tempo_queimando){
	
	#region Matrizes
	
		var temQueima = [
			[no==arvore_queimando,	n==arvore_queimando,	ne==arvore_queimando],
			[o==arvore_queimando,		false,				l==arvore_queimando],
			[so==arvore_queimando,	s==arvore_queimando,	se==arvore_queimando]
		]
		var temInicioFogo = [
			[no==inicio_fogo, n==inicio_fogo,	 ne==inicio_fogo],
			[o==inicio_fogo, false,				l==inicio_fogo],
			[so==inicio_fogo, s==inicio_fogo,	se==inicio_fogo]
		] //0.6
		var temBrasa = [
			[no==queima_lenta,n==queima_lenta,	ne==queima_lenta],
			[o==queima_lenta,	false,			l==queima_lenta],
			[so==queima_lenta,s==queima_lenta,	se==queima_lenta]
		]//0.2
	#endregion
	if(centro == inicio_fogo and tempo_queimando>2) return arvore_queimando
	if(centro == arvore_queimando and tempo_queimando>6) return queima_lenta
	if(centro == queima_lenta and tempo_queimando >16) return solo_exposto
	var p = random_range(0,1)
	#region Renascimento
	//Exp
	//if(centro == solo_exposto and p<=((tempo_desde_queima*tempo_desde_queima*coef*coef)/250000)) return arvore_viva
	//Linear
	if(centro == solo_exposto and p<=0.0001) return arvore_viva
	#endregion
	var temQueimaSoma = temQueima[0][0] + temQueima[0][1] + temQueima[0][2] + temQueima[1][0] + temQueima[1][1] + temQueima[1][2] + temQueima[2][0] + temQueima[2][1] + temQueima[2][1] 
	var temInicioFogoSoma = temInicioFogo[0][0] + temInicioFogo[0][1] + temInicioFogo[0][2] + temInicioFogo[1][0] + temInicioFogo[1][1] + temInicioFogo[1][2] + temInicioFogo[2][0] + temInicioFogo[2][1] + temInicioFogo[2][1] 
	var temBrasaSoma = temBrasa[0][0] + temBrasa[0][1] + temBrasa[0][2] + temBrasa[1][0] + temBrasa[1][1] + temBrasa[1][2] + temBrasa[2][0] + temBrasa[2][1] + temBrasa[2][1] 

	#region Ta pegando fogo bixo
	if(centro == arvore_viva and temQueimaSoma+temInicioFogoSoma+temBrasaSoma>0 ){
		var randomM =	[
							[random_range(0,1),	random_range(0,1),	random_range(0,1)],
							[random_range(0,1),			0,			random_range(0,1)],
							[random_range(0,1),	random_range(0,1),	random_range(0,1)]
						];
		for(var i = 0; i<3;i++){
			for(var j = 0; j<3;j++){
				if(temInicioFogo[i][j] and randomM[i][j]<matrixCoef[i][j]*0.6) return inicio_fogo
				if(temQueima[i][j] and randomM[i][j]<matrixCoef[i][j]) return inicio_fogo
				if(temBrasa[i][j] and randomM[i][j]<matrixCoef[i][j]*0.2) return inicio_fogo
			}
		}
	}
	#endregion
	return centro
}
#endregion
#region Calcular novos estados

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
		novosEstados[i][j] = heitorzera1(	
									celulas[cima][j].estado,
									celulas[baixo][j].estado,
									celulas[i][esquerda].estado,
									celulas[i][direita].estado,
									celulas[cima][direita].estado,
									celulas[cima][esquerda].estado,
									celulas[baixo][direita].estado,
									celulas[baixo][esquerda].estado,
									celulas[i][j].estado,
									celulas[i][j].tempo_desde_queima,
									celulas[i][j].tempo_queimando
									)
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
iteracoes++
alarm[0] = 1