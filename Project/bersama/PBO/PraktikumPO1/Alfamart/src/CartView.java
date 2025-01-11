import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import java.util.ArrayList;

public class CartView extends JPanel {
    private ArrayList<CartItem> cartItems;
    private JLabel totalLabel;
    private double totalPrice = 0.0;
    private static final int PADDING = 20;
    private static final Color PRIMARY_COLOR = Color.RED;
    private static final Font HEADER_FONT = new Font("Arial", Font.BOLD, 20);
    private static final Font PRICE_FONT = new Font("Arial", Font.BOLD, 16);

    public CartView() {
        cartItems = new ArrayList<>();
        initializeLayout();
        createComponents();
    }

    private void initializeLayout() {
        setLayout(new BorderLayout());
    }

    private void createComponents() {
        createHeaderPanel();
        createMainContent();
        createFooterPanel();
    }

    private void createHeaderPanel() {
        // Header Panel
        JPanel headerPanel = createBaseHeaderPanel();

        // Logo, Search, Cart sections
        headerPanel.add(createLogoSection(), BorderLayout.WEST);
        headerPanel.add(createSearchSection(), BorderLayout.CENTER);
        headerPanel.add(createCartButton(), BorderLayout.EAST);

        // Navigation Panel
        JPanel navPanel = createNavigationPanel();

        // Combine header and nav
        JPanel headerWithNav = new JPanel(new BorderLayout());
        headerWithNav.add(headerPanel, BorderLayout.NORTH);
        headerWithNav.add(navPanel, BorderLayout.SOUTH);

        add(headerWithNav, BorderLayout.NORTH);
    }

    private JPanel createBaseHeaderPanel() {
        JPanel headerPanel = new JPanel(new BorderLayout());
        headerPanel.setBackground(PRIMARY_COLOR);
        headerPanel.setPreferredSize(new Dimension(800, 60));
        return headerPanel;
    }

    private JLabel createLogoSection() {
        JLabel logoLabel = new JLabel("ALFAMART");
        logoLabel.setForeground(Color.WHITE);
        logoLabel.setFont(HEADER_FONT);
        logoLabel.setBorder(BorderFactory.createEmptyBorder(0, PADDING, 0, 0));
        return logoLabel;
    }

    private JPanel createSearchSection() {
        JPanel searchPanel = new JPanel(new BorderLayout());
        searchPanel.setBackground(PRIMARY_COLOR);
        searchPanel.setBorder(BorderFactory.createEmptyBorder(10, 100, 10, 100));

        JTextField searchField = new JTextField("cari produk....");
        JButton searchButton = new JButton("Q");

        searchPanel.add(searchField, BorderLayout.CENTER);
        searchPanel.add(searchButton, BorderLayout.EAST);
        return searchPanel;
    }

    private JButton createCartButton() {
        JButton cartButton = new JButton("\uD83D\uDED2");
        cartButton.setBackground(PRIMARY_COLOR);
        cartButton.setForeground(Color.WHITE);
        cartButton.setBorder(BorderFactory.createEmptyBorder(0, PADDING, 0, PADDING));
        return cartButton;
    }

    private JPanel createNavigationPanel() {
        JPanel navPanel = new JPanel(new GridLayout(1, 4));
        navPanel.setPreferredSize(new Dimension(800, 40));
        navPanel.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.LIGHT_GRAY));

        String[] navItems = {"Produk", "Promosi", "Keranjang", "Hubungi Kami"};
        for (String item : navItems) {
            navPanel.add(createNavButton(item));
        }
        return navPanel;
    }

    private JButton createNavButton(String text) {
        JButton navButton = new JButton(text);
        navButton.setForeground(Color.BLACK);
        navButton.setBackground(Color.WHITE);
        navButton.setBorderPainted(false);
        navButton.setFocusPainted(false);
        navButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
        navButton.addActionListener(e -> handleNavigation(text));
        return navButton;
    }

    private void handleNavigation(String destination) {
        Component comp = this;
        while (!(comp instanceof Main) && comp != null) {
            comp = comp.getParent();
        }
        if (comp instanceof Main) {
            ((Main) comp).showCard(destination);
        }
    }

    private void createMainContent() {
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(PADDING, PADDING, PADDING, PADDING));

        // Initialize sample data
        initializeSampleData();

        // Create and add cart items panel
        JPanel cartItemsPanel = new JPanel();
        cartItemsPanel.setLayout(new BoxLayout(cartItemsPanel, BoxLayout.Y_AXIS));

        // Add header and items
        cartItemsPanel.add(createCartHeader());
        addCartItems(cartItemsPanel);

        mainPanel.add(cartItemsPanel);
        add(new JScrollPane(mainPanel), BorderLayout.CENTER);
    }

    private void initializeSampleData() {
        cartItems.add(new CartItem("Indomie Goreng", 4000, 1));
        cartItems.add(new CartItem("Indomie Soto", 4000, 1));
    }

    // Tambahkan method ini setelah initializeSampleData()

    private JPanel createCartHeader() {
        JPanel headerRow = new JPanel(new GridLayout(1, 5));
        headerRow.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.LIGHT_GRAY));

        String[] headers = {"Produk", "Harga Satuan", "Kuantitas", "Total Harga", "Aksi"};
        for (String header : headers) {
            JLabel headerLabel = new JLabel(header);
            headerLabel.setFont(new Font("Arial", Font.BOLD, 14));
            headerRow.add(headerLabel);
        }

        return headerRow;
    }

    private void addCartItems(JPanel cartItemsPanel) {
        totalPrice = 0.0; // Reset total price

        for (CartItem item : cartItems) {
            cartItemsPanel.add(createCartItemPanel(item));
            totalPrice += item.getPrice() * item.getQuantity();
        }

        // Update total label if it exists
        if (totalLabel != null) {
            totalLabel.setText("Total: RP " + String.format("%,d", (int)totalPrice));
        }
    }

    private JPanel createCartItemPanel(CartItem item) {
        JPanel panel = new JPanel(new GridLayout(1, 5));
        panel.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.LIGHT_GRAY));

        // Product Image and Name
        JPanel productPanel = new JPanel(new BorderLayout());
        JLabel imageLabel = new JLabel("400 x 400");
        imageLabel.setPreferredSize(new Dimension(80, 80));
        imageLabel.setBackground(Color.LIGHT_GRAY);
        imageLabel.setOpaque(true);
        productPanel.add(imageLabel, BorderLayout.WEST);

        // Price
        JLabel priceLabel = new JLabel("RP " + String.format("%,d", (int)item.getPrice()));
        priceLabel.setForeground(Color.RED);

        // Quantity
        JPanel quantityPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JButton minusButton = new JButton("-");
        JTextField quantityField = new JTextField(String.valueOf(item.getQuantity()), 3);
        quantityField.setHorizontalAlignment(JTextField.CENTER);
        JButton plusButton = new JButton("+");

        quantityPanel.add(minusButton);
        quantityPanel.add(quantityField);
        quantityPanel.add(plusButton);

        // Total
        JLabel totalLabel = new JLabel("RP " + String.format("%,d", (int)(item.getPrice() * item.getQuantity())));
        totalLabel.setForeground(Color.RED);

        // Delete Button
        JButton deleteButton = new JButton("Hapus");
        deleteButton.setForeground(Color.BLACK);

        panel.add(productPanel);
        panel.add(priceLabel);
        panel.add(quantityPanel);
        panel.add(totalLabel);
        panel.add(deleteButton);

        return panel;
    }

    private void createFooterPanel() {
        JPanel footerPanel = new JPanel(new BorderLayout());
        footerPanel.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));

        // Total Price
        totalLabel = new JLabel("Total: RP " + String.format("%,d", (int)totalPrice));
        totalLabel.setFont(new Font("Arial", Font.BOLD, 16));

        // Checkout Button
        JButton checkoutButton = new JButton("CHECKOUT");
        checkoutButton.setBackground(Color.RED);
        checkoutButton.setForeground(Color.WHITE);
        checkoutButton.setPreferredSize(new Dimension(120, 40));

        footerPanel.add(totalLabel, BorderLayout.WEST);
        footerPanel.add(checkoutButton, BorderLayout.EAST);

        add(footerPanel, BorderLayout.SOUTH);
    }

    // CartItem class to store item details
    private class CartItem {
        private String name;
        private double price;
        private int quantity;

        public CartItem(String name, double price, int quantity) {
            this.name = name;
            this.price = price;
            this.quantity = quantity;
        }

        public String getName() { return name; }
        public double getPrice() { return price; }
        public int getQuantity() { return quantity; }
    }
}
