import database.DBConnection;

import javax.swing.*;
import java.awt.*;
import java.sql.*;

public class AlfamartECommerce extends JPanel {
    private JPanel contentPanel;
    private JPanel paginationPanel;
    private int currentPage = 1;
    private final int PRODUCTS_PER_PAGE = 10;

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
        contentPanel = new JPanel();
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));
        contentPanel.setBackground(Color.WHITE);
        contentPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        // Tambah Panel Pagination
        paginationPanel = new JPanel(new FlowLayout());
        paginationPanel.setBackground(Color.WHITE);

        // Panel untuk menampung content dan pagination
        JPanel containerPanel = new JPanel(new BorderLayout());
        containerPanel.add(contentPanel, BorderLayout.CENTER);
        containerPanel.add(paginationPanel, BorderLayout.SOUTH);

        JScrollPane scrollPane = new JScrollPane(containerPanel);
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

        // Load products untuk halaman pertama
        loadProducts(currentPage);
    }

    private void loadProducts(int page) {
        contentPanel.removeAll();

        try (Connection conn = DBConnection.getConnection()) {
            // Hitung offset
            int offset = (page - 1) * PRODUCTS_PER_PAGE;

            // Ambil produk untuk halaman saat ini
            String query = "SELECT * FROM products LIMIT ? OFFSET ?";
            PreparedStatement ps = conn.prepareStatement(query);
            ps.setInt(1, PRODUCTS_PER_PAGE);
            ps.setInt(2, offset);

            ResultSet rs = ps.executeQuery();

            while (rs.next()) {
                JPanel productPanel = createProductPanel(
                        rs.getString("name"),
                        rs.getString("description"),
                        "Rp " + String.format("%,d", rs.getInt("price"))
                );
                contentPanel.add(productPanel);
                contentPanel.add(Box.createRigidArea(new Dimension(0, 10)));
            }

            updatePaginationControls(conn);

        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this,
                    "Error loading products: " + e.getMessage(),
                    "Database Error",
                    JOptionPane.ERROR_MESSAGE);
        }

        contentPanel.revalidate();
        contentPanel.repaint();
    }

    private void updatePaginationControls(Connection conn) throws SQLException {
        paginationPanel.removeAll();

        // Hitung total produk
        String countQuery = "SELECT COUNT(*) as total FROM products";
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery(countQuery);

        int totalProducts = 0;
        if (rs.next()) {
            totalProducts = rs.getInt("total");
        }

        int totalPages = (int) Math.ceil((double) totalProducts / PRODUCTS_PER_PAGE);

        // Tombol Previous
        JButton prevButton = new JButton("Previous");
        prevButton.setEnabled(currentPage > 1);
        prevButton.addActionListener(e -> {
            currentPage--;
            loadProducts(currentPage);
        });

        // Tombol Next
        JButton nextButton = new JButton("Next");
        nextButton.setEnabled(currentPage < totalPages);
        nextButton.addActionListener(e -> {
            currentPage++;
            loadProducts(currentPage);
        });

        // Label informasi halaman
        JLabel pageInfo = new JLabel(String.format("Page %d of %d", currentPage, totalPages));

        // Styling tombol pagination
        prevButton.setBackground(Color.RED);
        prevButton.setForeground(Color.WHITE);
        prevButton.setFocusPainted(false);
        nextButton.setBackground(Color.RED);
        nextButton.setForeground(Color.WHITE);
        nextButton.setFocusPainted(false);

        paginationPanel.add(prevButton);
        paginationPanel.add(Box.createRigidArea(new Dimension(10, 0)));
        paginationPanel.add(pageInfo);
        paginationPanel.add(Box.createRigidArea(new Dimension(10, 0)));
        paginationPanel.add(nextButton);

        paginationPanel.revalidate();
        paginationPanel.repaint();
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