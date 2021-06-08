package GUI.Pessoas;

import Pessoas.Cliente;
import Pessoas.Endereco;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CadastroCliente{
    private static JPanel panel;
    private static JTextField tfCpf,tfNome,tfCelular, tfTelFixo,tfEmail, tfRua, tfComplemento, tfCep, tfCidade, tfBairro, tfNro,tfProfissao,tfEstadoCivil;
    private static JCheckBox cbMulher;
    private static JButton btnSubmit,btnMenu;
    private static JLabel lCpf,lNome,lCelular,lTelFixo,lEmail,lRua,lComplemento,lCep,lCidade,lMulher,lBairro,lNro,lProfissao,lEstadoCivil;
    private static JRadioButton rbHomem, rbMulher;
    private static JComboBox cbEstadoCivil;
    public CadastroCliente(){
        JFrame frame = new JFrame();
        panel = new JPanel();
        panel.setLayout(null);
        frame.setTitle("Cadastro Cliente");
        frame.setSize(400,530);
        frame.add(panel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

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

        lProfissao = new JLabel("Profissão: ");
        lProfissao.setBounds(10,390,150,25);
        tfProfissao = new JTextField(20);
        tfProfissao.setBounds(150,390,150,25);
        panel.add(lProfissao);
        panel.add(tfProfissao);



        String[] estCivil = {"Solteiro(a)", "Casado(a)", "Separado(a)", "Viúvo(a)", "Outro"};
        cbEstadoCivil = new JComboBox(estCivil);
        cbEstadoCivil.setBounds(10,420,150,25);
        panel.add(cbEstadoCivil);


         btnMenu = new JButton("Menu");
         btnMenu.setBounds(10,460,150,30);
         panel.add(btnMenu);
         btnMenu.addActionListener(new ActionListener() {
             @Override
             public void actionPerformed(ActionEvent e) {

             }
         });


        btnSubmit = new JButton("Cadastrar");
        btnSubmit.setBounds(180,460,150,30);
        panel.add(btnSubmit);
        btnSubmit.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                Endereco end = new Endereco(tfRua.getText(),tfComplemento.getText(),tfCep.getText(),tfCidade.getText(),tfBairro.getText(),Integer.parseInt(tfNro.getText()));
                Cliente c = new Cliente(tfCpf.getText(),tfNome.getText(),tfCelular.getText(),tfTelFixo.getText(),tfEmail.getText(),cbEstadoCivil.getSelectedItem().toString(),rbMulher.isSelected(),end,tfProfissao.getText());

            }
        });

//        panel.setBorder(BorderFactory.createEmptyBorder(30,30,10,30));



         frame.setVisible(true);
    }



}
