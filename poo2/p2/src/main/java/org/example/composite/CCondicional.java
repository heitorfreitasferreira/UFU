package org.example.composite;

import java.util.ArrayList;

public class CCondicional implements Comando{
    ArrayList<Comando> comandos;
    public CCondicional(Comando comando1, Comando comando2){
        this.comandos = new ArrayList<>();
        this.comandos.add(comando1);
        this.comandos.add(comando2);
    }
    @Override
    public void add(Comando comando) {
        this.comandos = new ArrayList<>();
        this.comandos.add(comando);
    }

    @Override
    public void remove(Comando comando) {
        if(this.comandos.contains(comando) && this.comandos.size() == 2){
            this.comandos.remove(comando);
        }
    }

    @Override
    public ArrayList<Comando> getComandos() {
        return this.comandos;
    }

    @Override
    public String executar() {
        if(Math.random() > 0.5) {
            return "Condicional verdadeiro\n" + this.comandos.get(0).executar();
        }
        else {
            return "Condicional falso\n" + this.comandos.get(1).executar();
        }
    }

    public String getNome() {
        return "";
    }

    public void setNome(String nome) {

    }
}
