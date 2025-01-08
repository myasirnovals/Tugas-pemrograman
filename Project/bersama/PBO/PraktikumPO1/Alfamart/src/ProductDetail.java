import javax.swing.*;
import java.awt.*;
import javax.swing.border.*;

public class ProductDetail extends JFrame {
    public ProductDetail() {
        setTitle("Alfamart E-Commerce");
        setSize(1000, 700);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBackground(new Color(240, 240, 240));

        // Header Panel
        JPanel headerPanel = createHeaderPanel();
        add(headerPanel, BorderLayout.NORTH);

        // Main Content Panel
        JPanel mainPanel = new JPanel(new BorderLayout(20, 0));
        mainPanel.setBackground(new Color(240, 240, 240));
        mainPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        // Left Panel (Product Images)
        JPanel leftPanel = createProductImagePanel();
        mainPanel.add(leftPanel, BorderLayout.WEST);

        // Right Panel (Product Details)
        JPanel rightPanel = createProductDetailsPanel();
        mainPanel.add(rightPanel, BorderLayout.CENTER);

        // Related Products Panel
        JPanel relatedPanel = createRelatedProductsPanel();
        mainPanel.add(relatedPanel, BorderLayout.SOUTH);

        add(mainPanel, BorderLayout.CENTER);
    }

    private JPanel createHeaderPanel() {
        JPanel headerPanel = new JPanel(new BorderLayout());
        headerPanel.setBackground(Color.RED);
        headerPanel.setPreferredSize(new Dimension(1000, 60));
        headerPanel.setBorder(BorderFactory.createEmptyBorder(10, 20, 10, 20));

        // Logo
        JLabel logoLabel = new JLabel("ALFAMART");
        logoLabel.setForeground(Color.WHITE);
        logoLabel.setFont(new Font("Arial", Font.BOLD, 20));

        // Search Panel
        JPanel searchPanel = new JPanel(new BorderLayout());
        searchPanel.setBackground(Color.RED);
        JTextField searchField = new JTextField("cari produk....");
        searchField.setPreferredSize(new Dimension(300, 30));
        JButton searchButton = new JButton("Q");
        searchButton.setBackground(Color.WHITE);

        // Cart Button
        JButton cartButton = new JButton("🛒");
        cartButton.setBackground(Color.WHITE);

        // Add components to header
        headerPanel.add(logoLabel, BorderLayout.WEST);
        searchPanel.add(searchField, BorderLayout.CENTER);
        searchPanel.add(searchButton, BorderLayout.EAST);
        headerPanel.add(searchPanel, BorderLayout.CENTER);
        headerPanel.add(cartButton, BorderLayout.EAST);

        return headerPanel;
    }

    private JPanel createProductImagePanel() {
        JPanel imagePanel = new JPanel(new BorderLayout(0, 10));
        imagePanel.setBackground(Color.WHITE);
        imagePanel.setBorder(BorderFactory.createEmptyBorder(10, 10, 10, 10));
        imagePanel.setPreferredSize(new Dimension(400, 450));

        // Main Image
        JPanel mainImagePanel = new JPanel();
        mainImagePanel.setBackground(Color.LIGHT_GRAY);
        mainImagePanel.setPreferredSize(new Dimension(380, 380));
        JLabel imageLabel = new JLabel("400 x 400");
        mainImagePanel.add(imageLabel);

        // Thumbnail Panel
        JPanel thumbnailPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        thumbnailPanel.setBackground(Color.WHITE);
        for (int i = 0; i < 3; i++) {
            JPanel thumb = new JPanel();
            thumb.setPreferredSize(new Dimension(60, 60));
            thumb.setBackground(Color.LIGHT_GRAY);
            thumbnailPanel.add(thumb);
        }

        imagePanel.add(mainImagePanel, BorderLayout.CENTER);
        imagePanel.add(thumbnailPanel, BorderLayout.SOUTH);

        return imagePanel;
    }

    private JPanel createProductDetailsPanel() {
        JPanel detailsPanel = new JPanel();
        detailsPanel.setLayout(new BoxLayout(detailsPanel, BoxLayout.Y_AXIS));
        detailsPanel.setBackground(Color.WHITE);
        detailsPanel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));

        // Product Title
        JLabel titleLabel = new JLabel("INDOMIE GORENG");
        titleLabel.setFont(new Font("Arial", Font.BOLD, 24));

        // Rating Panel
        JPanel ratingPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        ratingPanel.setBackground(Color.WHITE);
        JLabel ratingLabel = new JLabel("⭐ 5.0 (999 Review) Stock: 101");
        ratingPanel.add(ratingLabel);

        // Price
        JLabel priceLabel = new JLabel("RP 4,000");
        priceLabel.setFont(new Font("Arial", Font.BOLD, 20));
        priceLabel.setForeground(Color.RED);

        // Description
        JLabel descLabel = new JLabel("Deskripsi Singkat");

        // Quantity Panel
        JPanel quantityPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        quantityPanel.setBackground(Color.WHITE);
        JButton minusButton = new JButton("-");
        JTextField quantityField = new JTextField("1", 3);
        quantityField.setHorizontalAlignment(JTextField.CENTER);
        JButton plusButton = new JButton("+");

        quantityPanel.add(minusButton);
        quantityPanel.add(quantityField);
        quantityPanel.add(plusButton);

        // Buttons Panel
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        buttonPanel.setBackground(Color.WHITE);
        JButton addToCartButton = new JButton("TAMBAH KE KERANJANG");
        addToCartButton.setBackground(Color.RED);
        addToCartButton.setForeground(Color.WHITE);
        JButton buyButton = new JButton("BELI");
        buyButton.setBackground(Color.WHITE);
        buyButton.setForeground(Color.RED);
        buyButton.setBorder(BorderFactory.createLineBorder(Color.RED));

        buttonPanel.add(addToCartButton);
        buttonPanel.add(buyButton);

        // Add all components
        detailsPanel.add(titleLabel);
        detailsPanel.add(Box.createRigidArea(new Dimension(0, 10)));
        detailsPanel.add(ratingPanel);
        detailsPanel.add(Box.createRigidArea(new Dimension(0, 10)));
        detailsPanel.add(priceLabel);
        detailsPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        detailsPanel.add(descLabel);
        detailsPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        detailsPanel.add(quantityPanel);
        detailsPanel.add(Box.createRigidArea(new Dimension(0, 20)));
        detailsPanel.add(buttonPanel);

        return detailsPanel;
    }

    private JPanel createRelatedProductsPanel() {
        JPanel relatedPanel = new JPanel(new BorderLayout());
        relatedPanel.setBackground(Color.WHITE);
        relatedPanel.setBorder(BorderFactory.createEmptyBorder(20, 0, 0, 0));

        JLabel titleLabel = new JLabel("PRODUK TERKAIT");
        titleLabel.setFont(new Font("Arial", Font.BOLD, 18));
        relatedPanel.add(titleLabel, BorderLayout.NORTH);

        JPanel productsPanel = new JPanel(new GridLayout(1, 4, 10, 0));
        productsPanel.setBackground(Color.WHITE);

        for (int i = 0; i < 4; i++) {
            JPanel productCard = createRelatedProductCard();
            productsPanel.add(productCard);
        }

        relatedPanel.add(productsPanel, BorderLayout.CENTER);
        return relatedPanel;
    }

    private JPanel createRelatedProductCard() {
        JPanel card = new JPanel();
        card.setLayout(new BoxLayout(card, BoxLayout.Y_AXIS));
        card.setBackground(Color.WHITE);
        card.setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY));

        // Image Panel
        JPanel imagePanel = new JPanel();
        imagePanel.setPreferredSize(new Dimension(100, 100));
        imagePanel.setBackground(Color.LIGHT_GRAY);
        JLabel imageLabel = new JLabel("400");
        imagePanel.add(imageLabel);

        // Product Info
        JLabel nameLabel = new JLabel("INDOMIE ACEH");
        JLabel priceLabel = new JLabel("RP 4,000");
        priceLabel.setForeground(Color.RED);

        card.add(imagePanel);
        card.add(Box.createRigidArea(new Dimension(0, 5)));
        card.add(nameLabel);
        card.add(priceLabel);

        return card;
    }
}