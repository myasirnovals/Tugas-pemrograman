import javax.swing.*;
import java.awt.*;

public class AlfamartECommerce extends JPanel {
    public AlfamartECommerce() {
        setLayout(new BorderLayout());

        // Header Panel
        JPanel headerPanel = new JPanel(new BorderLayout());
        headerPanel.setBackground(Color.RED);
        headerPanel.setPreferredSize(new Dimension(800, 100));

        JLabel titleLabel = new JLabel("Alfamart E-Commerce", SwingConstants.CENTER);
        titleLabel.setForeground(Color.WHITE);
        titleLabel.setFont(new Font("Arial", Font.BOLD, 24));

        JLabel subtitleLabel = new JLabel("Belanja Mudah dan Cepat!", SwingConstants.CENTER);
        subtitleLabel.setForeground(Color.WHITE);
        subtitleLabel.setFont(new Font("Arial", Font.PLAIN, 16));

        JPanel titlePanel = new JPanel(new GridLayout(2, 1));
        titlePanel.setBackground(Color.RED);
        titlePanel.add(titleLabel);
        titlePanel.add(subtitleLabel);

        headerPanel.add(titlePanel, BorderLayout.CENTER);
        add(headerPanel, BorderLayout.NORTH);

        // Navigation Panel
        JPanel navPanel = new JPanel(new GridLayout(1, 4));
        navPanel.setPreferredSize(new Dimension(800, 40));
        navPanel.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.LIGHT_GRAY));

        // Ubah bagian Navigation Panel (sekitar baris ke-31):
        String[] navItems = {"Produk", "Promosi", "Keranjang", "Hubungi Kami"};
        for (String item : navItems) {
            JButton navButton = new JButton(item);
            navButton.setForeground(Color.BLACK);
            navButton.setBackground(Color.WHITE);
            navButton.setBorderPainted(false);
            navButton.setFocusPainted(false);
            navButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
            // Tambahkan ActionListener untuk navigasi
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

        // Main Content Panel yang membungkus navPanel dan contentPanel
        JPanel mainPanel = new JPanel(new BorderLayout());
        mainPanel.add(navPanel, BorderLayout.NORTH);

        // Content Panel untuk Produk
        JPanel contentPanel = new JPanel();
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));
        contentPanel.setBackground(Color.WHITE);

        // Padding untuk konten
        contentPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        // Product panels
        for (int i = 0; i < 2; i++) {
            JPanel productPanel = createProductPanel(
                    "Nama Produk",
                    "Deskripsi singkat produk.",
                    "Rp " + (i == 0 ? "20.000" : "15.000")
            );
            contentPanel.add(productPanel);
            contentPanel.add(Box.createRigidArea(new Dimension(0, 10)));
        }

        JScrollPane scrollPane = new JScrollPane(contentPanel);
        scrollPane.setBorder(null);
        mainPanel.add(scrollPane, BorderLayout.CENTER);

        add(mainPanel, BorderLayout.CENTER);

        // Footer Panel
        JPanel footerPanel = new JPanel();
        footerPanel.setBackground(new Color(51, 51, 51));
        footerPanel.setPreferredSize(new Dimension(800, 30));
        JLabel footerLabel = new JLabel("© 2025 Alfamart E-Commerce. Semua Hak Dilindungi.");
        footerLabel.setForeground(Color.WHITE);
        footerPanel.add(footerLabel);
        add(footerPanel, BorderLayout.SOUTH);
    }

    private JPanel createProductPanel(String name, String description, String price) {
        JPanel panel = new JPanel(new BorderLayout(10, 0));
        panel.setMaximumSize(new Dimension(750, 100));
        panel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        panel.setBackground(Color.WHITE);

        // Image Panel
        JPanel imagePanel = new JPanel();
        imagePanel.setPreferredSize(new Dimension(100, 100));
        imagePanel.setBackground(Color.LIGHT_GRAY);
        JLabel imageLabel = new JLabel("100 x 100");
        imageLabel.setForeground(Color.GRAY);
        imagePanel.add(imageLabel);
        panel.add(imagePanel, BorderLayout.WEST);

        // Info Panel
        JPanel infoPanel = new JPanel();
        infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));
        infoPanel.setBackground(Color.WHITE);

        JLabel nameLabel = new JLabel(name);
        nameLabel.setFont(new Font("Arial", Font.BOLD, 14));
        JLabel descLabel = new JLabel(description);
        descLabel.setForeground(Color.GRAY);
        JLabel priceLabel = new JLabel(price);
        priceLabel.setFont(new Font("Arial", Font.BOLD, 14));

        infoPanel.add(nameLabel);
        infoPanel.add(Box.createRigidArea(new Dimension(0, 5)));
        infoPanel.add(descLabel);
        infoPanel.add(Box.createRigidArea(new Dimension(0, 5)));
        infoPanel.add(priceLabel);

        panel.add(infoPanel, BorderLayout.CENTER);

        // Button Panel
        JButton addButton = new JButton("Tambah ke Keranjang");
        addButton.setBackground(Color.RED);
        addButton.setForeground(Color.WHITE);
        addButton.setFocusPainted(false);
        addButton.setBorderPainted(false);
        addButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
        panel.add(addButton, BorderLayout.EAST);

        return panel;
    }
}