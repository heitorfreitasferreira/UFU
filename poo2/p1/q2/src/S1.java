public class S1 extends Estado {
  public S1(Automato automato) {
    super(automato);
    // System.out.println("S1");
  }

  public void processa(String palavra) {
    if (palavra.isEmpty()) {
      System.out.println("Cadeia não aceita");
      automato.setEstado(new S1(automato));
    } else {
      char x = palavra.charAt(0);
      String xs = palavra.substring(1);
      // System.out.println("cabeça = " + x + " resto = " + xs);

      if (automato.getAlfabeto().indexOf(x) == -1) {
        System.err.println("Simbolo " + x + " fora do alfabeto [" + automato.getAlfabeto() + "]");

      } else if (x == 'a') {
        automato.setEstado(new S2(automato));
        automato.getEstado().processa(xs);
      } else {
        System.out.println("Transição inválida no estado S1");
        automato.setEstado(new S1(automato));
      }
    }
  }
}
