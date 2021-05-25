package ManutencaoDados;

import pessoas.Corretor;

import java.util.ArrayList;
import java.util.Objects;

public class DadosCorretores {
    private ArrayList<Corretor> corretores;

    public void adicionarCorretor(Corretor corretor){
        corretores.add(corretor);
    }

    public void eliminarCorretor(String cpf){
        if(!corretores.removeIf(corretor -> Objects.equals(corretor.getCpf(), cpf)))
            System.out.println("Não foi possível encontrar nenhum corretor com o cpf correspondente!");
    }

    public void listarCorretores(){
        for (Corretor corretor : corretores) {
            System.out.println(corretor.toString());
        }
    }

    public Corretor buscarCorretor(String cpf){
        Corretor p = null;
        for(Corretor corretor : corretores){
            if(corretor.getCpf().equals(cpf)){
                p = corretor;
                break;
            }
        }
        return p;
    }
}
