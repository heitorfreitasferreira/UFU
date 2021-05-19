package com.company;

import java.util.List;

public class Livro extends  Produto{
    private String editora;

    private List autores;
    public List getAutores() {
        return autores;
    }
    public void setAutor(List autores) {
        autores = autores;
    }

    public Livro(String descricao, float preco, String editora) {
        super(descricao, preco);
        this.editora = editora;
    }

    public String getDescricao() {
        return super.getDescricao() + "\n"+ this.editora ;
    }
}
