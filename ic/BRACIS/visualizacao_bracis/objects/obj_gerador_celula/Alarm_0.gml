///@description Avançar o estado do reticulado
#region Funções
function avalia_quadrante(i,j){
	if (i < HORIZONTAL / 2 and j < VERTICAL / 2)
	  quadrante_b++;
	if (i < HORIZONTAL / 2 and j >= VERTICAL / 2)
	  quadrante_a++;
	if (i >= HORIZONTAL / 2 and j < VERTICAL / 2)
	  quadrante_c++;
	if (i >= HORIZONTAL / 2 and j >= VERTICAL / 2)
	  quadrante_d++;
}


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
	if(centro == florestal and total>0) return arvore_queimando
	if(centro == solo_exposto and p<=0.01) return campestre
	if(centro == florestal and f<=0.0005) return arvore_queimando//0.0005
	return centro
}
function chopard2(n,s,o,l,ne,no,se,so,centro){
	var p = random_range(0,1)
	var f = random_range(0,1)
	var g = random_range(0,1)
	var total = (n==arvore_queimando)+(s==arvore_queimando)+(o==arvore_queimando)+(l==arvore_queimando)+(ne==arvore_queimando)+(no==arvore_queimando)+(se==arvore_queimando)+(so==arvore_queimando)
	if(centro == arvore_queimando) return solo_exposto
	if(centro == florestal and (total>0)*(1-g) > 0.7) return arvore_queimando
	if(centro == solo_exposto and p<=0.01) return florestal
	if(centro == florestal and f<=0.0005) return arvore_queimando
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
	if(centro == florestal and (total>0)*(1-g) > 0.7) return arvore_queimando
	if(centro == solo_exposto and p<=0.01) return florestal
	//if(centro == florestal and f<=0.0005) return arvore_queimando
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
	//if(centro == florestal and (total>0)*(1-g) > 0.7) return arvore_queimando
	if(centro == solo_exposto and p<=0.0001) return florestal
	
	
	var tem_fogo = ondeTemFogo[0][0] + ondeTemFogo[0][1] + ondeTemFogo[0][2] + ondeTemFogo[1][0] + ondeTemFogo[1][1] + ondeTemFogo[1][2] + ondeTemFogo[2][0] + ondeTemFogo[2][1] + ondeTemFogo[2][1] 
	var tem_arvore = (n==florestal) +(s==florestal) +(l==florestal) +(o==florestal) + (no==florestal) + (ne==florestal) +(so==florestal) +(se==florestal)
	var f = irandom_range(0,8)
	if(centro == solo_exposto and tem_arvore>f and !tem_fogo) return florestal
	
	#region Ta pegando fogo bixo
	if(centro == florestal and tem_fogo >0 ){
		for(var i = 0; i<3;i++){
			for(var j = 0; j<3;j++){
				if(ondeTemFogo[i][j] and randomM[i][j]<matrixCoef[i][j]) return arvore_queimando
			}
		}
	}
	#endregion
	//if(centro == florestal and f<=1/157286400) return arvore_queimando
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
	if(centro == solo_exposto and p<=((tempo_desde_queima*tempo_desde_queima)/250000)) return florestal
	
	
	
	
	var tem_fogo = ondeTemFogo[0][0] + ondeTemFogo[0][1] + ondeTemFogo[0][2] + ondeTemFogo[1][0] + ondeTemFogo[1][1] + ondeTemFogo[1][2] + ondeTemFogo[2][0] + ondeTemFogo[2][1] + ondeTemFogo[2][1] 
	//var tem_arvore = (n==florestal) +(s==florestal) +(l==florestal) +(o==florestal) + (no==florestal) + (ne==florestal) +(so==florestal) +(se==florestal)
	//var f = irandom_range(0,8)
	//if(centro == solo_exposto and tem_arvore>f and !tem_fogo) return florestal
	
	#region Ta pegando fogo bixo
	if(centro == florestal and tem_fogo >0 ){
		for(var i = 0; i<3;i++){
			for(var j = 0; j<3;j++){
				if(ondeTemFogo[i][j] and randomM[i][j]<matrixCoef[i][j]) return arvore_queimando
			}
		}
	}
	#endregion
	//if(centro == florestal and f<=0.0005) return arvore_queimando
	return centro
}
function dilao1993(n,s,o,l,ne,no,se,so,centro,tempo_desde_queima,tempo_queimando){
	
		var temQueima = [
			[no==arvore_queimando,	n==arvore_queimando,	ne==arvore_queimando],
			[o==arvore_queimando,		false,				l==arvore_queimando],
			[so==arvore_queimando,	s==arvore_queimando,	se==arvore_queimando]
		]
	
	if(centro == arvore_queimando and tempo_queimando>3) return solo_exposto
	
	var temQueimaSoma = temQueima[0][0] + temQueima[0][1] + temQueima[0][2] + temQueima[1][0] + temQueima[1][1] + temQueima[1][2] + temQueima[2][0] + temQueima[2][1] + temQueima[2][1] 
	
	#region Ta pegando fogo bixo
	if(centro == florestal and temQueimaSoma>0 ){
		var randomM =	[
							[random_range(0,1),	random_range(0,1),	random_range(0,1)],
							[random_range(0,1),			0,			random_range(0,1)],
							[random_range(0,1),	random_range(0,1),	random_range(0,1)]
						];
		for(var i = 0; i<3;i++){
			for(var j = 0; j<3;j++){
				if(temQueima[i][j] and randomM[i][j]<matrixCoef[i][j]) return arvore_queimando
			}
		}
	}
	#endregion
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
	//if(centro == solo_exposto and p<=((tempo_desde_queima*tempo_desde_queima*coef/5*coef/5)/250000)) return florestal //antigo
	if(centro == solo_exposto and p<=((tempo_desde_queima*tempo_desde_queima)/20000000)) return florestal
	//Linear
	//if(centro == solo_exposto and p<=0.0001) return florestal
	#endregion
	var temQueimaSoma = temQueima[0][0] + temQueima[0][1] + temQueima[0][2] + temQueima[1][0] + temQueima[1][1] + temQueima[1][2] + temQueima[2][0] + temQueima[2][1] + temQueima[2][1] 
	var temInicioFogoSoma = temInicioFogo[0][0] + temInicioFogo[0][1] + temInicioFogo[0][2] + temInicioFogo[1][0] + temInicioFogo[1][1] + temInicioFogo[1][2] + temInicioFogo[2][0] + temInicioFogo[2][1] + temInicioFogo[2][1] 
	var temBrasaSoma = temBrasa[0][0] + temBrasa[0][1] + temBrasa[0][2] + temBrasa[1][0] + temBrasa[1][1] + temBrasa[1][2] + temBrasa[2][0] + temBrasa[2][1] + temBrasa[2][1] 
	
	
	if(centro == florestal and random_range(0,20)<=1/3145728000) {
		novos_focos++
		return arvore_queimando
	}
	#region Ta pegando fogo bixo
	if(centro == florestal and temQueimaSoma+temInicioFogoSoma+temBrasaSoma>0 ){
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
function heitorzera2(n,s,o,l,ne,no,se,so,centro,tempo_desde_queima,tempo_queimando,estado_inicial){
	
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
	if(centro == inicio_fogo and tempo_queimando>t_inicio_fogo) return arvore_queimando
	if(centro == arvore_queimando and tempo_queimando>t_arvore_queimando) return queima_lenta
	if(centro == queima_lenta and tempo_queimando >t_queima_lenta) return solo_exposto
	var p = random_range(0,1)
	#region Renascimento
	//Exp
	//if(centro == solo_exposto and p<=((tempo_desde_queima*tempo_desde_queima*coef/5*coef/5)/250000)) return florestal //antigo
	if(centro == solo_exposto and p<=((tempo_desde_queima*tempo_desde_queima)/20000000)) {
		if(estado_inicial == florestal)								return estado_inicial
		if(estado_inicial == savanica and random_range(0,1) < 0.8)	return estado_inicial
		if(estado_inicial == savanica and random_range(0,1) < 0.6)	return estado_inicial
	}
	//Linear
	//if(centro == solo_exposto and p<=0.0001) return florestal
	#endregion
	var temQueimaSoma = temQueima[0][0] + temQueima[0][1] + temQueima[0][2] + temQueima[1][0] + temQueima[1][1] + temQueima[1][2] + temQueima[2][0] + temQueima[2][1] + temQueima[2][1] 
	var temInicioFogoSoma = temInicioFogo[0][0] + temInicioFogo[0][1] + temInicioFogo[0][2] + temInicioFogo[1][0] + temInicioFogo[1][1] + temInicioFogo[1][2] + temInicioFogo[2][0] + temInicioFogo[2][1] + temInicioFogo[2][1] 
	var temBrasaSoma = temBrasa[0][0] + temBrasa[0][1] + temBrasa[0][2] + temBrasa[1][0] + temBrasa[1][1] + temBrasa[1][2] + temBrasa[2][0] + temBrasa[2][1] + temBrasa[2][1] 
	
	
	/*if(centro >=campestre and centro <= florestal and random_range(0,20)<=1/3145728000) {
		novos_focos++
		return arvore_queimando
	}*/
	#region Ta pegando fogo bixo
	var vegetacao = 0
	if(centro == savanica) vegetacao = 1
	if(centro == florestal) vegetacao = 0.8
	if(centro == campestre) vegetacao = 0.6
	 
	if(centro >=campestre and centro <= florestal and temQueimaSoma+temInicioFogoSoma+temBrasaSoma>0 ){
		var randomM =	[
							[random_range(0,1),	random_range(0,1),	random_range(0,1)],
							[random_range(0,1),			0,			random_range(0,1)],
							[random_range(0,1),	random_range(0,1),	random_range(0,1)]
						];
		for(var i = 0; i<3;i++){
			for(var j = 0; j<3;j++){
				if(temInicioFogo[i][j] and randomM[i][j] < (matrixCoef[i][j]*0.6*vegetacao)*coef_umidade) return inicio_fogo
				if(temQueima[i][j] and randomM[i][j] < (matrixCoef[i][j]*vegetacao)*coef_umidade) return inicio_fogo
				if(temBrasa[i][j] and randomM[i][j] < (matrixCoef[i][j]*0.2*vegetacao)*coef_umidade) return inicio_fogo
			}
		}
	}
	#endregion
	return centro
	// Diminuir decaimento da matriz com a diminuição do coef
	// 
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
		novosEstados[i][j] = heitorzera2(	
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
									celulas[i][j].tempo_queimando,
									celulas[i][j].estado_inicial
									
									)
		if novosEstados[i][j] == inicio_fogo and celulas[i][j].estado != inicio_fogo
			avalia_quadrante(i,j)
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
//if iteracoes<200
alarm[0] = 1
//else{
//	mostrar_dados = true
//}