package GUI;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MainMenu implements ActionListener {

    private int count = 0;
    private JLabel label;
    private JPanel panel;
    private JButton btn;
    public MainMenu(){
        JFrame frame = new JFrame();
        label = new JLabel("Número de clicks: 0");



        frame.setSize(300,700);
        frame.add(panel,BorderLayout.CENTER);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("ImobiJava");
        frame.pack();
        frame.setVisible(true);


        panel = new JPanel();
        panel.setBorder(BorderFactory.createEmptyBorder(30,30,10,30));
        panel.setLayout(new GridLayout(0,1));
        panel.add(label);
        panel.add(btn);


        btn = new JButton("Click me");

        btn.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        count++;
        label.setText("Número de clicks: "+count);
    }
}
