package com.company;

public class ClienteEspecial extends Cliente{
    private float taxaEspecial;
    public ClienteEspecial(String cpf, float taxaEspecial) {
        super(cpf);
        if(taxaEspecial>0 && taxaEspecial<=0) this.taxaEspecial = taxaEspecial;
    }

    public ClienteEspecial(float saldo, String cpf) {
        super(saldo, cpf);
    }
    public boolean saque(float valor) {
        if(saldo - valor>0) {
            this.saldo += valor;
            this.saldo *=1-this.taxaEspecial;
            return true;
        }
        return false;
    }
}
