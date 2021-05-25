package ManutencaoDados;

import pessoas.ClienteProprietario;

import java.util.ArrayList;
import java.util.Objects;

public class DadosClientesProprietarios {
    private ArrayList<ClienteProprietario> clientesProprietarios;

    public void adicionarClienteProprietario(ClienteProprietario cliente){
        clientesProprietarios.add(cliente);
    }

    public void eliminarClienteProprietario(String cpf){
        if(!clientesProprietarios.removeIf(cliente -> Objects.equals(cliente.getCpf(), cpf)))
            System.out.println("Não foi possível encontrar nenhum cliente com o cpf correspondente!");
    }

    public void listarClientesProprietarios(){
        for (ClienteProprietario cliente : clientesProprietarios) {
            System.out.println(cliente.toString());
        }
    }

    public ClienteProprietario buscarClienteProprietario(String cpf){
        ClienteProprietario cli = null;
        for(ClienteProprietario cliente: clientesProprietarios){
            if(cliente.getCpf().equals(cpf)){
                cli = cliente;
                break;
            }
        }
        return cli;
    }
}
