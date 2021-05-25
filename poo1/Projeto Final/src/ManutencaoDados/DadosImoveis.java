package ManutencaoDados;

import Imoveis.Imovel;
import pessoas.Endereco;

import java.util.ArrayList;
import java.util.Objects;

public class DadosImoveis {
    private ArrayList<Imovel> imoveis;

    public void adicionarImovel(Imovel imovel){
        imoveis.add(imovel);
    }

    // Como diferenciar os imóveis? Criar método de comparação?
//    public void eliminarImovel(Endereco endereco){
//        if()
//            System.out.println("Não foi possível encontrar nenhuma imovel com o nome correspondente!");
//    }

    public void listarImoveis(){
        for (Imovel imovel : imoveis) {
            System.out.println(imovel.toString());
        }
    }

//    public Imovel buscarImovel(){
//        Imovel im = null;
//        for(Imovel imovel : imoveis){
//            if(imovel.getCpf().equals()){
//                im = imovel;
//                break;
//            }
//        }
//        return p;
//    }
}
