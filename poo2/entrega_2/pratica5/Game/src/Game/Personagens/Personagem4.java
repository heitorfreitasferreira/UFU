package Game.Personagens;

import Atacar.AtacarMedio;
import Correr.CorrerMedio;
import Escudos.Escudo;
import Pular.PularMedio;

public class Personagem4 extends Personagem{
    
    public Personagem4(String nome) {
        super(new PularMedio(), new CorrerMedio(), new AtacarMedio(), new Escudo(10),nome);
        //TODO Auto-generated constructor stub
    }
    
}
