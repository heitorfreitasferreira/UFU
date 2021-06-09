package GUI.Pessoas;

import ManutencaoDados.DadosClientes;
import ManutencaoDados.DadosCorretores;
import Pessoas.Cliente;
import Pessoas.Endereco;
import Pessoas.Corretor;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Date;

public class CadastroCorretor{
    private static JPanel panel;
    private static JTextField tfCpf,tfNome,tfCelular, tfTelFixo,tfEmail, tfRua, tfComplemento, tfCep, tfCidade, tfBairro, tfNro,tfCargo,tfUsuario,tfAnoCorretagem;
    private static JCheckBox cbFormadoEmVendas;
    private static JButton btnSubmit,btnMenu;
    private static JLabel lCpf,lNome,lCelular,lTelFixo,lEmail,lRua,lComplemento,lCep,lCidade,lBairro,lNro,lCargo,lUsuario,lSenha,lAnoCorretagem;
    private static JPasswordField pfSenha;
    private static JRadioButton rbHomem, rbMulher;
    private static JComboBox cbEstadoCivil;
    public CadastroCorretor(DadosCorretores corretores){
        JFrame frame = new JFrame();
        panel = new JPanel();
        panel.setLayout(null);
        frame.setTitle("Cadastro Corretor");
        frame.setSize(400,700);
        frame.add(panel);
//        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        //Criando objetos text field

        lNome = new JLabel("Nome: ");
        lNome.setBounds(10,20,80,25);
        tfNome = new JTextField(20);
        tfNome.setBounds(150,20,200,25);
        panel.add(lNome);
        panel.add(tfNome);


        lEmail = new JLabel("Email: ");
        lEmail.setBounds(10,50,80,25);
        tfEmail = new JTextField(20);
        tfEmail.setBounds(150,50,200,25);
        panel.add(lEmail);
        panel.add(tfEmail);

        lCpf = new JLabel("CPF: ");
        lCpf.setBounds(10,80,80,25);
        tfCpf = new JTextField(20);
        tfCpf.setBounds(150,80,100,25);
        panel.add(lCpf);
        panel.add(tfCpf);

        lCelular = new JLabel("Celular: ");
        lCelular.setBounds(10,110,80,25);
        tfCelular = new JTextField(20);
        tfCelular.setBounds(150,110,100,25);
        panel.add(lCelular);
        panel.add(tfCelular);


        lTelFixo = new JLabel("Fixo: ");
        lTelFixo.setBounds(10,140,80,25);
        tfTelFixo = new JTextField(20);
        tfTelFixo.setBounds(150,140,100,25);
        panel.add(lTelFixo);
        panel.add(tfTelFixo);



        // Create Radio buttons
        ButtonGroup bgMulher = new ButtonGroup();
        rbHomem = new JRadioButton("Homem", true);
        rbHomem.setBounds(10,170,80,25);
        rbMulher = new JRadioButton("Mulher", false);
        rbMulher.setBounds(100,170,80,25);
        bgMulher.add(rbMulher);
        bgMulher.add(rbHomem);

        panel.add(rbHomem);
        panel.add(rbMulher);


//        lMulher = new JLabel("Mulher: ");
//        lMulher.setBounds(10,170,80,25);
//        cbMulher = new JCheckBox("Mulher");
//        cbMulher.setBounds(10,170,150,25);
//        panel.add(lMulher);



        lCidade = new JLabel("Cidade: ");
        lCidade.setBounds(10,200,80,25);
        tfCidade = new JTextField(20);
        tfCidade.setBounds(150,200,200,25);
        panel.add(lCidade);
        panel.add(tfCidade);


        lBairro = new JLabel("Bairro: ");
        lBairro.setBounds(10,230,80,25);
        tfBairro = new JTextField(20);
        tfBairro.setBounds(150,230,200,25);
        panel.add(lBairro);
        panel.add(tfBairro);

        lRua = new JLabel("Rua: ");
        lRua.setBounds(10,260,80,25);
        tfRua = new JTextField(20);
        tfRua.setBounds(150,260,200,25);
        panel.add(lRua);
        panel.add(tfRua);

        lNro = new JLabel("Número: ");
        lNro.setBounds(10,290,80,25);
        tfNro = new JTextField(20);
        tfNro.setBounds(150,290,50,25);
        panel.add(lNro);
        panel.add(tfNro);

        lCep = new JLabel("CEP: ");
        lCep.setBounds(10,320,150,25);
        tfCep = new JTextField(20);
        tfCep.setBounds(150,320,50,25);
        panel.add(lCep);
        panel.add(tfCep);

        lComplemento = new JLabel("Complemento: ");
        lComplemento.setBounds(10,350,150,25);
        tfComplemento = new JTextField(20);
        tfComplemento.setBounds(150,350,150,25);
        panel.add(lComplemento);
        panel.add(tfComplemento);

        lCargo = new JLabel("Cargo: ");
        lCargo.setBounds(10,390,150,25);
        tfCargo = new JTextField(20);
        tfCargo.setBounds(150,390,150,25);
        panel.add(lCargo);
        panel.add(tfCargo);


        lUsuario = new JLabel("Usuário: ");
        lUsuario.setBounds(10,430,150,25);
        tfUsuario = new JTextField(20);
        tfUsuario.setBounds(150,430,150,25);
        panel.add(lUsuario);
        panel.add(tfUsuario);

        lSenha = new JLabel("Senha: ");
        lSenha.setBounds(10,460,150,25);
        pfSenha = new JPasswordField(20);
        pfSenha.setBounds(150,460,150,25);
        panel.add(lSenha);
        panel.add(pfSenha);



        String[] estCivil = {"Solteiro(a)", "Casado(a)", "Separado(a)", "Viúvo(a)", "Outro"};
        cbEstadoCivil = new JComboBox(estCivil);
        cbEstadoCivil.setBounds(10,500,150,25);
        panel.add(cbEstadoCivil);

        lAnoCorretagem = new JLabel("Ano de início de corretagem: ");
        lAnoCorretagem.setBounds(10,540,230,25);
        tfAnoCorretagem = new JTextField(20);
        tfAnoCorretagem.setBounds(250,540,50,25);
        panel.add(lAnoCorretagem);
        panel.add(tfAnoCorretagem);


        cbFormadoEmVendas = new JCheckBox("Formado em vendas");
        cbFormadoEmVendas.setBounds(10,570,300,25);
        panel.add(cbFormadoEmVendas);

        btnSubmit = new JButton("Cadastrar");
        btnSubmit.setBounds(180,600,150,30);
        panel.add(btnSubmit);
        btnSubmit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Endereco end = new Endereco(tfRua.getText(),tfComplemento.getText(),tfCep.getText(),tfCidade.getText(),tfBairro.getText(),Integer.parseInt(tfNro.getText()));
                Date hoje = new Date();
                Date inicioCorretagem = new Date();
                inicioCorretagem.setMonth(1);
                inicioCorretagem.setDate(1);
                String temp = tfAnoCorretagem.getText();
                inicioCorretagem.setYear(Integer.parseInt(temp));
                Corretor f = new Corretor(tfCpf.getText(),tfNome.getText(),tfCelular.getText(),tfTelFixo.getText(),tfEmail.getText(),cbEstadoCivil.getSelectedItem().toString(),rbMulher.isSelected(),end,tfCargo.getText(),tfUsuario.getText(),pfSenha.getText(),hoje,cbFormadoEmVendas.isSelected(),inicioCorretagem);
                corretores.adicionar(f);
                frame.dispose();
            }
        });

        panel.setBorder(BorderFactory.createEmptyBorder(30,30,30,30));



        frame.setVisible(true);
    }

}
