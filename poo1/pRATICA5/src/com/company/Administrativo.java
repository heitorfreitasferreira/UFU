package com.company;

import com.company.Funcionario;

public class Administrativo extends Funcionario {
    int horaExtraAcum;
    //CONSTRUCTOR-------------------------------------
    public Administrativo(){
        this.horaExtraAcum = 0;
        setSalarioBase(1000);
    }
    //GETTER SETTER-----------------------------------
    public int getHoraExtraAcum() {
        return horaExtraAcum;
    }
    public float getsalarioBonus(){
        return horaExtraAcum * (this.getSalarioBase()/100);
    }
    //------------------------------------------------
    public void attHoraExtraAcum(int horaExtra){
        this.horaExtraAcum+=horaExtra;
    }
    public void resethoraExtraAcum(){
        this.horaExtraAcum = 0;
    }

}