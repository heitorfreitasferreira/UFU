///@description Criação do reticulado
#region Variáveis
celulas = []
largura = 16
altura = 16
HORIZONTAL = 128
VERTICAL = 64
#macro solo_exposto 0
#macro arvore_queimando 1
#macro arvore_viva 2
#endregion
#region Inicializando a matriz do reticulado
for(var i = 0; i<VERTICAL;i++){
	var linhas = []
	for(var j = 0;j<HORIZONTAL; j++){
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
