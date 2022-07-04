import Pular.PularBaixo;
import Pular.PularMedio;
import Pular.PularAlto;

//-------------------------
import Correr.CorrerDevagar;
import Correr.CorrerMedio;
import Correr.CorrerRapido;

//-------------------------
import Atacar.AtacarFraco;
import Atacar.AtacarMedio;
import Atacar.AtacarForte;

import java.util.ArrayList;

//-------------------------

import java.util.Scanner;

public class App {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);

        ArrayList<Personagem> jogadores = new ArrayList<Personagem>();

        jogadores.add(new Personagem1());
        jogadores.add(new Personagem2());
        jogadores.add(new Personagem3());

        for (int i = 0; i < jogadores.size(); i++) {
            System.out.println("Jogador " + (i + 1) + ":");
            System.out.println("Pular: " + jogadores.get(i).pulo());
            System.out.println("Correr: " + jogadores.get(i).correr());
            System.out.println("Atacar: " + jogadores.get(i).atacar());
            System.out.println("");
        }
    }
}


/** 
    Resultado de execução: 

    Jogador 1:
    Pular: Pulo Medio
    Correr: Corrida Media
    Atacar: Ataque Forte

    Jogador 2:
    Pular: Pulo Alto
    Correr: Corrida Rapida
    Atacar: Ataque Medio

    Jogador 3:
    Pular: Pulo Baixo
    Correr: Corrida Rapida
    Atacar: Ataque Forte

 */
