package com.company;

public class Produto {
    public Produto(String descricao, float preco) {
        this.descricao = descricao;
        setPreco(preco);
    }

    private String descricao;
    public String getDescricao() {
        return descricao;
    }

    private String nomeloja;
    public String getNomeloja() {
        return nomeloja;
    }
    public void setNomeloja(String nomeloja) {
        this.nomeloja = nomeloja;
    }

    private float preco;
    public float getPreco() {
        return preco;
    }
    public void setPreco(float preco) {
        this.preco = preco;
    }
}
