package Game.Personagens;

import Atacar.AtacarForte;
import Correr.CorrerMedio;
import Escudos.Escudo;
import Pular.PularMedio;

public class Inimigo extends Personagem{
    public Inimigo( String nome) {
        super(new PularMedio(), new CorrerMedio(), new AtacarForte(), new Escudo(10),nome);
    }

    @Override
    public String getNome() {
        return "Inimigo: "+ super.getNome();
    }
    
}
