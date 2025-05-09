import dao.CartDAO;
import model.CartItem;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.table.*;
import java.sql.SQLException;
import java.util.ArrayList;

public class CartView extends JPanel {
    private CartDAO cartDAO;
    private ArrayList<CartItem> cartItems;
    private JLabel totalLabel;
    private JButton refreshButton;
    private double totalPrice = 0.0;
    private static final int PADDING = 20;
    private static final Color PRIMARY_COLOR = Color.RED;
    private static final Font HEADER_FONT = new Font("Arial", Font.BOLD, 20);
    private static final Font PRICE_FONT = new Font("Arial", Font.BOLD, 16);
    private static final Color SECONDARY_COLOR = new Color(51, 51, 51);
    private static final Color BACKGROUND_COLOR = Color.WHITE;

    public CartView() {
        cartDAO = new CartDAO();
        cartItems = new ArrayList<>();
        initializeLayout();
        loadCartItems();
        createComponents();
    }

    private void loadCartItems() {
        try {
            cartItems = cartDAO.getAllCartItems();
        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this,
                    "Error loading cart items: " + e.getMessage(),
                    "Database Error",
                    JOptionPane.ERROR_MESSAGE);
        }
    }

    private void initializeLayout() {
        setLayout(new BorderLayout());
    }

    private void createComponents() {
        createHeaderPanel();

        JPanel mainPanel = new JPanel(new BorderLayout());

        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT));
        buttonPanel.setBorder(BorderFactory.createEmptyBorder(10, 0, 10, 20));

        refreshButton = new JButton("Refresh");
        refreshButton.setBackground(Color.WHITE);
        refreshButton.setForeground(PRIMARY_COLOR);
        refreshButton.setFocusPainted(false);
        refreshButton.setCursor(new Cursor(Cursor.HAND_CURSOR));
        refreshButton.addActionListener(e -> refreshCart());

        buttonPanel.add(refreshButton);

        mainPanel.add(buttonPanel, BorderLayout.NORTH);
        mainPanel.add(createMainContent(), BorderLayout.CENTER);

        add(mainPanel, BorderLayout.CENTER);
        createFooterPanel();
    }

    private void refreshCart() {
        try {
            setCursor(Cursor.getPredefinedCursor(Cursor.WAIT_CURSOR));
            loadCartItems();
            refreshView();
            JOptionPane.showMessageDialog(this,
                    "Cart refreshed successfully!",
                    "Success",
                    JOptionPane.INFORMATION_MESSAGE);
        } catch (Exception e) {
            JOptionPane.showMessageDialog(this,
                    "Error refreshing cart: " + e.getMessage(),
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
        } finally {
            setCursor(Cursor.getDefaultCursor());
        }
    }

    private void createHeaderPanel() {
        JPanel headerPanel = createBaseHeaderPanel();

        headerPanel.add(createLogoSection(), BorderLayout.WEST);
        headerPanel.add(createSearchSection(), BorderLayout.CENTER);
        headerPanel.add(createCartButton(), BorderLayout.EAST);

        JPanel navPanel = createNavigationPanel();

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
        JPanel searchPanel = new JPanel(new BorderLayout(10, 0));
        searchPanel.setBackground(PRIMARY_COLOR);
        searchPanel.setBorder(BorderFactory.createEmptyBorder(10, 100, 10, 100));

        JTextField searchField = new JTextField("Cari produk...");
        searchField.setPreferredSize(new Dimension(200, 30));
        searchField.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createLineBorder(Color.WHITE),
                BorderFactory.createEmptyBorder(5, 10, 5, 10)
        ));

        JButton searchButton = new JButton("🔍");
        searchButton.setBackground(Color.WHITE);
        searchButton.setForeground(PRIMARY_COLOR);
        searchButton.setFocusPainted(false);
        searchButton.setCursor(new Cursor(Cursor.HAND_CURSOR));

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
        JPanel navPanel = new JPanel(new GridLayout(1, 4, 2, 0));
        navPanel.setPreferredSize(new Dimension(800, 40));
        navPanel.setBackground(Color.WHITE);
        navPanel.setBorder(BorderFactory.createCompoundBorder(
                BorderFactory.createMatteBorder(1, 0, 1, 0, Color.LIGHT_GRAY),
                BorderFactory.createEmptyBorder(0, PADDING, 0, PADDING)
        ));

        String[] navItems = {"Produk", "Promosi", "Keranjang", "Hubungi Kami"};
        for (String item : navItems) {
            JButton navButton = createNavButton(item);
            if (item.equals("Keranjang")) {
                navButton.setForeground(PRIMARY_COLOR);
                navButton.setFont(navButton.getFont().deriveFont(Font.BOLD));
            }
            navPanel.add(navButton);
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

    private JPanel createMainContent() {
        JPanel mainPanel = new JPanel();
        mainPanel.setLayout(new BoxLayout(mainPanel, BoxLayout.Y_AXIS));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(PADDING, PADDING, PADDING, PADDING));

        initializeSampleData();

        JPanel cartItemsPanel = new JPanel();
        cartItemsPanel.setLayout(new BoxLayout(cartItemsPanel, BoxLayout.Y_AXIS));

        cartItemsPanel.add(createCartHeader());
        addCartItems(cartItemsPanel);

        mainPanel.add(cartItemsPanel);
        return mainPanel;
    }

    private void initializeSampleData() {
    }

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
        totalPrice = 0.0;

        for (CartItem item : cartItems) {
            cartItemsPanel.add(createCartItemPanel(item));
            totalPrice += item.getProduct().getPrice() * item.getQuantity();
        }

        if (totalLabel != null) {
            totalLabel.setText("Total: RP " + String.format("%,d", (int)totalPrice));
        }
    }

    private JPanel createCartItemPanel(CartItem item) {
        JPanel panel = new JPanel(new GridLayout(1, 5));
        panel.setBorder(BorderFactory.createMatteBorder(0, 0, 1, 0, Color.LIGHT_GRAY));

        JPanel productPanel = new JPanel(new BorderLayout());
        JLabel nameLabel = new JLabel(item.getProduct().getName());

        if (item.getProduct().getImageUrl() != null) {
            JLabel imageLabel = new JLabel("400 x 400");
            imageLabel.setPreferredSize(new Dimension(80, 80));
            imageLabel.setBackground(Color.LIGHT_GRAY);
            imageLabel.setOpaque(true);
            productPanel.add(imageLabel, BorderLayout.WEST);
        }
        productPanel.add(nameLabel, BorderLayout.CENTER);

        double originalPrice = item.getProduct().getPrice();
        double discount = item.getProduct().getDiscountPercentage();
        double finalPrice = originalPrice * (1 - discount/100.0);

        JLabel priceLabel = new JLabel("RP " + String.format("%,d", (int)finalPrice));
        if (discount > 0) {
            priceLabel.setText(String.format("<html>RP %,d<br/>-%d%%</html>",
                    (int)finalPrice, (int)discount));
        }
        priceLabel.setForeground(Color.RED);

        JPanel quantityPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        JButton minusButton = new JButton("-");
        JTextField quantityField = new JTextField(String.valueOf(item.getQuantity()), 3);
        quantityField.setHorizontalAlignment(JTextField.CENTER);
        JButton plusButton = new JButton("+");

        minusButton.addActionListener(e -> updateQuantity(item, item.getQuantity() - 1));
        plusButton.addActionListener(e -> updateQuantity(item, item.getQuantity() + 1));

        quantityPanel.add(minusButton);
        quantityPanel.add(quantityField);
        quantityPanel.add(plusButton);

        double totalItemPrice = finalPrice * item.getQuantity();
        JLabel totalLabel = new JLabel("RP " + String.format("%,d", (int)totalItemPrice));
        totalLabel.setForeground(Color.RED);

        JButton deleteButton = new JButton("Hapus");
        deleteButton.setForeground(Color.BLACK);
        deleteButton.addActionListener(e -> removeItem(item));

        panel.add(productPanel);
        panel.add(priceLabel);
        panel.add(quantityPanel);
        panel.add(totalLabel);
        panel.add(deleteButton);

        return panel;
    }

    private void updateQuantity(CartItem item, int newQuantity) {
        if (newQuantity > 0 && newQuantity <= item.getProduct().getStock()) {
            try {
                cartDAO.updateQuantity(item.getCartItemId(), newQuantity);
                loadCartItems();
                refreshView();
            } catch (SQLException e) {
                JOptionPane.showMessageDialog(this,
                        "Error updating quantity: " + e.getMessage(),
                        "Database Error",
                        JOptionPane.ERROR_MESSAGE);
            }
        } else {
            JOptionPane.showMessageDialog(this,
                    "Invalid quantity. Must be between 1 and available stock.",
                    "Error",
                    JOptionPane.WARNING_MESSAGE);
        }
    }

    private void removeItem(CartItem item) {
        int confirm = JOptionPane.showConfirmDialog(this,
                "Are you sure you want to remove this item?",
                "Confirm Remove",
                JOptionPane.YES_NO_OPTION);

        if (confirm == JOptionPane.YES_OPTION) {
            try {
                cartDAO.deleteItem(item.getCartItemId());
                loadCartItems();
                refreshView();
            } catch (SQLException e) {
                JOptionPane.showMessageDialog(this,
                        "Error removing item: " + e.getMessage(),
                        "Database Error",
                        JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private void refreshView() {
        removeAll();
        createComponents();
        revalidate();
        repaint();
    }

    private void createFooterPanel() {
        JPanel footerPanel = new JPanel(new BorderLayout());
        footerPanel.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));

        totalLabel = new JLabel("Total: RP " + String.format("%,d", (int)totalPrice));
        totalLabel.setFont(new Font("Arial", Font.BOLD, 16));

        JButton checkoutButton = new JButton("CHECKOUT");
        checkoutButton.setBackground(Color.RED);
        checkoutButton.setForeground(Color.WHITE);
        checkoutButton.setPreferredSize(new Dimension(120, 40));

        checkoutButton.addActionListener(e -> handleCheckout());

        footerPanel.add(totalLabel, BorderLayout.WEST);
        footerPanel.add(checkoutButton, BorderLayout.EAST);
        add(footerPanel, BorderLayout.SOUTH);
    }

    private void handleCheckout() {
        if (cartItems.isEmpty()) {
            JOptionPane.showMessageDialog(this,
                    "Keranjang belanja masih kosong!",
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
            return;
        }

        Component comp = this;
        while (!(comp instanceof Main) && comp != null) {
            comp = comp.getParent();
        }
        if (comp instanceof Main) {
            ((Main) comp).showCard("Checkout");
        }
    }
}
