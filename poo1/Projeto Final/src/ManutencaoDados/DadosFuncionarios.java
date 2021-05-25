package ManutencaoDados;

import pessoas.Funcionario;

import java.util.ArrayList;
import java.util.Objects;

public class DadosFuncionarios{
    private ArrayList<Funcionario> funcionarios;

    public void adicionarFuncionario(Funcionario funcionario){
        funcionarios.add(funcionario);
    }

    public void eliminarFuncionario(String cpf){
        if(!funcionarios.removeIf(funcionario -> Objects.equals(funcionario.getCpf(), cpf)))
            System.out.println("Não foi possível encontrar nenhum funcionario com o cpf correspondente!");
    }

    public void listarFuncionarios(){
        for (Funcionario funcionario : funcionarios) {
            System.out.println(funcionario.toString());
        }
    }

    public Funcionario buscarFuncionario(String cpf){
        Funcionario f = null;
        for(Funcionario funcionario : funcionarios){
            if(funcionario.getCpf().equals(cpf)){
                f = funcionario;
                break;
            }
        }
        return f;
    }
}
