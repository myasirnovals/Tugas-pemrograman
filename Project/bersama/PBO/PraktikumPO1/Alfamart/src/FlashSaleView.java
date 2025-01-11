import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class FlashSaleView extends JPanel {
    private ArrayList<Product> products;
    private JPanel productsPanel;
    private int currentPage = 0;
    private final int PRODUCTS_PER_PAGE = 20; // 4 kolom x 5 baris
    private final int COLUMNS = 4;

    public FlashSaleView() {
        products = new ArrayList<>();
        setLayout(new BorderLayout());

        // Initialize sample products
        initializeProducts();

        // Buat panel utama untuk menampung semua konten
        JPanel mainContentPanel = new JPanel(new BorderLayout());

        // Create main components
        createHeader();
        createCategoryTabs(mainContentPanel);
        createProductsGrid(mainContentPanel);

        // Tambahkan mainContentPanel ke panel utama
        add(mainContentPanel, BorderLayout.CENTER);
    }

    private void initializeProducts() {
        // Add sample products
        for (int i = 1; i <= 40; i++) { // Menambah 40 produk untuk contoh
            products.add(new Product(
                    "Product Name " + i,
                    "consectetur adipiscing elit duis tristique sollicitudin nisi sit amet commodo.",
                    "25%",
                    "Category"
            ));
        }
    }

    private void createHeader() {
        // Header Panel
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

        // Navigation Panel
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

        // Panel untuk menampung header dan navigasi
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

        // Panel untuk produk
        productsPanel = new JPanel();
        productsPanel.setLayout(new GridLayout(5, 4, 15, 15)); // Menambah spacing antar card
        productsPanel.setBorder(BorderFactory.createEmptyBorder(15, 15, 15, 15));

        // Tampilkan produk untuk halaman saat ini
        updateProductsDisplay();

        JScrollPane scrollPane = new JScrollPane(productsPanel);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPane.setBorder(null);

        mainScrollPanel.add(scrollPane, BorderLayout.CENTER);

        // Panel untuk pagination
        JPanel paginationPanel = new JPanel(new FlowLayout(FlowLayout.CENTER));
        JButton prevButton = new JButton("Previous");
        JButton nextButton = new JButton("Next");

        // Styling tombol
        prevButton.setBackground(Color.WHITE);
        nextButton.setBackground(Color.WHITE);
        prevButton.setFocusPainted(false);
        nextButton.setFocusPainted(false);

        // Action listeners
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

        // Update status tombol pagination
        updatePaginationButtons(prevButton, nextButton);

        mainScrollPanel.add(paginationPanel, BorderLayout.SOUTH);
        mainContentPanel.add(mainScrollPanel, BorderLayout.CENTER);
    }

    private void updateProductsDisplay() {
        productsPanel.removeAll();

        int start = currentPage * PRODUCTS_PER_PAGE;
        int end = Math.min(start + PRODUCTS_PER_PAGE, products.size());

        // Tambahkan produk untuk halaman saat ini
        for (int i = start; i < end; i++) {
            productsPanel.add(createProductCard(products.get(i)));
        }

        // Jika jumlah produk kurang dari PRODUCTS_PER_PAGE, tambahkan panel kosong
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

        // Panel untuk konten utama (gambar dan teks)
        JPanel contentPanel = new JPanel();
        contentPanel.setLayout(new BoxLayout(contentPanel, BoxLayout.Y_AXIS));
        contentPanel.setBackground(Color.WHITE);

        // Product Image (placeholder)
        JPanel imagePanel = new JPanel();
        imagePanel.setPreferredSize(new Dimension(150, 150));
        imagePanel.setMinimumSize(new Dimension(150, 150));
        imagePanel.setMaximumSize(new Dimension(150, 150));
        imagePanel.setBackground(Color.LIGHT_GRAY);
        contentPanel.add(imagePanel);
        contentPanel.add(Box.createVerticalStrut(8)); // Spacing

        // Panel untuk informasi produk
        JPanel infoPanel = new JPanel();
        infoPanel.setLayout(new BoxLayout(infoPanel, BoxLayout.Y_AXIS));
        infoPanel.setBackground(Color.WHITE);

        // Category
        JLabel categoryLabel = new JLabel(product.getCategory());
        categoryLabel.setForeground(Color.GRAY);
        categoryLabel.setFont(new Font("Arial", Font.PLAIN, 12));
        categoryLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        infoPanel.add(categoryLabel);
        infoPanel.add(Box.createVerticalStrut(4));

        // Product Name
        JLabel nameLabel = new JLabel("<html><body style='width: 140px'>" +
                product.getName() + "</body></html>");
        nameLabel.setFont(new Font("Arial", Font.BOLD, 14));
        nameLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        infoPanel.add(nameLabel);
        infoPanel.add(Box.createVerticalStrut(4));

        // Description
        JLabel descLabel = new JLabel("<html><body style='width: 140px'>" +
                product.getDescription() + "</body></html>");
        descLabel.setForeground(Color.GRAY);
        descLabel.setFont(new Font("Arial", Font.PLAIN, 12));
        descLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        infoPanel.add(descLabel);
        infoPanel.add(Box.createVerticalStrut(8));

        // Discount
        JLabel discountLabel = new JLabel(product.getDiscount());
        discountLabel.setForeground(Color.RED);
        discountLabel.setFont(new Font("Arial", Font.BOLD, 14));
        discountLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        infoPanel.add(discountLabel);

        contentPanel.add(infoPanel);
        card.add(contentPanel, BorderLayout.CENTER);

        // Tambahkan hover effect
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

    // Product class to store product details
    private class Product {
        private String name;
        private String description;
        private String discount;
        private String category;

        public Product(String name, String description, String discount, String category) {
            this.name = name;
            this.description = description;
            this.discount = discount;
            this.category = category;
        }

        public String getName() { return name; }
        public String getDescription() { return description; }
        public String getDiscount() { return discount; }
        public String getCategory() { return category; }
    }
}
