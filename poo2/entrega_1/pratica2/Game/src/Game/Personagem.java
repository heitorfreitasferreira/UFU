package Game;

// import Atacar.*;
import Correr.*;
import Pular.*;
import Vida.*;
import Vida.Estados.*;

public class Personagem {
  // Strategys
  private PularStategyInterface pulo;
  private CorrerStrategyInterface corrida;

  // States
  private int vida;
  private String nome;

  private VidaInterface estado;

  public Personagem(PularStategyInterface pulo, CorrerStrategyInterface corrida, String nome) {
    setCorrida(corrida);
    setPulo(pulo);
    setNome(nome);
    setVida(71);
    setEstado(new Fraco(this));
  }

  public void setEstado(VidaInterface estado) {
    this.estado = estado;
    estado.lidaAlteracaoVida();
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNome() {
    return nome;
  }

  // ---------------------------------------------------
  // Strategy Pattern
  // ---------------------------------------------------
  // Alteração/Escolha de estratégias
  public void setPulo(PularStategyInterface pulo) {
    this.pulo = pulo;
  }

  public int getVida() {
    return vida;
  }

  public void setVida(int vida) {
    if (vida > 100)
      this.vida = 100;
    else if (vida < 0)
      this.vida = 0;
    else
      this.vida = vida;
  }

  public VidaInterface getEstado() {
    return estado;
  }

  public void curar(int quantidade) {
    this.estado.curar(quantidade);
  }

  public void apanhar(int quantidade) {
    this.estado.apanhar(quantidade);
  }

  public void sobeDesceVida(int quantidade) {
    if (quantidade > 0) {
      this.estado.curar(quantidade);
    } else if (quantidade < 0) {
      this.estado.apanhar(quantidade);
    }
  }

  public void setCorrida(CorrerStrategyInterface corrida) {
    this.corrida = corrida;
  }

  // Comportamentos do Personagem (Strategys)
  public String pulo() {
    return pulo.pulo();
  }

  public String correr() {
    return corrida.correr();
  }
}
