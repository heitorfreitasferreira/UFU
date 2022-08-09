package Game.factories;

import Atacar.AtacarStrategyInterface;
import Atacar.RaioParalisante;
import Escudos.EscudoHandler;
import Escudos.EscudoMedieval;
import Game.Personagens.Personagem;
import Game.Personagens.Robo;

public class FuturistaFactory implements GameFactory{
    private static FuturistaFactory instance = new FuturistaFactory();
    private FuturistaFactory(){

    }
    public static FuturistaFactory getInstance(){
        return instance;
    }

    public Personagem createPersonagem(String nome) {
        return new Robo(nome);
    }
    public AtacarStrategyInterface createArma(AtacarStrategyInterface personagem) {
        return new RaioParalisante(personagem);
    }
    public EscudoHandler createEscudo() {
        return new EscudoMedieval();
    }
}
