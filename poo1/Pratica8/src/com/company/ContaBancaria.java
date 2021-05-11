package com.company;

public abstract class ContaBancaria implements Imprimivel{
    protected double saldo;
    protected int num;
    ContaBancaria (double saldo, int numeroConta){
        this.saldo = saldo;
        setNum(numeroConta);
    }
    public abstract boolean sacar(double valor);
    public abstract boolean depositar(double valor);

    public double getSaldo() {
        return saldo;
    }

    public int getNumeroConta() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public void mostrarDados(){
        System.out.println("Conta numero: " + getNumeroConta());
        System.out.println("Saldo: " + getSaldo());
    }
}
