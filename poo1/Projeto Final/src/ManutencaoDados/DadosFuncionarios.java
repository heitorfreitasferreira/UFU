package ManutencaoDados;

import Pessoas.Funcionario;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Objects;

public class DadosFuncionarios implements IManutencao<Funcionario>{
    private ArrayList<Funcionario> funcionarios;

    public DadosFuncionarios() {
        this.funcionarios = new ArrayList<Funcionario>();
    }

    @Override
    public void adicionar(Funcionario funcionario){
        funcionarios.add(funcionario);
    }

    @Override
    public void eliminar(String cpf){
        if(!funcionarios.removeIf(funcionario -> Objects.equals(funcionario.getCpf(), cpf)))
            System.out.println("Não foi possível encontrar nenhum funcionario com o cpf correspondente!");
    }

    @Override
    public void listar(){
        for (Funcionario funcionario : funcionarios) {
            System.out.println(funcionario.toString());
        }
    }
    public String[][] getMatrizFuncionarios(){

        String[][] data = new String[funcionarios.size()][4];
        for (int i = 0; i< funcionarios.size();i++) {
            data[i][0] = funcionarios.get(i).getNome();
            data[i][1] = funcionarios.get(i).getEmail();
            data[i][2] = funcionarios.get(i).getCelular();
            data[i][3] = funcionarios.get(i).getCargo();
        }
        return data;
    }
    @Override
    public Funcionario buscar(String cpf){
        Funcionario f = null;
        for(Funcionario funcionario : funcionarios){
            if(funcionario.getCpf().equals(cpf)){
                f = funcionario;
                break;
            }
        }
        return f;
    }

    @Override
    public void salvaDadosBin(){
        FileOutputStream escritorArquivo = null;
        ObjectOutputStream escritorObj = null;
        try{
            escritorArquivo =new FileOutputStream("FuncionariosBin");
            escritorObj = new ObjectOutputStream(escritorArquivo);
            for (Funcionario funcionario : funcionarios)
                escritorObj.writeObject(funcionario);
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
