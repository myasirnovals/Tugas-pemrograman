import dao.CartDAO;
import dao.ProductDAO;
import database.DBConnection;
import model.CartItem;
import model.Product;

import javax.swing.*;
import java.awt.*;
import java.sql.*;

public class AlfamartECommerce extends JPanel {
    private JPanel contentPanel;
    private JPanel paginationPanel;
    private int currentPage = 1;
    private final int PRODUCTS_PER_PAGE = 10;
    private CartDAO cartDAO;

    public AlfamartECommerce() {
        this.cartDAO = new CartDAO();
        setLayout(new BorderLayout());

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

        JPanel mainPanel = new JPanel(new BorderLayout());
        mainPanel.add(navPanel, BorderLayout.NORTH);

        contentPanel = new JPanel();
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));
        contentPanel.setBackground(Color.WHITE);
        contentPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        paginationPanel = new JPanel(new FlowLayout());
        paginationPanel.setBackground(Color.WHITE);

        JPanel containerPanel = new JPanel(new BorderLayout());
        containerPanel.add(contentPanel, BorderLayout.CENTER);
        containerPanel.add(paginationPanel, BorderLayout.SOUTH);

        JScrollPane scrollPane = new JScrollPane(containerPanel);
        scrollPane.setBorder(null);
        mainPanel.add(scrollPane, BorderLayout.CENTER);

        add(mainPanel, BorderLayout.CENTER);

        JPanel footerPanel = new JPanel();
        footerPanel.setBackground(new Color(51, 51, 51));
        footerPanel.setPreferredSize(new Dimension(800, 30));
        JLabel footerLabel = new JLabel("© 2025 Alfamart E-Commerce. Semua Hak Dilindungi.");
        footerLabel.setForeground(Color.WHITE);
        footerPanel.add(footerLabel);
        add(footerPanel, BorderLayout.SOUTH);

        loadProducts(currentPage);
    }

    private void loadProducts(int page) {
        contentPanel.removeAll();

        try (Connection conn = DBConnection.getConnection()) {
            int offset = (page - 1) * PRODUCTS_PER_PAGE;
            String query = "SELECT * FROM products LIMIT ? OFFSET ?";
            PreparedStatement ps = conn.prepareStatement(query);
            ps.setInt(1, PRODUCTS_PER_PAGE);
            ps.setInt(2, offset);

            ResultSet rs = ps.executeQuery();
            while (rs.next()) {
                JPanel productPanel = createProductPanel(
                        rs.getInt("product_id"),
                        rs.getString("name"),
                        rs.getString("description"),
                        "Rp " + String.format("%,d", rs.getInt("price")),
                        rs.getInt("stock")
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

        String countQuery = "SELECT COUNT(*) as total FROM products";
        Statement stmt = conn.createStatement();
        ResultSet rs = stmt.executeQuery(countQuery);

        int totalProducts = 0;
        if (rs.next()) {
            totalProducts = rs.getInt("total");
        }

        int totalPages = (int) Math.ceil((double) totalProducts / PRODUCTS_PER_PAGE);

        JButton prevButton = new JButton("Previous");
        prevButton.setEnabled(currentPage > 1);
        prevButton.addActionListener(e -> {
            currentPage--;
            loadProducts(currentPage);
        });

        JButton nextButton = new JButton("Next");
        nextButton.setEnabled(currentPage < totalPages);
        nextButton.addActionListener(e -> {
            currentPage++;
            loadProducts(currentPage);
        });

        JLabel pageInfo = new JLabel(String.format("Page %d of %d", currentPage, totalPages));

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

    private JPanel createProductPanel(int productId, String name, String description, String price, int stock) {
        JPanel panel = new JPanel(new BorderLayout(10, 0));
        panel.setMaximumSize(new Dimension(750, 100));
        panel.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(Color.LIGHT_GRAY),
                BorderFactory.createEmptyBorder(10, 10, 10, 10)
        ));
        panel.setBackground(Color.WHITE);

        JPanel imagePanel = new JPanel();
        imagePanel.setPreferredSize(new Dimension(100, 100));
        imagePanel.setBackground(Color.LIGHT_GRAY);
        JLabel imageLabel = new JLabel("100 x 100");
        imageLabel.setForeground(Color.GRAY);
        imagePanel.add(imageLabel);
        panel.add(imagePanel, BorderLayout.WEST);

        JPanel infoPanel = new JPanel();
        infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));
        infoPanel.setBackground(Color.WHITE);

        JLabel nameLabel = new JLabel(name);
        nameLabel.setFont(new Font("Arial", Font.BOLD, 14));

        JLabel descLabel = new JLabel(description);
        descLabel.setForeground(Color.GRAY);

        JLabel priceLabel = new JLabel(price);
        priceLabel.setFont(new Font("Arial", Font.BOLD, 14));

        JLabel stockLabel = new JLabel("Stok: " + stock);
        stockLabel.setForeground(stock > 0 ? new Color(0, 150, 0) : Color.RED);

        infoPanel.add(nameLabel);
        infoPanel.add(Box.createRigidArea(new Dimension(0, 5)));
        infoPanel.add(descLabel);
        infoPanel.add(Box.createRigidArea(new Dimension(0, 5)));
        infoPanel.add(priceLabel);
        infoPanel.add(Box.createRigidArea(new Dimension(0, 5)));
        infoPanel.add(stockLabel);

        panel.add(infoPanel, BorderLayout.CENTER);

        JButton addButton = new JButton(stock > 0 ? "Tambah ke Keranjang" : "Stok Habis");
        addButton.setBackground(Color.RED);
        addButton.setForeground(Color.WHITE);
        addButton.setFocusPainted(false);
        addButton.setEnabled(stock > 0);
        addButton.setCursor(new Cursor(Cursor.HAND_CURSOR));

        addButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                if (addButton.isEnabled()) {
                    addButton.setBackground(new Color(204, 0, 0));
                }
            }

            public void mouseExited(java.awt.event.MouseEvent evt) {
                if (addButton.isEnabled()) {
                    addButton.setBackground(Color.RED);
                }
            }
        });

        addButton.addActionListener(e -> {
            addButton.setEnabled(false);
            addButton.setText("Menambahkan...");

            SwingWorker<Void, Void> worker = new SwingWorker<>() {
                @Override
                protected Void doInBackground() throws Exception {
                    try {
                        ProductDAO productDAO = new ProductDAO();
                        Product product = productDAO.getProductById(productId);

                        if (product != null && product.getStock() > 0) {
                            CartItem cartItem = new CartItem(0, product, 1);
                            cartDAO.addToCart(cartItem);
                        }
                    } catch (SQLException ex) {
                        throw ex;
                    }
                    return null;
                }

                @Override
                protected void done() {
                    try {
                        get();
                        JOptionPane.showMessageDialog(panel,
                                "Produk berhasil ditambahkan ke keranjang!",
                                "Sukses",
                                JOptionPane.INFORMATION_MESSAGE);
                        loadProducts(currentPage);
                    } catch (Exception ex) {
                        JOptionPane.showMessageDialog(panel,
                                "Error menambahkan ke keranjang: " + ex.getMessage(),
                                "Error",
                                JOptionPane.ERROR_MESSAGE);
                    }
                }
            };
            worker.execute();
        });

        panel.add(addButton, BorderLayout.EAST);
        return panel;
    }
}