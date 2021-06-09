package ManutencaoDados;

import Imoveis.Casa;
import Pessoas.Endereco;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
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

    public String[][] getMatrizCasas(){
        DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

        String[][] data = new String[casas.size()][4];
        for (int i = 0; i< casas.size();i++) {
            if(casas.get(i).isDisponivel()) {
                data[i][0] = (casas.get(i).isParaVenda() ? "Venda" : "Aluguel");
                data[i][1] = dateFormat.format(casas.get(i).getDataConstrucao());
                data[i][2] = Float.toString(casas.get(i).calculaValorFinal());
                data[i][3] = casas.get(i).getEndereco().getCidade();
            }
        }
        return data;
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
