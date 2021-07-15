package GUI.Imoveis;

import ManutencaoDados.DadosApartamento;
import ManutencaoDados.DadosCasa;

import javax.swing.*;

public class ListarCasa {
    private static JTable jt;
    private static JPanel panel;

    public ListarCasa(DadosCasa casas){
        JFrame frame = new JFrame("Listar Casas");
        panel = new JPanel();
        frame.add(panel);

        String[] column = {"Para","Data de Construção","Valor Final", "Cidade", "Num Piscinas"};
        String[][] data = casas.getMatrizCasas();
        jt = new JTable(data, column);
        JScrollPane sp = new JScrollPane(jt);

        frame.add(sp);
        frame.pack();
        frame.setVisible(true);
    }
}
