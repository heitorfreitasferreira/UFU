package Game.Personagens;

import Atacar.AtacarForte;
import Correr.CorrerMedio;
import Escudos.Escudo;
import Pular.PularMedio;

public class Personagem1 extends Personagem{
    public Personagem1( String nome) {
        super(new PularMedio(), new CorrerMedio(), new AtacarForte(), new Escudo(10),nome);
    }
    
}
