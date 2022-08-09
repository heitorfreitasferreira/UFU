import java.util.Scanner;

import Escudos.Escudo;
import Game.Personagens.Personagem;

public class SalaEscolha extends ASala{
    public SalaEscolha(Labirinto esq, Labirinto dir, Personagem inimigo){
        super(esq, dir, inimigo);
    }
    public void selecionarCaminho(Personagem personagem) {
        personagem.apanhar(inimigo.getDanoAtaques());
        if(personagem.getVida() <= 0){
            System.out.println(personagem.getNome()+" perdeu o confronto com "+inimigo.getNome()+"! Melhore...");
        }
        else{
            System.out.println(personagem.getNome()+" venceu o confronto com "+inimigo.getNome()+"!\n Lhe restam "+personagem.getVida()+" pontos de vida!");

            if(Math.random()<0.1){
                var valor_escudo = (int) (Math.random()*10);
                System.out.println(personagem.getNome()+" encontrou um escudo de +"+valor_escudo+"!!");
                personagem.addEscudo(new Escudo(valor_escudo));
            }
            // Read the user input
            Scanner scanner = new Scanner(System.in);
            System.out.println("Escolha uma opção:");
            System.out.println("1 - Esquerda");
            System.out.println("2 - Direita");
            String opcao = scanner.nextLine();

            while(!opcao.equals("1") && !opcao.equals("2")){
                System.out.println("Opção inválida!");
                opcao = scanner.nextLine();
            }
            if (opcao.equals("1")) {
                System.out.println("Entrando na sala da esquerda...");
                rooms.get(0).jogar(personagem);
            }
            else if(opcao.equals("2")) {
                System.out.println("Entrando na sala da direita...");
                rooms.get(1).jogar(personagem);
            }
        }
        
    }
    
}
