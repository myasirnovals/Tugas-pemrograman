import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import java.util.ArrayList;

public class CartView extends JFrame {
    private ArrayList<CartItem> cartItems;
    private JLabel totalLabel;
    private double totalPrice = 0.0;

    public CartView() {
        cartItems = new ArrayList<>();
        setTitle("Alfamart - Keranjang");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Header Panel
        createHeaderPanel();

        // Main Content
        createMainContent();

        // Footer with Checkout Button
        createFooterPanel();
    }

    private void createHeaderPanel() {
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

        add(headerPanel, BorderLayout.NORTH);
    }

    private void createMainContent() {
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        // Add sample items
        cartItems.add(new CartItem("Indomie Goreng", 4000, 1));
        cartItems.add(new CartItem("Indomie Soto", 4000, 1));

        // Create cart items panel
        JPanel cartItemsPanel = new JPanel();
        cartItemsPanel.setLayout(new BoxLayout(cartItemsPanel, BoxLayout.Y_AXIS));

        // Header
        JPanel headerRow = new JPanel(new GridLayout(1, 5));
        headerRow.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.LIGHT_GRAY));
        headerRow.add(new JLabel("Produk"));
        headerRow.add(new JLabel("Harga Satuan"));
        headerRow.add(new JLabel("Kuantitas"));
        headerRow.add(new JLabel("Total Harga"));
        headerRow.add(new JLabel("Aksi"));
        cartItemsPanel.add(headerRow);

        // Add items
        for (CartItem item : cartItems) {
            cartItemsPanel.add(createCartItemPanel(item));
            totalPrice += item.getPrice() * item.getQuantity();
        }

        mainPanel.add(cartItemsPanel);
        add(new JScrollPane(mainPanel), BorderLayout.CENTER);
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
