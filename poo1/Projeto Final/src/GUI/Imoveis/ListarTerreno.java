package GUI.Imoveis;

import ManutencaoDados.DadosCasa;
import ManutencaoDados.DadosTerrenos;

import javax.swing.*;

public class ListarTerreno {
    private static JTable jt;
    private static JPanel panel;

    public ListarTerreno(DadosTerrenos terrenos){
        JFrame frame = new JFrame("Listar Terrenos");
        panel = new JPanel();
        frame.add(panel);

        String[] column = {"Para","Data de Construção","Valor Final", "Cidade", "Possui Aclive"};
        String[][] data = terrenos.getMatrizTerrenos();
        jt = new JTable(data, column);
        JScrollPane sp = new JScrollPane(jt);

        frame.add(sp);
        frame.pack();
        frame.setVisible(true);
    }
}
