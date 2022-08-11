package org.example.composite;

import java.util.List;

public interface Comando {
    //private ArrayList<Comando> comandos = new ArrayList<Comando>();
    public void add(Comando comando);
    public void remove(Comando comando);
    public List<Comando> getComandos();
    public String executar();
    public String getNome();
    public void setNome(String nome);
}
