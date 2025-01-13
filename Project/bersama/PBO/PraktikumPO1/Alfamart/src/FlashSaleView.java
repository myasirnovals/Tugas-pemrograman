import model.Product;

import javax.swing.*;
import java.awt.*;
import java.sql.*;
import java.util.ArrayList;

public class FlashSaleView extends JPanel {
    private ArrayList<Product> products;
    private JPanel productsPanel;
    private int currentPage = 0;
    private final int PRODUCTS_PER_PAGE = 20;
    private final int COLUMNS = 4;

    public FlashSaleView() {
        products = new ArrayList<>();
        setLayout(new BorderLayout());

        initializeProducts();

        JPanel mainContentPanel = new JPanel(new BorderLayout());

        createHeader();
        createCategoryTabs(mainContentPanel);
        createProductsGrid(mainContentPanel);

        add(mainContentPanel, BorderLayout.CENTER);
    }

    private void initializeProducts() {
        products.clear();
        try {
            Connection conn = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/kuliah_basisdata_alfamart_ecommerce",
                    "root", "");

            String query = "SELECT p.*, c.name as category_name " +
                    "FROM products p " +
                    "JOIN categories c ON p.category_id = c.category_id " +
                    "WHERE p.discount_percentage > 0 " +
                    "ORDER BY p.discount_percentage DESC";

            PreparedStatement stmt = conn.prepareStatement(query);
            ResultSet rs = stmt.executeQuery();

            while (rs.next()) {
                Product product = new Product(
                        rs.getInt("product_id"),
                        rs.getInt("category_id"),
                        rs.getString("name"),
                        rs.getString("description"),
                        rs.getDouble("price"),
                        rs.getDouble("discount_percentage"),
                        rs.getString("image_url"),
                        rs.getInt("stock")
                );
                products.add(product);
            }

            rs.close();
            stmt.close();
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
            JOptionPane.showMessageDialog(this,
                    "Error loading products: " + e.getMessage(),
                    "Database Error",
                    JOptionPane.ERROR_MESSAGE);
        }
    }

    private void createHeader() {
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

        add(headerWithNav, BorderLayout.NORTH);
    }

    private void createCategoryTabs(JPanel mainContentPanel) {
        JPanel tabsPanel = new JPanel();
        tabsPanel.setLayout(new FlowLayout(FlowLayout.LEFT));
        tabsPanel.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.LIGHT_GRAY));

        String[] categories = {"All", "Segera Habis", "Makanan", "Sembako", "Lainnya"};

        for (String category : categories) {
            JButton tabButton = new JButton(category);
            tabButton.setFocusPainted(false);
            tabButton.setBorderPainted(false);
            tabButton.setBackground(Color.WHITE);
            if (category.equals("All")) {
                tabButton.setForeground(Color.RED);
            }
            tabsPanel.add(tabButton);
        }

        mainContentPanel.add(tabsPanel, BorderLayout.NORTH);
    }

    private void createProductsGrid(JPanel mainContentPanel) {
        JPanel mainScrollPanel = new JPanel();
        mainScrollPanel.setLayout(new BorderLayout());

        productsPanel = new JPanel();
        productsPanel.setLayout(new GridLayout(5, 4, 15, 15));
        productsPanel.setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        updateProductsDisplay();

        JScrollPane scrollPane = new JScrollPane(productsPanel);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPane.setBorder(null);

        mainScrollPanel.add(scrollPane, BorderLayout.CENTER);

        JPanel paginationPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
        JButton prevButton = new JButton("Previous");
        JButton nextButton = new JButton("Next");

        prevButton.setBackground(Color.WHITE);
        nextButton.setBackground(Color.WHITE);
        prevButton.setFocusPainted(false);
        nextButton.setFocusPainted(false);

        prevButton.addActionListener(e -> {
            if (currentPage > 0) {
                currentPage--;
                updateProductsDisplay();
                updatePaginationButtons(prevButton, nextButton);
            }
        });

        nextButton.addActionListener(e -> {
            if ((currentPage + 1) * PRODUCTS_PER_PAGE < products.size()) {
                currentPage++;
                updateProductsDisplay();
                updatePaginationButtons(prevButton, nextButton);
            }
        });

        paginationPanel.add(prevButton);
        paginationPanel.add(nextButton);

        updatePaginationButtons(prevButton, nextButton);

        mainScrollPanel.add(paginationPanel, BorderLayout.SOUTH);
        mainContentPanel.add(mainScrollPanel, BorderLayout.CENTER);
    }

    private void updateProductsDisplay() {
        productsPanel.removeAll();

        int start = currentPage * PRODUCTS_PER_PAGE;
        int end = Math.min(start + PRODUCTS_PER_PAGE, products.size());

        for (int i = start; i < end; i++) {
            productsPanel.add(createProductCard(products.get(i)));
        }

        for (int i = end - start; i < PRODUCTS_PER_PAGE; i++) {
            JPanel emptyPanel = new JPanel();
            emptyPanel.setBackground(Color.WHITE);
            productsPanel.add(emptyPanel);
        }

        productsPanel.revalidate();
        productsPanel.repaint();
    }

    private void updatePaginationButtons(JButton prevButton, JButton nextButton) {
        prevButton.setEnabled(currentPage > 0);
        nextButton.setEnabled((currentPage + 1) * PRODUCTS_PER_PAGE < products.size());
    }

    private JPanel createProductCard(Product product) {
        JPanel card = new JPanel();
        card.setLayout(new BorderLayout(5, 5));
        card.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(Color.LIGHT_GRAY, 1),
                BorderFactory.createEmptyBorder(8, 8, 8, 8)
        ));
        card.setBackground(Color.WHITE);

        JPanel contentPanel = new JPanel();
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));
        contentPanel.setBackground(Color.WHITE);

        JPanel imagePanel = new JPanel();
        imagePanel.setPreferredSize(new Dimension(150, 150));
        imagePanel.setMinimumSize(new Dimension(150, 150));
        imagePanel.setMaximumSize(new Dimension(150, 150));
        imagePanel.setBackground(Color.LIGHT_GRAY);
        contentPanel.add(imagePanel);
        contentPanel.add(Box.createVerticalStrut(8));

        JPanel infoPanel = new JPanel();
        infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));
        infoPanel.setBackground(Color.WHITE);

        JLabel categoryLabel = new JLabel(getCategoryName(product.getCategoryId()));
        categoryLabel.setForeground(Color.GRAY);
        categoryLabel.setFont(new Font("Arial", Font.PLAIN, 12));
        categoryLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        infoPanel.add(categoryLabel);
        infoPanel.add(Box.createVerticalStrut(4));

        JLabel nameLabel = new JLabel("<html><body style='width: 140px'>" +
                product.getName() + "</body></html>");
        nameLabel.setFont(new Font("Arial", Font.BOLD, 14));
        nameLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        infoPanel.add(nameLabel);
        infoPanel.add(Box.createVerticalStrut(4));

        JPanel pricePanel = new JPanel();
        pricePanel.setLayout(new BoxLayout(pricePanel, BoxLayout.Y_AXIS));
        pricePanel.setBackground(Color.WHITE);
        pricePanel.setAlignmentX(Component.LEFT_ALIGNMENT);

        JLabel originalPriceLabel = new JLabel("<html><strike>Rp " +
                String.format("%,d", (int) product.getPrice()) + "</strike></html>");
        originalPriceLabel.setForeground(Color.GRAY);
        originalPriceLabel.setFont(new Font("Arial", Font.PLAIN, 12));
        pricePanel.add(originalPriceLabel);

        double discountedPrice = product.getPrice() *
                (1 - product.getDiscountPercentage() / 100.0);
        JLabel priceLabel = new JLabel("Rp " +
                String.format("%,d", (int) discountedPrice));
        priceLabel.setFont(new Font("Arial", Font.BOLD, 14));
        priceLabel.setForeground(Color.RED);
        pricePanel.add(priceLabel);

        JLabel discountLabel = new JLabel("-" +
                (int) product.getDiscountPercentage() + "%");
        discountLabel.setForeground(Color.RED);
        discountLabel.setFont(new Font("Arial", Font.BOLD, 12));
        pricePanel.add(discountLabel);

        infoPanel.add(pricePanel);
        infoPanel.add(Box.createVerticalStrut(8));

        JButton addToCartButton = new JButton("Tambah ke Keranjang");
        addToCartButton.setBackground(Color.RED);
        addToCartButton.setForeground(Color.WHITE);
        addToCartButton.setFocusPainted(false);
        addToCartButton.setBorderPainted(false);
        addToCartButton.setAlignmentX(Component.LEFT_ALIGNMENT);
        addToCartButton.setCursor(new Cursor(Cursor.HAND_CURSOR));

        addToCartButton.addActionListener(e -> {
            try {
                addToCart(product.getProductId(), 1);
                JOptionPane.showMessageDialog(this,
                        "Produk berhasil ditambahkan ke keranjang!",
                        "Sukses",
                        JOptionPane.INFORMATION_MESSAGE);
            } catch (SQLException ex) {
                JOptionPane.showMessageDialog(this,
                        "Gagal menambahkan produk ke keranjang: " + ex.getMessage(),
                        "Error",
                        JOptionPane.ERROR_MESSAGE);
            }
        });

        infoPanel.add(addToCartButton);

        contentPanel.add(infoPanel);
        card.add(contentPanel, BorderLayout.CENTER);

        card.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                card.setBorder(BorderFactory.createCompoundBorder(
                        BorderFactory.createLineBorder(Color.RED, 1),
                        BorderFactory.createEmptyBorder(8, 8, 8, 8)
                ));
            }

            public void mouseExited(java.awt.event.MouseEvent evt) {
                card.setBorder(BorderFactory.createCompoundBorder(
                        BorderFactory.createLineBorder(Color.LIGHT_GRAY, 1),
                        BorderFactory.createEmptyBorder(8, 8, 8, 8)
                ));
            }
        });

        return card;
    }

    private void addToCart(int productId, int quantity) throws SQLException {
        Connection conn = DriverManager.getConnection(
                "jdbc:mysql://localhost:3306/kuliah_basisdata_alfamart_ecommerce",
                "root", "");

        String query = "INSERT INTO cart_items (product_id, quantity) VALUES (?, ?)";
        PreparedStatement stmt = conn.prepareStatement(query);
        stmt.setInt(1, productId);
        stmt.setInt(2, quantity);
        stmt.executeUpdate();

        stmt.close();
        conn.close();
    }

    private String getCategoryName(int categoryId) {
        try {
            Connection conn = DriverManager.getConnection(
                    "jdbc:mysql://localhost:3306/kuliah_basisdata_alfamart_ecommerce",
                    "root", "");
            String query = "SELECT name FROM categories WHERE category_id = ?";
            PreparedStatement stmt = conn.prepareStatement(query);
            stmt.setInt(1, categoryId);
            ResultSet rs = stmt.executeQuery();

            if (rs.next()) {
                return rs.getString("name");
            }

            rs.close();
            stmt.close();
            conn.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return "Unknown Category";
    }
}
