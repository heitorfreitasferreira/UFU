import Game.Personagem;
//-------------------------
import Pular.*;
import Correr.*;
// import Atacar.*;

//-------------------------
// import java.util.Scanner;
import java.util.ArrayList;

public class App {
    public static void main(String[] args) throws Exception {
        // Scanner scanner = new Scanner(System.in);
        Ferramentas ferramentas = new Ferramentas();
        ArrayList<Personagem> jogadores = new ArrayList<Personagem>();

        jogadores.add(new Personagem(new PularMedio(), new CorrerMedio()/* ,new AtacarMedio() */,
                ferramentas.getRandomNick()));
        jogadores.add(new Personagem(new PularAlto(), new CorrerRapido()/* ,new AtacarForte() */,
                ferramentas.getRandomNick()));
        jogadores.add(new Personagem(new PularBaixo(), new CorrerRapido()/* ,new AtacarFraco() */,
                ferramentas.getRandomNick()));
        for (int i = 0; i < jogadores.size(); i++) {
            System.out.println(jogadores.get(i).getNome() + " | " + jogadores.get(i).getVida() + "hp:");
            System.out.println("Pular: " + jogadores.get(i).pulo());
            System.out.println("Correr: " + jogadores.get(i).correr());
            // System.out.println("Atacar: " + jogadores.get(i).atacar());
            System.out.println("");
        }
        System.out.println("----------------------------------------------------");
        for (int i = 0; i < jogadores.size(); i++) {
            System.out.println(jogadores.get(i).getNome() + " | " + jogadores.get(i).getVida() + "hp:");
            System.out.println("Atacar ou curar? (a/c)");
            String opcao = "c";// scanner.nextLine();
            if (opcao.equals("a")) {
                System.out.print("Inflingir: ");
                int quantidade = 15;// scanner.nextLine();
                jogadores.get(i).apanhar(quantidade);
                System.out.println("Inlfingido " + quantidade);
            } else if (opcao.equals("c")) {
                System.out.print("Cura: ");
                int quantidade = 10 * i;// scanner.nextLine();
                jogadores.get(i).curar(quantidade);
                System.out.println("Curado " + quantidade);
            }
            System.out.println("");
        }
        System.out.println("----------------------------------------------------");
        for (int i = 0; i < jogadores.size(); i++) {
            System.out.println(jogadores.get(i).getNome() + " | " + jogadores.get(i).getVida() + "hp:");
            System.out.println("Pular: " + jogadores.get(i).pulo());
            System.out.println("Correr: " + jogadores.get(i).correr());
            // System.out.println("Atacar: " + jogadores.get(i).atacar());
            System.out.println("");
        }

    }
}
