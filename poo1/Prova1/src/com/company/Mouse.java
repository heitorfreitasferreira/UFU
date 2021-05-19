package com.company;

public class Mouse extends Produto{
    private String tipo;

    public Mouse(String descricao, float preco, String tipo) {
        super(descricao, preco);
        this.tipo = tipo;
    }
    public String getDescricao() {
        return super.getDescricao() + "\n"+ this.tipo ;
    }
}
