#include "./../utils/index.h"

class Celula{
private:
    var estado,tempo_desde_queima,tempo_queimando;
    void set_estado(var estado){
        this->estado = estado;
        if(estado == solo_exposto) {tempo_desde_queima = 0; tempo_queimando = 0;}
        else tempo_desde_queima = - 1;
        // ---------
        if (estado == arvore_queimando) tempo_queimando = t_inicio_fogo;
        else if (estado == queima_lenta) tempo_queimando = t_arvore_queimando;
        else tempo_queimando = 0;
    }
    void avanca_fogo(){
        tempo_queimando++;
        if (tempo_queimando>=t_inicio_fogo){
            set_estado(arvore_queimando);
            return;
        }
        if (tempo_queimando>=t_arvore_queimando){
            set_estado(queima_lenta);
            return;
        }
        if(tempo_queimando>16){
            set_estado(solo_exposto);
            return;
        }
    }
    float influencia_vegetacao(var estado_atual_vegetacao){
        if(estado_atual_vegetacao == savanica)  return 1;
        if(estado_atual_vegetacao == florestal)  return 0.8;
        if(estado_atual_vegetacao == campestre)  return 0.6;
        return -1;
    }
public:
    Celula(var estado){
        set_estado(estado);
    }
    Celula(){
        set_estado(campestre);
    }
    var get_estado(){
        return this->estado;
    }
    void heitorzeira2(Celula n,Celula s,Celula o,Celula l,Celula ne,Celula no,Celula se,Celula so){
        #pragma region Matrizes
        bool temQueima[3][3] = {
			{no.estado==arvore_queimando,	n.estado==arvore_queimando,	ne.estado==arvore_queimando},
			{o.estado==arvore_queimando,		false,				l.estado==arvore_queimando},
			{so.estado==arvore_queimando,	s.estado==arvore_queimando,	se.estado==arvore_queimando}
		};
        bool temInicioFogo[3][3] = {
			{no.estado==inicio_fogo, n.estado==inicio_fogo,	 ne.estado==inicio_fogo},
			{o.estado==inicio_fogo, false,				l.estado==inicio_fogo},
			{so.estado==inicio_fogo, s.estado==inicio_fogo,	se.estado==inicio_fogo}
		}; //0.6
		bool temBrasa[3][3] = {
			{no.estado==queima_lenta,n.estado==queima_lenta,	ne.estado==queima_lenta},
			{o.estado==queima_lenta,	false,			l.estado==queima_lenta},
			{so.estado==queima_lenta,s.estado==queima_lenta,	se.estado==queima_lenta}
		};//0.2
        var temQueimaSoma = temQueima[0][0] + temQueima[0][1] + temQueima[0][2] + temQueima[1][0] + temQueima[1][1] + temQueima[1][2] + temQueima[2][0] + temQueima[2][1] + temQueima[2][1] ;
	    var temInicioFogoSoma = temInicioFogo[0][0] + temInicioFogo[0][1] + temInicioFogo[0][2] + temInicioFogo[1][0] + temInicioFogo[1][1] + temInicioFogo[1][2] + temInicioFogo[2][0] + temInicioFogo[2][1] + temInicioFogo[2][1];
	    var temBrasaSoma = temBrasa[0][0] + temBrasa[0][1] + temBrasa[0][2] + temBrasa[1][0] + temBrasa[1][1] + temBrasa[1][2] + temBrasa[2][0] + temBrasa[2][1] + temBrasa[2][1];
        
	
        #pragma endregion Matrizes
        if(estado>=inicio_fogo && estado<=queima_lenta)
           tempo_queimando++;
        if(estado == solo_exposto) tempo_desde_queima++;
        if(estado == inicio_fogo && tempo_queimando>2) 
            set_estado(arvore_queimando);
	    if(estado == arvore_queimando && tempo_queimando>6) 
            set_estado(queima_lenta);
	    if(estado == queima_lenta && tempo_queimando >16) 
            set_estado(solo_exposto);
        
        if(estado >=campestre && estado <= florestal && temQueimaSoma+temInicioFogoSoma+temBrasaSoma>0){


            double randomM [3][3 ]=	{
							{random_range(0,1),	random_range(0,1),	random_range(0,1)},
							{random_range(0,1),			0,			random_range(0,1)},
							{random_range(0,1),	random_range(0,1),	random_range(0,1)}
						};
            for(var i = 0; i<3;i++){
                for(var j = 0; j<3;j++){
                    if(temInicioFogo[i][j] && randomM[i][j] < (matrixCoef[i][j]*0.6*influencia_vegetacao(estado))/*-umidade_ar*/) set_estado(inicio_fogo);
                    if(temQueima[i][j] && randomM[i][j] < (matrixCoef[i][j]*influencia_vegetacao(estado))/*-umidade_ar*/) set_estado(inicio_fogo);
                    if(temBrasa[i][j] && randomM[i][j] < (matrixCoef[i][j]*0.2*influencia_vegetacao(estado))/*-umidade_ar*/) set_estado(inicio_fogo);
                }
		    }
        }
        

    }
};

void print_reticulado(Celula reticulado[TAMANHO_RETICULADO][TAMANHO_RETICULADO]);