package Imoveis;

import pessoas.Endereco;

import java.util.Date;

public class Casa extends Moradia{
    private int numPiscinas;

    public Casa(boolean disponivel, boolean paraVenda, boolean ativo, Date dataConstrucao, Date dataRegistro, float valor, float valorImobiliaria, Endereco endereco, int area, int numQuartos, int numSuites, int numSalaEstar, int numSalaJantar, int numVagasGaragem, int numArmEmbutido, String descricao, boolean condominio, boolean condominio1, int numPiscinas) {
        super(disponivel, paraVenda, ativo, dataConstrucao, dataRegistro, valor, valorImobiliaria, endereco, area, numQuartos, numSuites, numSalaEstar, numSalaJantar, numVagasGaragem, numArmEmbutido, descricao, condominio);

        setNumPiscinas(numPiscinas);
    }

    public int getNumPiscinas() {
        return numPiscinas;
    }
    public void setNumPiscinas(int numPiscinas) {
        this.numPiscinas = numPiscinas;
    }
}
