package Imoveis;

import pessoas.Endereco;

import java.util.Date;

public class Imovel {
    private boolean disponivel,paraVenda,ativo;
    private Date dataConstrucao,dataRegistro;
    private float valor,valorImobiliaria;
    private Endereco endereco;
    private int area;


    public Imovel(boolean disponivel, boolean paraVenda, boolean ativo, Date dataConstrucao, Date dataRegistro, float valor, float valorImobiliaria, Endereco endereco,int area) {
        setDisponivel(disponivel);
        setParaVenda(paraVenda);
        setAtivo(ativo);
        setDataConstrucao(dataConstrucao);
        setDataRegistro(dataRegistro);
        setValor(valor);
        setValorImobiliaria(valorImobiliaria);
        setEndereco(endereco);
        setArea(area);
    }

    public int getArea() {
        return area;
    }

    public void setArea(int area) {
        this.area = area;
    }

    public boolean isDisponivel() {
        return disponivel;
    }
    public Endereco getEndereco() {
        return endereco;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }
    public void setDisponivel(boolean disponivel) {
        this.disponivel = disponivel;
    }

    public boolean isParaVenda() {
        return paraVenda;
    }

    public void setParaVenda(boolean paraVenda) {
        this.paraVenda = paraVenda;
    }

    public boolean isAtivo() {
        return ativo;
    }

    public void setAtivo(boolean ativo) {
        this.ativo = ativo;
    }

    public Date getDataConstrucao() {
        return dataConstrucao;
    }

    public void setDataConstrucao(Date dataConstrucao) {
        this.dataConstrucao = dataConstrucao;
    }

    public Date getDataRegistro() {
        return dataRegistro;
    }

    public void setDataRegistro(Date dataRegistro) {
        this.dataRegistro = dataRegistro;
    }

    public float getValor() {
        return valor;
    }

    public void setValor(float valor) {
        this.valor = valor;
    }

    public float getValorImobiliaria() {
        return valorImobiliaria;
    }

    public void setValorImobiliaria(float valorImobiliaria) {
        this.valorImobiliaria = valorImobiliaria;
    }
}
