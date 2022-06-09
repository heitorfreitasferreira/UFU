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

//-------------------------
public class App {
    public static void main(String[] args) throws Exception {

        Personagem personagem = new Personagem(new PularBaixo(), new CorrerDevagar());
        System.out.println(personagem.pulo());
        System.out.println(personagem.correr());
    }
}
