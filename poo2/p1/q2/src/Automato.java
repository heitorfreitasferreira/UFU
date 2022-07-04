public class Automato {
  private String alfabeto;
  private Estado estado;

  // #region Construtores getters e setters
  public Automato(String alfabeto) {
    setAlfabeto(alfabeto);
    setEstado(new S1(this));
  }

  public String getAlfabeto() {
    return alfabeto;
  }

  public void setAlfabeto(String alfabeto) {
    this.alfabeto = alfabeto;
  }

  public Estado getEstado() {
    return estado;
  }

  public void setEstado(Estado estado) {
    this.estado = estado;
  }
  // #endregion Construtores getters e setters

  public void processa(String palavra) {
    estado.processa(palavra);
  }
}
