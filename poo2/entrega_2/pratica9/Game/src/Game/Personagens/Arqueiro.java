package Game.Personagens;

import Atacar.AtacarForte;
import Correr.CorrerDevagar;
import Escudos.Escudo;
import Pular.PularMedio;

public class Arqueiro extends Personagem {
    public Arqueiro( String nome) {
        super(new PularMedio(), new CorrerDevagar(), new AtacarForte(), new Escudo(0),"Arqueiro: "+nome);
    }
}
