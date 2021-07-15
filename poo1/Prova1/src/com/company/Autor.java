package com.company;

import java.util.List;

public class Autor {
    private String nome;
    private String CPF;

    private List livros;
    public List getLivros() {
        return livros;
    }
    public void setLivros(List livros) {
        this.livros = livros;
    }

    public Autor(String nome, String CPF) {
        this.nome = nome;
        this.CPF = CPF;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getCPF() {
        return CPF;
    }

    public void setCPF(String CPF) {
        this.CPF = CPF;
    }
}
