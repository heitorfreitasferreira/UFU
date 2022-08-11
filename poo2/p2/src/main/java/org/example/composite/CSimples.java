package org.example.composite;

import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;

public class CSimples implements Comando{

    private String nome;

    public CSimples(String nome){
        setNome(nome);
    }

    public void add(Comando comando) {

    }

    public void remove(Comando comando) {

    }

    public ArrayList<Comando> getComandos() {
        return new ArrayList<>();
    }

    public String executar() {
        return getNome()+"\n";
    }

    public String getNome() {
        return nome;
    }

    @Override
    public void setNome(@NotNull String nome) {
        this.nome = nome.toLowerCase();
    }
}
