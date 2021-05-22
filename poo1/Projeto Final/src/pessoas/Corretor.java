package pessoas;

import java.util.Date;

public class Corretor extends Funcionario{

    private boolean formadoVendas;
    Date dataInicioCorretagem;
    float salarioFinal;

    public Corretor(String cpf, String nome, String celular, String telFixo, String email, String estCivil, boolean mulher, Endereco endereco, String cargo, String usuario, String senha, Date dataIngressoEmpresa, boolean mulher1, float salario, boolean formadoVendas, Date dataInicioCorretagem, float salarioFinal) {
        super(cpf, nome, celular, telFixo, email, estCivil, mulher, endereco, cargo, usuario, senha, dataIngressoEmpresa, mulher1, salario);
        setFormadoVendas(formadoVendas);
        setDataInicioCorretagem(dataInicioCorretagem);
        setSalarioFinal(salarioFinal);
    }

    public boolean isFormadoVendas() {
        return formadoVendas;
    }

    public void setFormadoVendas(boolean formadoVendas) {
        this.formadoVendas = formadoVendas;
    }

    public Date getDataInicioCorretagem() {
        return dataInicioCorretagem;
    }

    public void setDataInicioCorretagem(Date dataInicioCorretagem) {
        this.dataInicioCorretagem = dataInicioCorretagem;
    }

    public float getSalarioFinal() {
        return salarioFinal;
    }

    public void setSalarioFinal(float salarioFinal) {
        this.salarioFinal = salarioFinal;
    }
}
