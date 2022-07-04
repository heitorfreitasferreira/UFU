public abstract class Estado {
  protected Automato automato;

  public Estado(Automato automato) {
    this.automato = automato;
  }

  public abstract void processa(String palavra);
}
