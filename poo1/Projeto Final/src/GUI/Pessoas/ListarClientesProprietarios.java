package GUI.Pessoas;

import ManutencaoDados.DadosClientes;
import ManutencaoDados.DadosClientesProprietarios;

import javax.swing.*;

public class ListarClientesProprietarios {

    private static  JTable jt;
    private static JPanel panel;
    public ListarClientesProprietarios(DadosClientesProprietarios clientes){
        JFrame frame = new JFrame("Listar Clientes Proprietarios");
        panel = new JPanel();
        frame.add(panel);

        String[] column = {"Nome","Email","Celular"};
        String[][] data = clientes.getMatrizClientesProprietarios();
        jt = new JTable(data, column);
        JScrollPane sp = new JScrollPane(jt);

        frame.add(sp);
        frame.pack();
        frame.setVisible(true);
    }


}
