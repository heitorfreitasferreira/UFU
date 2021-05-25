package ManutencaoDados;

import pessoas.Pessoa;

import java.util.ArrayList;
import java.util.Objects;

public class DadosPessoas {
    private ArrayList<Pessoa> pessoas;

    public void adicionarPessoa(Pessoa pessoa){
        pessoas.add(pessoa);
    }

    public void eliminarPessoa(String cpf){
        if(!pessoas.removeIf(pessoa -> Objects.equals(pessoa.getCpf(), cpf)))
            System.out.println("Não foi possível encontrar nenhuma pessoa com o cpf correspondente!");
    }

    public void listarPessoas(){
        for (Pessoa pessoa : pessoas) {
            System.out.println(pessoa.toString());
        }
    }

    public Pessoa buscarPessoa(String cpf){
        Pessoa p = null;
        for(Pessoa pessoa : pessoas){
            if(pessoa.getCpf().equals(cpf)){
                p = pessoa;
                break;
            }
        }
        return p;
    }
}
