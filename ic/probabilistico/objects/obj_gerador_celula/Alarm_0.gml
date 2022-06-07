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
	if(centro == arvore_viva and f<=0.00000000000000005) return arvore_queimando//0.0005
	return centro
}
function chopard2(n,s,o,l,ne,no,se,so,centro){
	var p = random_range(0,1)
	var f = random_range(0,100)
	var g = random_range(0,1)
	var total = (n==arvore_queimando)+(s==arvore_queimando)+(o==arvore_queimando)+(l==arvore_queimando)+(ne==arvore_queimando)+(no==arvore_queimando)+(se==arvore_queimando)+(so==arvore_queimando)
	if(centro == arvore_queimando) return solo_exposto
	if(centro == arvore_viva and (total>0)*(1-g) > 0.7) return arvore_queimando
	if(centro == solo_exposto and p<=0.01) return arvore_viva
	if(centro == arvore_viva and f<=0.005) return arvore_queimando
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
//Matriz de probabilidade da posição gerar fogo no centro
var coef = 1

				
matrixCoef =	[	
					[coef*0.6,	coef*0.8,	coef*0.6],
					[coef*0.4,	0,			coef*0.4],
					[coef*0.2,	coef*0.1,	coef*0.2]
				];

function rotaciona90(matriz){
	var copia=	[	
					[0,	0,	0],
					[0,	0,	0],
					[0,	0,	0]
				];
	//array_copy(copia,0,matriz,0,array_length(matriz))
	
	for (var i = 0; i < 3; i++) {
	    for (var j = 0; j < 3; j++) {
		   copia[j][3-1-i] = matriz[i][j]
		}
	}
	return copia
}
var intermediaria = rotaciona90(matrixCoef)
var i2 = rotaciona90(intermediaria)
var i3 = rotaciona90(i2)
matrixCoef = rotaciona90(i3)
/*			
var decay1 = 0.2
var decay2 = 0.4
var decay3 = 0.6
var decay4 = 0.7


var decayM = 0.75
matrixCoef2 =	[	
					[coef*,	coef,	coef-decay1],
					[coef-decay2,	0,			coef-decay1*2],
					[coef*0.2,	coef*0.1,	coef*0.2]
				];
*/
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
		novosEstados[i][j] = chopardVentoTunadoMatriz(	
							celulas[cima][j].estado,
									celulas[baixo][j].estado,
									celulas[i][esquerda].estado,
									celulas[i][direita].estado,
									celulas[cima][direita].estado,
									celulas[cima][esquerda].estado,
									celulas[baixo][direita].estado,
									celulas[baixo][esquerda].estado,
									celulas[i][j].estado,
									celulas[i][j].tempo_desde_queima
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