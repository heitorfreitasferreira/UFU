///@description Criação do reticulado
path = filename_path(working_directory + "level.txt");
#region Variáveis
celulas = []
#macro largura sprite_get_width(spr_estado)
#macro altura sprite_get_height(spr_estado)
#macro HORIZONTAL room_width/largura
#macro VERTICAL  room_height/altura
#macro solo_exposto 0
#macro inicio_fogo 1
#macro arvore_queimando 2
#macro queima_lenta 3
#macro arvore_viva 4
#macro agua 5
iteracoes = 0
#endregion

#region Inicializando a matriz de estados
novosEstados = []
for(var i = 0; i<VERTICAL;i++){
	var linhas = []
	for(var j = 0;j<HORIZONTAL; j++){
		array_push(linhas,false)
	}
	array_push(novosEstados,linhas)
	array_delete(linhas,0,array_length(linhas))
}
#endregion
#region Inicializando a matriz do reticulado
for(var i = 0; i<=VERTICAL;i++){
	var linhas = []
	for(var j = 0;j<=HORIZONTAL; j++){
		array_push(linhas,false)
	}
	array_push(celulas,linhas)
	array_delete(linhas,0,array_length(linhas))
}

#endregion
#region Colocando uma celula em cada posição do 
for(var i = 0;i< VERTICAL; i++){
	for(var j = 0;j< HORIZONTAL; j++){
		celulas[i][j] = instance_create_layer(j*largura,i*altura,"Instances",obj_celula)
	}
}


#endregion

#region Inserindo posição vazia
var celula_temp = instance_create_layer(room_width + largura,room_height + altura,"Instances",obj_celula)
celula_temp.estado = solo_exposto
//celulas[VERTICAL] = array_create(HORIZONTAL,celula_temp)
for(var i = 0;i< HORIZONTAL; i++){
	celulas[VERTICAL][i] = celula_temp
}
for(var i = 0;i< VERTICAL; i++){
	celulas[i][HORIZONTAL] = celula_temp
}
celulas[VERTICAL][HORIZONTAL] = celula_temp
#endregion

celulas[VERTICAL/2][HORIZONTAL/2].estado = arvore_queimando
#region Jeito antigo
/*
for(var i = 0;i< VERTICAL; i++){
	var linha = []
	for(var j = 0;j< HORIZONTAL; j++){
		var celula = instance_create_layer(j*largura,i*altura,"Instances",obj_celula)
		celula.estado =true// choose(true,false)
		array_push(linha,celula)
	}
	array_push(celulas,linha)
	array_delete(linha,0,array_length(linha))
}
*/
#endregion


#region Criação da matriz de vento
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
coef = 1
var inicialCardeais =	[	
							[coef*0.12,	coef*0.16,	coef*0.12],
							[coef*0.08,	0,			coef*0.08],
							[coef*0.04,	coef*0.002,	coef*0.04]
						];
var inicialColaterais =	[	
							[coef*0.16,	coef*0.12,	coef*0.08],
							[coef*0.12,	0,			coef*0.04],
							[coef*0.08,	coef*0.04,	coef*0.002]
						];

matrixCoef = [	
					[0,	0,	0],
					[0,	0,	0],
					[0,	0,	0]
				];

function defineDirecao(i,f,inicialCardeais, inicialColaterais){
	if(i == "n" and f == "s"){
		return inicialCardeais
	}
	else if(i == "l" and f == "o"){
		return rotaciona90(inicialCardeais)
	}
	else if(i == "s" and f == "n"){
		var intermediaria = rotaciona90(inicialCardeais)
		return rotaciona90(intermediaria)
	}
	else if(i == "o" and f == "l"){
		var i1 = rotaciona90(inicialCardeais)
		var i2 = rotaciona90(i1)
		return rotaciona90(i2)
	}
	else if(i == "no" and f == "se"){
		return inicialColaterais
	}
	else if(i == "ne" and f == "so"){
		return rotaciona90(inicialColaterais)
	}
	else if(i == "se" and f == "no"){
		var intermediaria = rotaciona90(inicialColaterais)
		return rotaciona90(intermediaria)
	}
	else if(i == "so" and f == "ne"){
		var i1 = rotaciona90(inicialCardeais)
		var i2 = rotaciona90(i1)
		return rotaciona90(i2)
	}
	else return inicialCardeais
	
}

matrixCoef = defineDirecao("l","o",inicialCardeais, inicialColaterais)
#endregion