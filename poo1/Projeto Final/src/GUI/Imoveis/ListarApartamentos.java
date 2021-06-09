package GUI.Imoveis;

import ManutencaoDados.DadosApartamento;
import ManutencaoDados.DadosClientes;

import javax.swing.*;

public class ListarApartamentos {
    private static JTable jt;
    private static JPanel panel;
    public ListarApartamentos(DadosApartamento aps){
        JFrame frame = new JFrame("Listar Apartamentos");
        panel = new JPanel();
        frame.add(panel);

        String[] column = {"Para","Data de Construção","Valor Final", "Cidade"};
        String[][] data = aps.getMatrizAps();
        jt = new JTable(data, column);
        JScrollPane sp = new JScrollPane(jt);

        frame.add(sp);
        frame.pack();
        frame.setVisible(true);
    }
}
