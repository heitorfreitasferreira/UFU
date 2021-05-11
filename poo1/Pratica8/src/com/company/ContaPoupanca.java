package com.company;

public class ContaPoupanca extends ContaBancaria {
    private double limite;

    public ContaPoupanca(double saldo, int numConta, double limite) {
        super(saldo,numConta);
        setLimite(limite);
    }

    public boolean sacar(double valor) {
        if (getSaldo()+getLimite()>=valor) {
            this.saldo -= valor;
            return true;
        }
        return false;
    }

    public boolean depositar(double valor) {
        this.saldo += valor;
        return true;
    }

    public double getLimite() {
        return limite;
    }

    public void setLimite(double limite) {
        this.limite = limite;
    }


    public void mostrarDados(){
        System.out.println("Tipo de conta: Conta Poupanca");
        super.mostrarDados();
        System.out.println("Limite: " + getLimite());
    }
}