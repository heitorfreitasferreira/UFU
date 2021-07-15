package com.company;

import com.company.Funcionario;

public class Vendedor extends Funcionario {
    float comissaoAcum;
    //CONSTRUCTOR-------------------------------------
    public Vendedor() {
        this.comissaoAcum = 0;
        setSalarioBase(1000);
    }
    //GETTER SETTER-----------------------------------
    public float getComissaoAcum() {
        return comissaoAcum;
    }
    //------------------------------------------------
    public void attComissao(int valorVenda) { this.comissaoAcum += valorVenda * 0.05; }
    public void resetComissaoAcum() { this.comissaoAcum = 0; }
}