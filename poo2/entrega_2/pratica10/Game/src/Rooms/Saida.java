import Game.Personagens.Personagem;

public class Saida implements Labirinto {

    public void selecionarCaminho(Personagem personagem) {
        System.out.println(personagem.getNome()+" encontrou a saída do labirinto!");
        System.out.println("");
    }

    public void jogar(Personagem personagem) {
        selecionarCaminho(personagem);
    }
    
}
