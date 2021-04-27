package com.company;
public class Cliente {
    protected float saldo,saldoAplicacao;
    protected String cpf;


    //Construtores
    public Cliente(){
        this.saldo = 0;
        this.saldoAplicacao = 0;
    }
    public Cliente(String cpf){
        this();
        setCpf(cpf);
    }
    public Cliente(float saldo, String cpf) {
        this(cpf);// pq isso ta dando erro?
        deposito(saldo);
    }
    //getters
    public String getCpf() {
        return cpf;
    }
    public float getSaldo() { return saldo; }
    public float getSaldoAplicacao() { return saldoAplicacao; }
    //setters
    public boolean setCpf(String cpf) {
        if (ValidaCPF.isCPF(cpf)){
            this.cpf = cpf;
            return true;
        }
        return false;
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
    public boolean aplicar(float valorAAplicar) {
        if (this.saldo>=1000){
            this.saldo -= valorAAplicar;
            this.saldoAplicacao +=valorAAplicar;
            return true;
        }
        return false;
    }
    public boolean retirarAplicacao(float valorARetirar){
        if(this.saldoAplicacao>=valorARetirar){
            this.saldo+=valorARetirar;
            this.saldoAplicacao-=valorARetirar;
            return true;
        }
        return false;
    }
}
