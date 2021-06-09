package ManutencaoDados;

import Imoveis.Apartamento;
import Pessoas.Endereco;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class DadosApartamento {
    private ArrayList<Apartamento> apartamentos;

    public DadosApartamento() {
        this.apartamentos = new ArrayList<Apartamento>();
    }

    public void adicionar(Apartamento ape){
        apartamentos.add(ape);
    }

    // Como diferenciar os imóveis? Criar método de comparação?
    public void eliminar(Endereco endereco){
        if(apartamentos.removeIf(ape -> ape.getEndereco().equals(endereco)))
            System.out.println("Não foi possível encontrar nenhuma casa com o endereço correspondente!");
    }

    public ArrayList<Apartamento> listar(){
        return apartamentos;
    }

    public Apartamento buscar(Endereco endereco){
        Apartamento ap = null;
        for(Apartamento ape : apartamentos){
            if(ape.getEndereco().equals(endereco)){
                ap = ape;
                break;
            }
        }
        return ap;
    }

    public void salvaDadosBin(){
        FileOutputStream escritorArquivo = null;
        ObjectOutputStream escritorObj = null;
        try{
            escritorArquivo =new FileOutputStream("apartamentosBin");
            escritorObj = new ObjectOutputStream(escritorArquivo);
            for (Apartamento ape : apartamentos)
                escritorObj.writeObject(ape);
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
