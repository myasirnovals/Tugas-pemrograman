import dao.CartDAO;
import dao.OrderDAO;
import model.CartItem;
import model.Order;

import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class CheckoutView extends JPanel {
    private JPanel cartItemsPanel;
    private JLabel totalLabel;
    private JLabel changeLabel;
    private JTextField nameField;
    private JTextField phoneField;
    private JTextField moneyField;
    private CartDAO cartDAO;
    private double totalAmount = 0.0;
    private OrderDAO orderDAO;
    private ArrayList<CartItem> cartItems;
    private JButton confirmButton;

    public CheckoutView() {
        orderDAO = new OrderDAO();
        cartDAO = new CartDAO();
        cartItems = new ArrayList<>();
        setLayout(new BorderLayout(10, 10));
        setBorder(new EmptyBorder(20, 20, 20, 20));

        totalLabel = new JLabel("Total: Rp 0");
        totalLabel.setFont(new Font("Arial", Font.BOLD, 16));

        confirmButton = new JButton("Konfirmasi Pesanan");
        confirmButton.addActionListener(e -> handleCheckout());

        // Panel untuk form checkout
        JPanel formPanel = createFormPanel();

        // Panel untuk items
        cartItemsPanel = new JPanel();
        cartItemsPanel.setLayout(new BoxLayout(cartItemsPanel, BoxLayout.Y_AXIS));
        JScrollPane scrollPane = new JScrollPane(cartItemsPanel);
        scrollPane.setPreferredSize(new Dimension(400, 300));

        // Load cart items
        loadCartItems();

        // Panel untuk total dan tombol
        JPanel bottomPanel = createBottomPanel();

        // Menambahkan komponen ke panel utama
        add(new JLabel("Checkout", SwingConstants.CENTER), BorderLayout.NORTH);
        add(scrollPane, BorderLayout.CENTER);
        add(formPanel, BorderLayout.EAST);
        add(bottomPanel, BorderLayout.SOUTH);
    }

    private JPanel createFormPanel() {
        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        panel.setBorder(BorderFactory.createTitledBorder("Informasi Pesanan"));
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.fill = GridBagConstraints.HORIZONTAL;
        gbc.insets = new Insets(5, 5, 5, 5);

        // Nama
        gbc.gridx = 0;
        gbc.gridy = 0;
        panel.add(new JLabel("Nama:"), gbc);
        nameField = new JTextField(20);
        gbc.gridx = 1;
        panel.add(nameField, gbc);

        // Nomor Telepon
        gbc.gridx = 0;
        gbc.gridy = 1;
        panel.add(new JLabel("No. Telepon:"), gbc);
        phoneField = new JTextField(20);
        gbc.gridx = 1;
        panel.add(phoneField, gbc);

        // Uang Dibayarkan
        gbc.gridx = 0;
        gbc.gridy = 2;
        panel.add(new JLabel("Uang Dibayarkan:"), gbc);
        moneyField = new JTextField(20);
        gbc.gridx = 1;
        panel.add(moneyField, gbc);

        // Label Kembalian
        gbc.gridx = 0;
        gbc.gridy = 3;
        gbc.gridwidth = 2;
        changeLabel = new JLabel("Kembalian: Rp 0");
        changeLabel.setFont(new Font("Arial", Font.BOLD, 14));
        panel.add(changeLabel, gbc);

        // Tambah listener untuk moneyField
        moneyField.addKeyListener(new KeyAdapter() {
            @Override
            public void keyReleased(KeyEvent e) {
                calculateChange();
            }
        });

        return panel;
    }

    private void calculateChange() {
        try {
            String moneyText = moneyField.getText().replaceAll("[^0-9]", "");
            double moneyPaid = Double.parseDouble(moneyText);
            double change = moneyPaid - totalAmount;

            if (change >= 0) {
                changeLabel.setText(String.format("Kembalian: Rp %,.0f", change));
                changeLabel.setForeground(Color.BLACK);
            } else {
                changeLabel.setText(String.format("Kurang: Rp %,.0f", Math.abs(change)));
                changeLabel.setForeground(Color.RED);
            }
        } catch (NumberFormatException ex) {
            changeLabel.setText("Kembalian: Rp 0");
            changeLabel.setForeground(Color.BLACK);
        }
    }

    private JPanel createBottomPanel() {
        JPanel panel = new JPanel(new BorderLayout());
        panel.setBorder(new EmptyBorder(10, 0, 0, 0));

        // Panel kiri untuk total
        panel.add(totalLabel, BorderLayout.WEST);

        // Panel kanan untuk tombol-tombol
        JPanel buttonPanel = new JPanel(new FlowLayout(FlowLayout.RIGHT, 10, 0));

        // Tombol Refresh
        JButton refreshButton = new JButton("Refresh");
        refreshButton.addActionListener(e -> loadCartItems());

        // Tombol Kembali
        JButton backButton = new JButton("Kembali");
        backButton.addActionListener(e -> navigateToCart());

        // Tambahkan semua tombol ke panel tombol
        buttonPanel.add(refreshButton);    // Tambah tombol refresh
        buttonPanel.add(backButton);       // Tombol kembali
        buttonPanel.add(confirmButton);    // Tombol konfirmasi

        panel.add(buttonPanel, BorderLayout.EAST);

        return panel;
    }

    private void loadCartItems() {
        cartItemsPanel.removeAll();
        totalAmount = 0.0;
        cartItems.clear(); // Tambahkan ini

        try {
            List<CartItem> items = cartDAO.getAllCartItems();
            cartItems.addAll(items); // Tambahkan ini

            for (CartItem item : items) {
                JPanel itemPanel = createCartItemPanel(item);
                cartItemsPanel.add(itemPanel);
                cartItemsPanel.add(Box.createRigidArea(new Dimension(0, 5)));

                totalAmount += item.getProduct().getPrice() * item.getQuantity();
            }

            totalLabel.setText(String.format("Total: Rp %,.0f", totalAmount));

        } catch (SQLException e) {
            JOptionPane.showMessageDialog(this,
                    "Error loading cart items: " + e.getMessage(),
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
        }

        cartItemsPanel.revalidate();
        cartItemsPanel.repaint();
    }

    private JPanel createCartItemPanel(CartItem item) {
        JPanel panel = new JPanel();
        panel.setLayout(new BorderLayout(10, 0));
        panel.setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY));
        panel.setMaximumSize(new Dimension(Integer.MAX_VALUE, 60));

        // Informasi produk
        JPanel infoPanel = new JPanel(new GridLayout(2, 1));
        infoPanel.add(new JLabel(item.getProduct().getName()));
        infoPanel.add(new JLabel(String.format("Rp %,.0f x %d",
                item.getProduct().getPrice(),
                item.getQuantity())));

        // Total harga item
        JLabel totalItem = new JLabel(String.format("Rp %,.0f",
                item.getProduct().getPrice() * item.getQuantity()));

        panel.add(infoPanel, BorderLayout.CENTER);
        panel.add(totalItem, BorderLayout.EAST);

        return panel;
    }

    private void handleCheckout() {
        if (validateForm()) {
            try {
                double moneyPaid = Double.parseDouble(moneyField.getText().replaceAll("[^0-9]", ""));
                double change = moneyPaid - totalAmount;

                int confirm = JOptionPane.showConfirmDialog(this,
                        String.format("Detail Pembayaran:\n" +
                                        "Total Belanja: Rp %,.0f\n" +
                                        "Uang Dibayar: Rp %,.0f\n" +
                                        "Kembalian: Rp %,.0f\n\n" +
                                        "Lanjutkan checkout?",
                                totalAmount, moneyPaid, change),
                        "Konfirmasi Checkout",
                        JOptionPane.YES_NO_OPTION);

                if (confirm == JOptionPane.YES_OPTION) {
                    Order order = new Order();
                    order.setCustomerName(nameField.getText().trim());
                    order.setPhone(phoneField.getText().trim());
                    order.setTotalAmount(totalAmount);
                    order.setPaymentAmount(moneyPaid);    // Tambah payment amount
                    order.setChangeAmount(change);        // Tambah change amount
                    order.setItems(cartItems);

                    if (orderDAO.createOrder(order)) {
                        JOptionPane.showMessageDialog(this,
                                String.format("Pesanan berhasil dibuat!\n" +
                                                "Total: Rp %,.0f\n" +
                                                "Dibayar: Rp %,.0f\n" +    // Tambah informasi pembayaran
                                                "Kembalian: Rp %,.0f",
                                        totalAmount, moneyPaid, change),
                                "Sukses",
                                JOptionPane.INFORMATION_MESSAGE);

                        resetForm();
                        navigateToCart();
                    }
                }
            } catch (SQLException e) {
                JOptionPane.showMessageDialog(this,
                        "Error saat membuat pesanan: " + e.getMessage(),
                        "Error",
                        JOptionPane.ERROR_MESSAGE);
            }
        }
    }

    private void resetForm() {
        nameField.setText("");
        phoneField.setText("");
        moneyField.setText("");
        cartItems.clear();
        loadCartItems();
    }

    private void navigateToCart() {
        Component comp = this;
        while (!(comp instanceof Main) && comp != null) {
            comp = comp.getParent();
        }
        if (comp instanceof Main) {
            ((Main) comp).showCard("Keranjang");
        }
    }

    private boolean validateForm() {
        String name = nameField.getText().trim();
        String phone = phoneField.getText().trim();
        String money = moneyField.getText().trim();

        if (name.isEmpty()) {
            JOptionPane.showMessageDialog(this,
                    "Nama harus diisi!",
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
            nameField.requestFocus();
            return false;
        }

        if (phone.isEmpty()) {
            JOptionPane.showMessageDialog(this,
                    "Nomor telepon harus diisi!",
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
            phoneField.requestFocus();
            return false;
        }

        if (!phone.matches("^[0-9]{10,13}$")) {
            JOptionPane.showMessageDialog(this,
                    "Nomor telepon tidak valid!\nHarus berisi 10-13 digit angka.",
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
            phoneField.requestFocus();
            return false;
        }

        if (money.isEmpty()) {
            JOptionPane.showMessageDialog(this,
                    "Jumlah pembayaran harus diisi!",
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
            moneyField.requestFocus();
            return false;
        }

        try {
            double moneyPaid = Double.parseDouble(money.replaceAll("[^0-9]", ""));
            if (moneyPaid < totalAmount) {
                JOptionPane.showMessageDialog(this,
                        "Pembayaran kurang!\nTotal yang harus dibayar: Rp " +
                                String.format("%,.0f", totalAmount),
                        "Error",
                        JOptionPane.ERROR_MESSAGE);
                moneyField.requestFocus();
                return false;
            }
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this,
                    "Format pembayaran tidak valid!",
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
            moneyField.requestFocus();
            return false;
        }

        if (cartItems.isEmpty()) {
            JOptionPane.showMessageDialog(this,
                    "Keranjang belanja kosong!",
                    "Error",
                    JOptionPane.ERROR_MESSAGE);
            return false;
        }

        return true;
    }
}
