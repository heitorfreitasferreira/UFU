import Escudos.Escudo;
import Game.Personagens.Personagem;

public class SalaAleatoria extends ASala{
    public SalaAleatoria(Labirinto esq, Labirinto dir, Personagem inimigo){
        super(esq, dir, inimigo);
    }
    public void selecionarCaminho(Personagem personagem) {
        System.out.println(personagem.getNome()+" venceu o confronto com "+inimigo.getNome()+"!\n Lhe restam "+personagem.getVida()+" pontos de vida!");
        if(Math.random()<0.1){
            var valor_escudo = (int) (Math.random()*10);
            System.out.println(personagem.getNome()+" encontrou um escudo de +"+valor_escudo+"!!");
            personagem.addEscudo(new Escudo(valor_escudo));
        }
        if (Math.random() < 0.5) {
            System.out.println("Entrando na sala da esquerda...");
            rooms.get(0).jogar(personagem);
        }
        else {
            System.out.println("Entrando na sala da direita...");
            rooms.get(1).jogar(personagem);
        }
    }
    
}
