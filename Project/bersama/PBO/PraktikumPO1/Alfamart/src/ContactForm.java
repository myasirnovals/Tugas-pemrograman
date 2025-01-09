import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class ContactForm extends JFrame {
    private JTextField namaField;
    private JTextField noHpField;
    private JTextField emailField;
    private JTextArea pesanArea;
    private JButton kirimButton;

    public ContactForm() {
        setTitle("Alfamart");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Header Panel (Red)
        JPanel headerPanel = new JPanel(new BorderLayout());
        headerPanel.setBackground(Color.RED);
        headerPanel.setPreferredSize(new Dimension(800, 60));

        // Logo
        JLabel logoLabel = new JLabel("ALFAMART");
        logoLabel.setForeground(Color.WHITE);
        logoLabel.setFont(new Font("Arial", Font.BOLD, 20));
        logoLabel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 0));

        // Search Panel
        JPanel searchPanel = new JPanel(new BorderLayout());
        searchPanel.setBackground(Color.RED);
        searchPanel.setBorder(BorderFactory.createEmptyBorder(10, 100, 10, 100));

        JTextField searchField = new JTextField("cari produk....");
        JButton searchButton = new JButton("Q");

        searchPanel.add(searchField, BorderLayout.CENTER);
        searchPanel.add(searchButton, BorderLayout.EAST);

        // Cart Button
        JButton cartButton = new JButton("🛒");
        cartButton.setBackground(Color.RED);
        cartButton.setForeground(Color.WHITE);
        cartButton.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 20));

        headerPanel.add(logoLabel, BorderLayout.WEST);
        headerPanel.add(searchPanel, BorderLayout.CENTER);
        headerPanel.add(cartButton, BorderLayout.EAST);

        // Main Content Panel
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        mainPanel.setBackground(Color.WHITE);

        // Title
        JLabel titleLabel = new JLabel("Hubungi Kami");
        titleLabel.setFont(new Font("Arial", Font.BOLD, 24));
        titleLabel.setAlignmentX(Component.LEFT_ALIGNMENT);

        // Form Fields
        namaField = createTextField("Nama");
        noHpField = createTextField("No Hp");
        emailField = createTextField("Email");

        // Pesan TextArea
        JLabel pesanLabel = new JLabel("Pesan");
        pesanLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        pesanArea = new JTextArea();
        pesanArea.setRows(5);
        pesanArea.setLineWrap(true);
        pesanArea.setWrapStyleWord(true);
        JScrollPane scrollPane = new JScrollPane(pesanArea);
        scrollPane.setAlignmentX(Component.LEFT_ALIGNMENT);
        scrollPane.setMaximumSize(new Dimension(Integer.MAX_VALUE, 100));

        // Kirim Button
        kirimButton = new JButton("Kirim");
        kirimButton.setAlignmentX(Component.LEFT_ALIGNMENT);
        kirimButton.setBackground(Color.RED);
        kirimButton.setForeground(Color.WHITE);
        kirimButton.setMaximumSize(new Dimension(100, 30));
        kirimButton.setBorderPainted(false);

        // Add components to main panel
        mainPanel.add(titleLabel);
        mainPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        mainPanel.add(new JLabel("Nama"));
        mainPanel.add(namaField);
        mainPanel.add(Box.createRigidArea(new Dimension(0, 10)));
        mainPanel.add(new JLabel("No Hp"));
        mainPanel.add(noHpField);
        mainPanel.add(Box.createRigidArea(new Dimension(0, 10)));
        mainPanel.add(new JLabel("Email"));
        mainPanel.add(emailField);
        mainPanel.add(Box.createRigidArea(new Dimension(0, 10)));
        mainPanel.add(pesanLabel);
        mainPanel.add(scrollPane);
        mainPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        mainPanel.add(kirimButton);

        // Add panels to frame
        add(headerPanel, BorderLayout.NORTH);
        add(mainPanel, BorderLayout.CENTER);

        // Add action listener for Kirim button
        kirimButton.addActionListener(e -> {
            // Add your submission logic here
            JOptionPane.showMessageDialog(this, "Pesan telah terkirim!");
            clearForm();
        });
    }

    private JTextField createTextField(String placeholder) {
        JTextField field = new JTextField();
        field.setMaximumSize(new Dimension(Integer.MAX_VALUE, 30));
        field.setAlignmentX(Component.LEFT_ALIGNMENT);
        return field;
    }

    private void clearForm() {
        namaField.setText("");
        noHpField.setText("");
        emailField.setText("");
        pesanArea.setText("");
    }
}
