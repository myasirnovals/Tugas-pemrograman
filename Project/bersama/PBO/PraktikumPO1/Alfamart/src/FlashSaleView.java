import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class FlashSaleView extends JPanel {
    private ArrayList<Product> products;
    private JPanel productsPanel;

    public FlashSaleView() {
        products = new ArrayList<>();
        setLayout(new BorderLayout());

        // Initialize sample products
        initializeProducts();

        // Create main components
        createHeader();
        createCategoryTabs();
        createProductsGrid();
    }

    private void initializeProducts() {
        // Add sample products
        for (int i = 1; i <= 10; i++) {
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

    private void createCategoryTabs() {
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

        add(tabsPanel, BorderLayout.CENTER);
    }

    private void createProductsGrid() {
        JPanel mainScrollPanel = new JPanel();
        mainScrollPanel.setLayout(new BorderLayout());

        productsPanel = new JPanel();
        productsPanel.setLayout(new GridLayout(0, 5, 10, 10));
        productsPanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));

        // Add product cards
        for (Product product : products) {
            productsPanel.add(createProductCard(product));
        }

        JScrollPane scrollPane = new JScrollPane(productsPanel);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_AS_NEEDED);
        scrollPane.setBorder(null);

        mainScrollPanel.add(scrollPane, BorderLayout.CENTER);
        add(mainScrollPanel, BorderLayout.SOUTH);
    }

    private JPanel createProductCard(Product product) {
        JPanel card = new JPanel();
        card.setLayout(new BoxLayout(card, BoxLayout.Y_AXIS));
        card.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        card.setBackground(Color.WHITE);

        // Product Image (placeholder)
        JPanel imagePanel = new JPanel();
        imagePanel.setPreferredSize(new Dimension(180, 180));
        imagePanel.setBackground(Color.LIGHT_GRAY);
        imagePanel.setMaximumSize(new Dimension(180, 180));
        card.add(imagePanel);

        // Category
        JLabel categoryLabel = new JLabel(product.getCategory());
        categoryLabel.setForeground(Color.GRAY);
        categoryLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        card.add(categoryLabel);

        // Product Name
        JLabel nameLabel = new JLabel(product.getName());
        nameLabel.setFont(new Font("Arial", Font.BOLD, 14));
        nameLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        card.add(nameLabel);

        // Description
        JTextArea descArea = new JTextArea(product.getDescription());
        descArea.setWrapStyleWord(true);
        descArea.setLineWrap(true);
        descArea.setOpaque(false);
        descArea.setEditable(false);
        descArea.setForeground(Color.GRAY);
        descArea.setFont(new Font("Arial", Font.PLAIN, 12));
        descArea.setAlignmentX(Component.LEFT_ALIGNMENT);
        card.add(descArea);

        // Discount
        JLabel discountLabel = new JLabel(product.getDiscount());
        discountLabel.setForeground(Color.RED);
        discountLabel.setAlignmentX(Component.LEFT_ALIGNMENT);
        card.add(discountLabel);

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
