import javax.swing.*;
import java.awt.*;

public class Main extends JFrame {
    public Main() {
        setTitle("Alfamart E-Commerce");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
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

        headerPanel.add(titleLabel, BorderLayout.CENTER);
        headerPanel.add(subtitleLabel, BorderLayout.SOUTH);
        add(headerPanel, BorderLayout.NORTH);

        // Navigation Panel
        JPanel navPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        navPanel.setBackground(Color.WHITE);
        String[] navItems = {"Produk", "Promosi", "Keranjang", "Hubungi Kami"};
        for (String item : navItems) {
            JButton navButton = new JButton(item);
            navButton.setForeground(Color.BLACK);
            navButton.setBackground(Color.WHITE);
            navButton.setBorderPainted(false);
            navPanel.add(navButton);
        }
        add(navPanel, BorderLayout.CENTER);

        // Content Panel
        JPanel contentPanel = new JPanel();
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));
        contentPanel.setBackground(Color.WHITE);

        JLabel newProductLabel = new JLabel("Produk Terbaru");
        newProductLabel.setFont(new Font("Arial", Font.BOLD, 18));
        newProductLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        contentPanel.add(newProductLabel);
        contentPanel.add(Box.createRigidArea(new Dimension(0, 10)));

        // Product panels
        for (int i = 0; i < 2; i++) {
            JPanel productPanel = createProductPanel("Nama Produk", "Deskripsi singkat produk.", "Rp " + (20000 - (i * 5000)));
            contentPanel.add(productPanel);
            contentPanel.add(Box.createRigidArea(new Dimension(0, 10)));
        }

        JScrollPane scrollPane = new JScrollPane(contentPanel);
        scrollPane.setBorder(null);
        add(scrollPane, BorderLayout.CENTER);

        // Footer Panel
        JPanel footerPanel = new JPanel();
        footerPanel.setBackground(Color.DARK_GRAY);
        footerPanel.setPreferredSize(new Dimension(800, 30));
        JLabel footerLabel = new JLabel("© 2025 Alfamart E-Commerce. Semua Hak Dilindungi.");
        footerLabel.setForeground(Color.WHITE);
        footerPanel.add(footerLabel);
        add(footerPanel, BorderLayout.SOUTH);
    }

    private JPanel createProductPanel(String name, String description, String price) {
        JPanel panel = new JPanel(new BorderLayout());
        panel.setMaximumSize(new Dimension(600, 100));
        panel.setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY));

        JPanel imagePanel = new JPanel();
        imagePanel.setPreferredSize(new Dimension(100, 100));
        imagePanel.setBackground(Color.LIGHT_GRAY);
        panel.add(imagePanel, BorderLayout.WEST);

        JPanel infoPanel = new JPanel();
        infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));
        infoPanel.add(new JLabel(name));
        infoPanel.add(new JLabel(description));
        infoPanel.add(new JLabel(price));
        panel.add(infoPanel, BorderLayout.CENTER);

        JButton addButton = new JButton("Tambah ke Keranjang");
        addButton.setBackground(Color.RED);
        addButton.setForeground(Color.WHITE);
        panel.add(addButton, BorderLayout.EAST);

        return panel;
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Main app = new Main();
            app.setVisible(true);
        });
    }
}