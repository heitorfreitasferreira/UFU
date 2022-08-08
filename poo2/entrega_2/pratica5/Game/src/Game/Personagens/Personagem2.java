package Game.Personagens;

import Atacar.AtacarMedio;
import Correr.CorrerRapido;
import Escudos.Escudo;
import Pular.PularAlto;

public class Personagem2 extends Personagem{
    public Personagem2( String nome) {
        super(new PularAlto(), new CorrerRapido(), new AtacarMedio(), new Escudo(10),nome);
        //TODO Auto-generated constructor stub
    }
    
}
