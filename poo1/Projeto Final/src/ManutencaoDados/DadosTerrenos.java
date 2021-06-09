package ManutencaoDados;

import Imoveis.Terreno;
import Pessoas.Endereco;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class DadosTerrenos {
    private ArrayList<Terreno> terrenos;

    public DadosTerrenos() {
        this.terrenos = new ArrayList<Terreno>();
    }

    public void adicionar(Terreno terr){
        terrenos.add(terr);
    }

    // Como diferenciar os imóveis? Criar método de comparação?
    public void eliminar(Endereco endereco){
        if(terrenos.removeIf(terr -> terr.getEndereco().equals(endereco)))
            System.out.println("Não foi possível encontrar nenhuma casa com o endereço correspondente!");
    }

    public ArrayList<Terreno> listar(){
        return terrenos;
    }

    public Terreno buscar(Endereco endereco){
        Terreno terreno = null;
        for(Terreno terr : terrenos){
            if(terr.getEndereco().equals(endereco)){
                terreno = terr;
                break;
            }
        }
        return terreno;
    }

    public void salvaDadosBin(){
        FileOutputStream escritorArquivo = null;
        ObjectOutputStream escritorObj = null;
        try{
            escritorArquivo =new FileOutputStream("terrenosBin");
            escritorObj = new ObjectOutputStream(escritorArquivo);
            for (Terreno terr : terrenos)
                escritorObj.writeObject(terr);
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
