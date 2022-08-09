package Game.Personagens;

import Atacar.AtacarMedio;
import Correr.CorrerRapido;
import Escudos.Escudo;
import Pular.PularBaixo;

public class Robo extends Personagem {
    public Robo(String nome){
        super(new PularBaixo(), new CorrerRapido(), new AtacarMedio(), new Escudo(0),"Robô: "+nome);
    }
}
