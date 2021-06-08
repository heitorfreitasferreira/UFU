package GUI;

import GUI.Pessoas.CadastroCliente;
import ManutencaoDados.DadosClientes;
import Pessoas.Cliente;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainMenu {
    private static JLabel label;
    private static JPanel panel;
    private static JButton btnCadastroCliente,btnCadastroFuncionario,btnCadastroCasa,btnCadastroApartamento,btnCadastroTerreno;
    //Telas
    private static CadastroCliente tlCadastroCliente;
    private static DadosClientes clientes;

    public MainMenu(){
        clientes = new DadosClientes();
        JFrame frame = new JFrame();

        panel = new JPanel();


        frame.setSize(310,700);
        frame.add(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("ImobiJava");
        frame.setVisible(true);

        panel.setBorder(BorderFactory.createEmptyBorder(30,30,10,30));
        panel.setLayout(null);

        label = new JLabel("Menu");
        label.setBounds(10,0,290,60);
        panel.add(label);

        btnCadastroCliente = new JButton("Cadastrar Cliente");
        btnCadastroCliente.setBounds(10,70,290,60);
        panel.add(btnCadastroCliente);
        btnCadastroCliente.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                tlCadastroCliente = new CadastroCliente(clientes);
            }
        });

        btnCadastroFuncionario = new JButton("Cadastrar Funcionário");
        btnCadastroFuncionario.setBounds(10,140,290,60);
        panel.add(btnCadastroFuncionario);


        btnCadastroApartamento = new JButton("Cadastrar Apartamento");
        btnCadastroApartamento.setBounds(10,210,290,60);
        panel.add(btnCadastroApartamento);

    }

}
