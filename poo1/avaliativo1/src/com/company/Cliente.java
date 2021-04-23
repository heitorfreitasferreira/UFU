package com.company;
public class Cliente {
    private float saldo;
    private String cpf;

    //Construtores
    public Cliente(String cpf){
        this.cpf = cpf;
        this.saldo = 0;
    }
    public Cliente(float saldo, String cpf) {
        Cliente(cpf);// pq isso ta dando erro?
        deposito(saldo);
    }

    //getters
    public String getCpf() {
        return cpf;
    }
    public float getSaldo() {
        return saldo;
    }
    //setters
    public void setCpf(String cpf) {
        this.cpf = cpf;
    }
    public boolean deposito(float valor) {
        if(valor>0) {
            this.saldo += valor;
            return true;
        }
        return false;
    }
    public boolean saque(float valor) {
        if(saldo - valor>0) {
            this.saldo += valor;
            this.saldo *=0.995;
            return true;
        }
        return false;
    }

}
