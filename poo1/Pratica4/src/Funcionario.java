public class Funcionario {
    private String nome, endereco, telefone,cpf,numeroCTPS;
    private float salario;

    public String getNome() {
        return nome;
    }

    public String getEndereco() {
        return endereco;
    }

    public String getTelefone() {
        return telefone;
    }

    public String getCpf() {
        return cpf;
    }

    public String getNumeroCTPS() {
        return numeroCTPS;
    }

    public float getSalario() {
        return salario;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setEndereco(String endereco) {
        this.endereco = endereco;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    }

    public void setCpf(String cpf) {
        this.cpf = cpf;
    }

    public void setNumeroCTPS(String numeroCTPS) {
        this.numeroCTPS = numeroCTPS;
    }

    public void setSalario(float salario) {
        this.salario = salario;
    }
}
