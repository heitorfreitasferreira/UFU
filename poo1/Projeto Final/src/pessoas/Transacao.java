package pessoas;

import Imoveis.Imovel;

import java.util.Date;

public class Transacao {
    private Date dataTransacao;
    private String metodoPagamento;
    private float valor;
    private Cliente usuario;
    private Imovel imovel;
    private Corretor corretor;
    private final int nroContato;
    private static int qntContratosTotal;

    public Transacao(Cliente usuario, Imovel imovel){
        setImovel(imovel);
        setUsuario(usuario);
        this.nroContato = qntContratosTotal;
        qntContratosTotal++;
    }

    public Transacao(Date dataTransacao, String metodoPagamento, Cliente usuario, Imovel imovel, Funcionario corretor) {
        this.dataTransacao = dataTransacao;
        this.metodoPagamento = metodoPagamento;
        setImovel(imovel);
        setUsuario(usuario);
        this.nroContato = qntContratosTotal;
        qntContratosTotal++;
    }

    public void setValor(float valor) { this.valor = valor; }

    public float getValor() { return valor; }

    public Funcionario getCorretor() { return corretor; }

    public void setCorretor(Corretor corretor) { this.corretor = corretor; }

    public Cliente getUsuario() { return usuario; }

    public void setUsuario(Cliente usuario) { this.usuario = usuario; }

    public Imovel getImovel() { return imovel; }

    public void setImovel(Imovel imovel) { this.imovel = imovel; }

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

    public boolean efetuarTransacao(){
        corretor.adicionaVendaMes(getValor());
        imovel.setStatus((byte) 3);
        setDataTransacao(new Date());
        return true;
    }
}
