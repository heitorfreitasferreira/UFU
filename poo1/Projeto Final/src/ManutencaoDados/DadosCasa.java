package ManutencaoDados;

import Imoveis.Casa;
import Pessoas.Endereco;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class DadosCasa {
    private ArrayList<Casa> casas;

    public DadosCasa() {
        this.casas = new ArrayList<Casa>();
    }

    public void adicionar(Casa casa){
        casas.add(casa);
    }

    // Como diferenciar os imóveis? Criar método de comparação?
    public void eliminar(Endereco endereco){
        if(casas.removeIf(casa -> casa.getEndereco().equals(endereco)))
            System.out.println("Não foi possível encontrar nenhuma casa com o endereço correspondente!");
    }

    public ArrayList<Casa> listar(){
        return casas;
    }

    public Casa buscar(Endereco endereco){
        Casa c = null;
        for(Casa casa : casas){
            if(casa.getEndereco().equals(endereco)){
                c = casa;
                break;
            }
        }
        return c;
    }

    public void salvaDadosBin(){
        FileOutputStream escritorArquivo = null;
        ObjectOutputStream escritorObj = null;
        try{
            escritorArquivo =new FileOutputStream("casasBin");
            escritorObj = new ObjectOutputStream(escritorArquivo);
            for (Casa casa : casas)
                escritorObj.writeObject(casa);
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
