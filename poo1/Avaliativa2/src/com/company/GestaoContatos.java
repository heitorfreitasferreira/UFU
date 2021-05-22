import java.util.ArrayList;
import java.util.Objects;

public class GestaoContatos {
    private ArrayList<Contato> familia;
    private ArrayList<Contato> amigos;
    private ArrayList<Contato> profissional;

    public void adicionaContato(Contato novoContato, int lista){
        if (lista == 1)
            familia.add(novoContato);
        else if (lista == 2)
            amigos.add(novoContato);
        else if (lista == 3)
            profissional.add(novoContato);
    }

    public void eliminaContato(String nome){
        boolean flag = false;
        flag = familia.removeIf(contato -> Objects.equals(contato.getNome(), nome));
        if(!flag)
            flag = amigos.removeIf(contato -> Objects.equals(contato.getNome(), nome));
        if(!flag)
            flag = profissional.removeIf(contato -> Objects.equals(contato.getNome(), nome));
        if (!flag)
            System.out.println("Não foi possível encontrar nenhum contato com o nome correspondente!");
    }

    public void listaContatos(int lista){
        ArrayList<Contato> contatos = new ArrayList<Contato>();
        if (lista == 1)
            contatos = familia;
        else if (lista == 2)
            contatos = amigos;
        else if (lista == 3)
            contatos = profissional;
        for (Contato contato : contatos) {
            System.out.println(contato.toString());
        }
    }

    public int maisVelho(int lista){
        ArrayList<Contato> contatos = new ArrayList<Contato>();
        if (lista == 1)
            contatos = familia;
        else if (lista == 2)
            contatos = amigos;
        else if (lista == 3)
            contatos = profissional;

        int max = 0;
        for (Contato contato : contatos) {
            if (contato.getIdade() > max)
                max = contato.getIdade();
        }

        return max;
    }

    public int maisNovo(int lista){
        ArrayList<Contato> contatos = new ArrayList<Contato>();
        if (lista == 1)
            contatos = familia;
        else if (lista == 2)
            contatos = amigos;
        else if (lista == 3)
            contatos = profissional;

        int min = 0;
        int count = 0;
        for (Contato contato : contatos) {
            if (count == 0)
                min = contato.getIdade();
            if (contato.getIdade() < min)
                min = contato.getIdade();
            count++;
        }

        return min;
    }

    @Override
    public String toString() {
        return "GestaoContatos{" +
                "familia=" + familia +
                ", amigos=" + amigos +
                ", profissional=" + profissional +
                '}';
    }
}
