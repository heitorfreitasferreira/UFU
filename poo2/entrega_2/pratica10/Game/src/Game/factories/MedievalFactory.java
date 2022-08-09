package Game.factories;

import Atacar.ArcoFlecha;
import Atacar.AtacarStrategyInterface;
import Escudos.EscudoHandler;
import Escudos.EscudoMedieval;
import Game.Personagens.Arqueiro;
import Game.Personagens.Personagem;

public class MedievalFactory implements GameFactory{
    private static MedievalFactory instance = new MedievalFactory();
    private MedievalFactory(){

    }
    public static MedievalFactory getInstance(){
        return instance;
    }
    public Personagem createPersonagem(String nome) {
        return new Arqueiro(nome);
    }
    public AtacarStrategyInterface createArma(AtacarStrategyInterface personagem) {
        return new ArcoFlecha(personagem);
    }
    public EscudoHandler createEscudo() {
        return new EscudoMedieval();
    }
}
