package GUI.Pessoas;

import ManutencaoDados.DadosClientes;

import javax.swing.*;

public class ListarClientes {

    private static  JTable jt;
    private static JPanel panel;
    public ListarClientes(DadosClientes clientes){
        JFrame frame = new JFrame("Listar Clientes");
        panel = new JPanel();
        frame.add(panel);

        String[] column = {"Nome","Email","Celular"};
        String[][] data = clientes.getMatrizClientes();
        jt = new JTable(data, column);
        JScrollPane sp = new JScrollPane(jt);

        frame.add(sp);
        frame.pack();
        frame.setVisible(true);
    }


}
