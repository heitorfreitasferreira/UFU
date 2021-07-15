package com.company;

public class ContaCorrente extends ContaBancaria{
    private double taxaDeOperacao;
    public ContaCorrente(double saldo, int numConta, double taxaDeOperacao){
        super(saldo,numConta);
        setTaxaDeOperacao(taxaDeOperacao);
    }
    public boolean sacar(double valor){
        if (valor + this.taxaDeOperacao <= getSaldo()){
            this.saldo = (this.saldo - valor) - this.taxaDeOperacao;
            return true;
        }
        return false;
    }
    public boolean depositar(double valor){
        if (getSaldo()+valor>=getTaxaDeOperacao()){
            this.saldo = this.saldo + valor - this.taxaDeOperacao;
            return true;
        }
        else return false;
    }

    public double getTaxaDeOperacao() {
        return taxaDeOperacao;
    }

    public void setTaxaDeOperacao(double taxaDeOperacao) {
        this.taxaDeOperacao = taxaDeOperacao;
    }
    public void mostrarDados(){

        System.out.println("Tipo de conta: Conta Corrente");
        super.mostrarDados();
        System.out.println("Taxa de operacao: " + this.taxaDeOperacao);
    }
}
