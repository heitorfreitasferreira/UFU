package Observer;

import java.util.ArrayList;

public abstract class Subscriber {
    // Caso a forma de salvar seja particular para cada observador, pode-se criar uma interface para que o programador implemente a mesma.
    protected ArrayList<String> log = new ArrayList<String>();
    // Neste exemplo as informações serão guardadas em um log que é um array de strings, pode ser feito por exemplo salvando uma informação em arquivo ou banco de dados.
    public void update(String aviso){
        log.add(aviso);
    }
}
