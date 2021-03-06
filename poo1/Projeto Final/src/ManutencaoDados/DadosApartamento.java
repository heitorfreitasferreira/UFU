package ManutencaoDados;

import Imoveis.Apartamento;
import Pessoas.Endereco;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
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

    public String[][] getMatrizAps(){
        DateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");

        String[][] data = new String[apartamentos.size()][6];
        for (int i = 0; i< apartamentos.size();i++) {
            if(apartamentos.get(i).isDisponivel()) {
                data[i][0] = (apartamentos.get(i).isParaVenda() ? "Venda" : "Aluguel");
                data[i][1] = dateFormat.format(apartamentos.get(i).getDataConstrucao());
                data[i][2] = Float.toString(apartamentos.get(i).calculaValorFinal());
                data[i][3] = apartamentos.get(i).getEndereco().getCidade();
                data[i][4] = apartamentos.get(i).isPortaria24h() ? "Sim" : "Não";
                data[i][5] = Integer.toString(apartamentos.get(i).getAndar());
            }
        }
        return data;
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
