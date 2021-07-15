package GUI.Pessoas;

import ManutencaoDados.DadosCorretores;
import ManutencaoDados.DadosFuncionarios;

import javax.swing.*;

public class ListarCorretores {

    private static  JTable jt;
    private static JPanel panel;
    public ListarCorretores(DadosCorretores corretores){
        JFrame frame = new JFrame("Listar Corretores");
        panel = new JPanel();
        frame.add(panel);

        String[] column = {"Nome","Email","Celular","Cargo"};
        String[][] data = corretores.getMatrizCorretores();
        jt = new JTable(data, column);
        JScrollPane sp = new JScrollPane(jt);

        frame.add(sp);
        frame.pack();
        frame.setVisible(true);
    }


}
