package ManutencaoDados;

import Pessoas.ClienteProprietario;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Objects;

public class DadosClientesProprietarios implements IManutencao<ClienteProprietario>{
    private ArrayList<ClienteProprietario> clientesProprietarios;

    public DadosClientesProprietarios() {
        this.clientesProprietarios = new ArrayList<ClienteProprietario> ();
    }

    @Override
    public void adicionar(ClienteProprietario cliente){
        clientesProprietarios.add(cliente);
    }

    @Override
    public void eliminar(String cpf){
        if(!clientesProprietarios.removeIf(cliente -> Objects.equals(cliente.getCpf(), cpf)))
            System.out.println("Não foi possível encontrar nenhum cliente com o cpf correspondente!");
    }

    @Override
    public void listar(){
        for (ClienteProprietario cliente : clientesProprietarios) {
            System.out.println(cliente.toString());
        }
    }
    public String[][] getMatrizClientesProprietarios(){

        String[][] data = new String[clientesProprietarios.size()][3];
        for (int i = 0; i< clientesProprietarios.size();i++) {
            data[i][0] = clientesProprietarios.get(i).getNome();
            data[i][1] = clientesProprietarios.get(i).getEmail();
            data[i][2] = clientesProprietarios.get(i).getCelular();
        }
        return data;
    }
    @Override
    public ClienteProprietario buscar(String cpf){
        ClienteProprietario cli = null;
        for(ClienteProprietario cliente: clientesProprietarios){
            if(cliente.getCpf().equals(cpf)){
                cli = cliente;
                break;
            }
        }
        return cli;
    }

    @Override
    public void salvaDadosBin(){
        FileOutputStream escritorArquivo = null;
        ObjectOutputStream escritorObj = null;
        try{
            escritorArquivo =new FileOutputStream("ClientesProprietáriosBin");
            escritorObj = new ObjectOutputStream(escritorArquivo);
            for (ClienteProprietario cliente : clientesProprietarios)
                escritorObj.writeObject(cliente);
        } catch (IOException e){
            System.out.println(e.getMessage());
        } finally {
            try{
                if(escritorArquivo != null)
                    escritorArquivo.close();
            }catch(Exception e){
                System.out.println(e.getMessage());
            }
        }
    }
}
