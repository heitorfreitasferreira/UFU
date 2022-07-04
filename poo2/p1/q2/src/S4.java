public class S4 extends Estado {
  public S4(Automato automato) {
    super(automato);
    // System.out.println("S4");
  }

  public void processa(String palavra) {

    if (palavra.isEmpty()) {
      System.out.println("Cadeia ACEITA");
      automato.setEstado(new S1(automato));
    } else {
      char x = palavra.charAt(0);
      String xs = palavra.substring(1);
      // System.out.println("cabeça = " + x + " resto = " + xs);

      if (automato.getAlfabeto().indexOf(x) == -1) {
        System.err.println("Simbolo " + x + " fora do alfabeto [" + automato.getAlfabeto() + "]");

      } else if (x == 'd') {
        automato.setEstado(new S3(automato));
        automato.getEstado().processa(xs);
      } else {
        System.out.println("Transição inválida no estado S4");
      }
    }
  }
}
