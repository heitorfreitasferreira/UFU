package pessoas;

import java.util.Date;

public class Transacao {
    private Date dataTransacao;
    private String metodoPagamento;
    private int nroContato;
    private static int qntContratosTotal;

    public Transacao(Date dataTransacao, String metodoPagamento) {
        this.dataTransacao = dataTransacao;
        this.metodoPagamento = metodoPagamento;
        this.nroContato = qntContratosTotal;
        qntContratosTotal++;
    }

    public Date getDataTransacao() {
        return dataTransacao;
    }

    public void setDataTransacao(Date dataTransacao) {
        this.dataTransacao = dataTransacao;
    }

    public String getMetodoPagamento() {
        return metodoPagamento;
    }

    public void setMetodoPagamento(String metodoPagamento) {
        this.metodoPagamento = metodoPagamento;
    }

    public int getNroContato() {
        return nroContato;
    }

}
