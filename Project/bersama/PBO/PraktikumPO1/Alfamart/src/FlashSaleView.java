import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;

public class FlashSaleView extends JFrame {
    private ArrayList<Product> products;
    private JPanel productsPanel;

    public FlashSaleView() {
        products = new ArrayList<>();
        setTitle("Alfamart - Flash Sale");
        setSize(1000, 800);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
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
        JPanel headerPanel = new JPanel();
        headerPanel.setBackground(Color.RED);
        headerPanel.setPreferredSize(new Dimension(getWidth(), 50));

        JLabel flashSaleLabel = new JLabel("Flash Sale Hari Ini !!");
        flashSaleLabel.setFont(new Font("Arial", Font.BOLD, 24));
        flashSaleLabel.setForeground(Color.WHITE);
        headerPanel.add(flashSaleLabel);

        add(headerPanel, BorderLayout.NORTH);
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

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            FlashSaleView frame = new FlashSaleView();
            frame.setVisible(true);
        });
    }
}
