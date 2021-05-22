package com.company;

public class Contato {
    private String nome,sexo,profissão,telefone, email;
    private int idade;

    public Contato(String nome, int idade, String sexo, String profissão, String telefone, String email) {
        this.nome = nome;
        this.idade = idade;
        this.sexo = sexo;
        this.profissão = profissão;
        this.telefone = telefone;
        this.email = email;
    }

    public String getNome() {
        return nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }
    public int getIdade() {
        return idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }
    public String getSexo() {
        return sexo;
    }
    public void setSexo(String sexo) {
        this.sexo = sexo;
    }
    public String getProfissão() {
        return profissão;
    }
    public void setProfissão(String profissão) {
        this.profissão = profissão;
    }
    public String getTelefone() {
        return telefone;
    }
    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        this.email = email;
    }

    public String toString(){
        return getNome() + ", "+getIdade()+" anos de idade, do sexo "+getSexo()+","+getProfissão()+", telefone n.º "+getTelefone()+",e-mail:"+getEmail()+"";
    }
}
