package Imoveis;

import pessoas.Endereco;

import java.util.Date;

public class Apartamento extends Moradia {
    private int andar;
    private float valorCondominio;
    private boolean portaria24h;

    public Apartamento(boolean disponivel, boolean paraVenda, boolean ativo, Date dataConstrucao, Date dataRegistro, float valor, float valorImobiliaria, Endereco endereco, int area, int numQuartos, int numSuites, int numSalaEstar, int numSalaJantar, int numVagasGaragem, int numArmEmbutido, String descricao, boolean condominio, int andar, float valorCondominio, boolean portaria24h) {
        super(disponivel, paraVenda, ativo, dataConstrucao, dataRegistro, valor, valorImobiliaria, endereco, area, numQuartos, numSuites, numSalaEstar, numSalaJantar, numVagasGaragem, numArmEmbutido, descricao, condominio);
        setAndar(andar);
        setValorCondominio(valorCondominio);
        setPortaria24h(portaria24h);
    }

    public int getAndar() {
        return andar;
    }
    public void setAndar(int andar) {
        this.andar = andar;
    }

    public float getValorCondominio() {
        return valorCondominio;
    }
    public void setValorCondominio(float valorCondominio) {
        this.valorCondominio = valorCondominio;
    }

    public boolean isPortaria24h() {
        return portaria24h;
    }
    public void setPortaria24h(boolean portaria24h) {
        this.portaria24h = portaria24h;
    }
}
