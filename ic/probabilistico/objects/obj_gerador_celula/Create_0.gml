///@description Criação do reticulado
#region Variáveis
celulas = []
#macro largura 16
#macro altura 16
#macro HORIZONTAL 128
#macro VERTICAL  64
#macro solo_exposto 0
#macro arvore_queimando 1
#macro arvore_viva 2
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
