import Game.Personagens.Personagem;

public class Saida implements Labirinto {

    public void jogar(Personagem personagem) {
        System.out.println(personagem.getNome()+" encontrou a saída do labirinto!");
        System.out.println("");
    }
    
}
