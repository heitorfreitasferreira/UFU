package pessoas;

import java.util.Date;

public class Funcionario extends Pessoa{
    String cargo,usuario,senha;
    Date dataIngressoEmpresa;
    float salario;

    public Funcionario(String cpf, String nome, String celular, String telFixo, String email, String estCivil, boolean mulher, Endereco endereco, String cargo, String usuario, String senha, Date dataIngressoEmpresa, boolean mulher1, float salario) {
        super(cpf, nome, celular, telFixo, email, estCivil, mulher, endereco);
        setCargo(cargo);
        setUsuario(usuario);
        setSenha(senha);
        setDataIngressoEmpresa(dataIngressoEmpresa);
        setSalario(salario);
    }

    public String getCargo() {
        return cargo;
    }

    public void setCargo(String cargo) {
        this.cargo = cargo;
    }

    public String getUsuario() {
        return usuario;
    }

    public void setUsuario(String usuario) {
        this.usuario = usuario;
    }

    public boolean compareSenha(String inputSenha) {
        if(inputSenha == this.senha) return true;
        return false;
    }

    public boolean setSenha(String senha) {
        if (senha.length()>=6) {
            this.senha = senha;
            return true;
        }
        return false;
    }

    public Date getDataIngressoEmpresa() {
        return dataIngressoEmpresa;
    }

    public void setDataIngressoEmpresa(Date dataIngressoEmpresa) {
        this.dataIngressoEmpresa = dataIngressoEmpresa;
    }

    public float getSalario() {
        return salario;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }
}
