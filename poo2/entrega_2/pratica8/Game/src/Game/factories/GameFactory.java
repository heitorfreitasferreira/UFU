package Game.factories;

import Atacar.AtacarStrategyInterface;
import Escudos.EscudoHandler;
import Game.Personagens.Personagem;

public interface GameFactory {
    public Personagem createPersonagem( String nome);
    public AtacarStrategyInterface createArma(AtacarStrategyInterface personagem);
    public EscudoHandler createEscudo();
    
}
