package GUI.Pessoas;

import ManutencaoDados.DadosClientesProprietarios;
import ManutencaoDados.DadosFuncionarios;

import javax.swing.*;

public class ListarFuncionarios {

    private static  JTable jt;
    private static JPanel panel;
    public ListarFuncionarios(DadosFuncionarios funcionarios){
        JFrame frame = new JFrame("Listar Funcionarios");
        panel = new JPanel();
        frame.add(panel);

        String[] column = {"Nome","Email","Celular","Cargo"};
        String[][] data = funcionarios.getMatrizFuncionarios();
        jt = new JTable(data, column);
        JScrollPane sp = new JScrollPane(jt);

        frame.add(sp);
        frame.pack();
        frame.setVisible(true);
    }


}
