///@description Altera a imagem para refletir o estado
image_index = estado
#region tempo desde a queima
if(estado == solo_exposto) tempo_desde_queima++
else tempo_desde_queima = 0
#endregion

#region tempo queimando
if(estado>solo_exposto and estado<arvore_viva) tempo_queimando++
else tempo_queimando = -1
#endregion	