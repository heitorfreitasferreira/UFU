public class Aluno {
    private String nome, numMatricula;
    private Curso curso;
    public Aluno(Curso curso){
        this.curso = curso;
    }
    public Aluno(){
    }
    public Curso getCurso() {
        return curso;
    }

    public String getNome() {
        return nome;
    }

    public String getNumMatricula() {
        return numMatricula;
    }

    public void setCurso(Curso curso) {
        this.curso = curso;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setNumMatricula(String numMatricula) {
        this.numMatricula = numMatricula;
    }

}
