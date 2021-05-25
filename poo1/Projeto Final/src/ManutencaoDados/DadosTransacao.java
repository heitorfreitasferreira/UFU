package ManutencaoDados;

import pessoas.Transacao;

import java.util.ArrayList;
import java.util.Objects;

public class DadosTransacao {
    private ArrayList<Transacao> transacoes;

    public void adicionarTransacao(Transacao transacao){
        transacoes.add(transacao);
    }

    public void eliminarTransacao(int nroContrato){
        if(!transacoes.removeIf(transacao -> Objects.equals(transacao.getNroContrato(), nroContrato)))
            System.out.println("Não foi possível encontrar nenhuma transacao com o numero de contrato correspondente!");
    }

    public void listarTransacaos(){
        for (Transacao transacao : transacoes) {
            System.out.println(transacao.toString());
        }
    }

    public Transacao buscarTransacao(int nroContrato){
        Transacao t = null;
        for(Transacao transacao : transacoes){
            if(transacao.getNroContrato() == nroContrato){
                t = transacao;
                break;
            }
        }
        return t;
    }
}
