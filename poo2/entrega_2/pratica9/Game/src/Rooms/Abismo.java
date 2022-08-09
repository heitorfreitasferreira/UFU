import java.time.Period;

import Game.Personagens.Personagem;

public class Abismo implements Labirinto{
    public void jogar(Personagem personagem){
        personagem.setVida(personagem.getVida()-personagem.getVida());
        System.out.println(personagem.getNome()+ " perdeu "+personagem.getVida()+" pontos de vida ao cair em um abismo!");
        System.out.println("");
    }
}
