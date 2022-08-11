package org.example.composite;

import java.util.ArrayList;
import java.util.Collections;

public class CComposto implements Comando{


    ArrayList<Comando> comandos;

    public CComposto(ArrayList<Comando> comandos){
        this.comandos = comandos;
    }
    public CComposto(Comando... comandos){
        this.comandos = new ArrayList<>();
        Collections.addAll(this.comandos, comandos);
    }
    public void add(Comando comando) {
        comandos.add(comando);
    }

    public void remove(Comando comando) {
        comandos.remove(comando);
    }

    public ArrayList<Comando> getComandos() {
        return null;
    }

    public String executar() {
        StringBuilder sb = new StringBuilder();
        for (Comando comando : comandos) {
            sb.append("\t").append(comando.executar());
        }
        return sb.toString();
    }

    public String getNome() {
        return "";
    }


    public void setNome(String nome) {

    }
}
