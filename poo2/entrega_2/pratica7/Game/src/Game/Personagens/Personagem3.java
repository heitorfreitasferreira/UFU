package Game.Personagens;

import Atacar.AtacarForte;
import Correr.CorrerRapido;
import Escudos.Escudo;
import Pular.PularBaixo;

public class Personagem3 extends Personagem{
    
    public Personagem3(String nome) {
        super(new PularBaixo(), new CorrerRapido(), new AtacarForte(), new Escudo(10),nome);
    }
    
}
