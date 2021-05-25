package ManutencaoDados;

import pessoas.Cliente;

import java.util.ArrayList;
import java.util.Objects;

public class DadosClientes {
    private ArrayList<Cliente> clientes;

    public void adicionarCliente(Cliente cliente){
        clientes.add(cliente);
    }

    public void eliminarCliente(String cpf){
        if(!clientes.removeIf(cliente -> Objects.equals(cliente.getCpf(), cpf)))
            System.out.println("Não foi possível encontrar nenhum cliente com o cpf correspondente!");
    }

    public void listarClientes(){
        for (Cliente cliente : clientes) {
            System.out.println(cliente.toString());
        }
    }

    public Cliente buscarCliente(String cpf){
        Cliente cli = null;
        for(Cliente cliente : clientes){
            if(cliente.getCpf().equals(cpf)){
                cli = cliente;
                break;
            }
        }
        return cli;
    }
}
