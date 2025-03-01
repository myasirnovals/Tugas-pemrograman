import model.ContactMessage;
import dao.ContactMessageDAO;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.SQLException;

public class ContactForm extends JPanel {
    private JTextField namaField;
    private JTextField noHpField;
    private JTextField emailField;
    private JTextArea pesanArea;
    private JButton kirimButton;
    private ContactMessageDAO messageDAO;

    public ContactForm() {
        messageDAO = new ContactMessageDAO();
        setLayout(new BorderLayout());

        JPanel headerPanel = new JPanel(new BorderLayout());
        headerPanel.setBackground(Color.RED);
        headerPanel.setPreferredSize(new Dimension(800, 60));

        JLabel logoLabel = new JLabel("ALFAMART");
        logoLabel.setForeground(Color.WHITE);
        logoLabel.setFont(new Font("Arial", Font.BOLD, 20));
        logoLabel.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 0));

        JPanel searchPanel = new JPanel(new BorderLayout());
        searchPanel.setBackground(Color.RED);
        searchPanel.setBorder(BorderFactory.createEmptyBorder(10, 100, 10, 100));

        JTextField searchField = new JTextField("cari produk....");
        JButton searchButton = new JButton("Q");

        searchPanel.add(searchField, BorderLayout.CENTER);
        searchPanel.add(searchButton, BorderLayout.EAST);

        JButton cartButton = new JButton("🛒");
        cartButton.setBackground(Color.RED);
        cartButton.setForeground(Color.WHITE);
        cartButton.setBorder(BorderFactory.createEmptyBorder(0, 20, 0, 20));

        headerPanel.add(logoLabel, BorderLayout.WEST);
        headerPanel.add(searchPanel, BorderLayout.CENTER);
        headerPanel.add(cartButton, BorderLayout.EAST);

        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        mainPanel.setBackground(Color.WHITE);

        JPanel navPanel = new JPanel(new GridLayout(1, 4));
        navPanel.setPreferredSize(new Dimension(800, 40));
        navPanel.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.LIGHT_GRAY));

        String[] navItems = {"Produk", "Promosi", "Keranjang", "Hubungi Kami"};
        for (String item : navItems) {
            JButton navButton = new JButton(item);
            navButton.setForeground(Color.BLACK);
            navButton.setBackground(Color.WHITE);
            navButton.setBorderPainted(false);
            navButton.setFocusPainted(false);
            navButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
            navButton.addActionListener(e -> {
                Component comp = this;
                while (!(comp instanceof Main) && comp != null) {
                    comp = comp.getParent();
                }
                if (comp instanceof Main) {
                    ((Main) comp).showCard(item);
                }
            });
            navPanel.add(navButton);
        }

        JPanel headerWithNav = new JPanel(new BorderLayout());
        headerWithNav.add(headerPanel, BorderLayout.NORTH);
        headerWithNav.add(navPanel, BorderLayout.SOUTH);

        JLabel titleLabel = new JLabel("Hubungi Kami");
        titleLabel.setFont(new Font("Arial", Font.BOLD, 24));
        titleLabel.setAlignmentX(Component.LEFT_ALIGNMENT);

        namaField = createTextField("Nama");
        noHpField = createTextField("No Hp");
        emailField = createTextField("Email");

        JLabel pesanLabel = new JLabel("Pesan");
        pesanLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        pesanArea = new JTextArea();
        pesanArea.setRows(5);
        pesanArea.setLineWrap(true);
        pesanArea.setWrapStyleWord(true);
        JScrollPane scrollPane = new JScrollPane(pesanArea);
        scrollPane.setAlignmentX(Component.LEFT_ALIGNMENT);
        scrollPane.setMaximumSize(new Dimension(Integer.MAX_VALUE, 100));

        kirimButton = new JButton("Kirim");
        kirimButton.setAlignmentX(Component.LEFT_ALIGNMENT);
        kirimButton.setBackground(Color.RED);
        kirimButton.setForeground(Color.WHITE);
        kirimButton.setMaximumSize(new Dimension(100, 30));
        kirimButton.setBorderPainted(false);

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

        add(headerWithNav, BorderLayout.NORTH);
        add(mainPanel, BorderLayout.CENTER);

        kirimButton.addActionListener(e -> {
            if (validateInput()) {
                try {
                    ContactMessage message = new ContactMessage(
                            namaField.getText().trim(),
                            noHpField.getText().trim(),
                            emailField.getText().trim(),
                            pesanArea.getText().trim()
                    );

                    if (messageDAO.save(message)) {
                        JOptionPane.showMessageDialog(this,
                                "Pesan berhasil dikirim!",
                                "Sukses",
                                JOptionPane.INFORMATION_MESSAGE);
                        clearForm();
                    }
                } catch (SQLException ex) {
                    JOptionPane.showMessageDialog(this,
                            "Error: " + ex.getMessage(),
                            "Error",
                            JOptionPane.ERROR_MESSAGE);
                }
            }
        });
    }

    private boolean validateInput() {
        if (namaField.getText().trim().isEmpty()) {
            showError("Nama tidak boleh kosong!");
            return false;
        }
        if (pesanArea.getText().trim().isEmpty()) {
            showError("Pesan tidak boleh kosong!");
            return false;
        }
        return true;
    }

    private void showError(String message) {
        JOptionPane.showMessageDialog(this,
                message,
                "Error",
                JOptionPane.ERROR_MESSAGE);
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
