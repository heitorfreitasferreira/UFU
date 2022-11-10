import java.util.ArrayList;

import Context.Reticulado;
import Utils.MatrizVento;

public class App {
    public static void main(String[] args) throws Exception {

        var quadrantes = new ArrayList<Integer>();
        quadrantes.add(5);
        quadrantes.add(5);
        quadrantes.add(5);
        quadrantes.add(5);
        Reticulado reticulado = new Reticulado(32, "ne", 0.35, quadrantes, 32 / 2, 32 / 2);
        reticulado.printa();
        for (int i = 0; i < 100; i++) {
            reticulado.atualiza();
            reticulado.printa();
        }
    }
}
