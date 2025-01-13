package dao;

import model.Order;
import model.CartItem;
import database.DBConnection;
import java.sql.*;

public class OrderDAO {
    private CartDAO cartDAO;

    public OrderDAO() {
        this.cartDAO = new CartDAO();
    }

    public boolean createOrder(Order order) throws SQLException {
        Connection connection = null;
        PreparedStatement orderStmt = null;
        PreparedStatement itemStmt = null;
        ResultSet generatedKeys = null;

        try {
            connection = DBConnection.getConnection();
            connection.setAutoCommit(false); // Start transaction

            // Insert order - Perubahan query untuk menyesuaikan dengan struktur baru
            String orderQuery = "INSERT INTO orders (customer_name, phone, payment_amount, change_amount, total_amount) VALUES (?, ?, ?, ?, ?)";
            orderStmt = connection.prepareStatement(orderQuery, Statement.RETURN_GENERATED_KEYS);
            orderStmt.setString(1, order.getCustomerName());
            orderStmt.setString(2, order.getPhone());
            orderStmt.setDouble(3, order.getPaymentAmount());    // Field baru
            orderStmt.setDouble(4, order.getChangeAmount());     // Field baru
            orderStmt.setDouble(5, order.getTotalAmount());
            orderStmt.executeUpdate();

            // Get generated order ID
            generatedKeys = orderStmt.getGeneratedKeys();
            if (!generatedKeys.next()) {
                throw new SQLException("Creating order failed, no ID obtained.");
            }
            int orderId = generatedKeys.getInt(1);

            // Insert order items
            String itemQuery = "INSERT INTO order_items (order_id, product_id, quantity, price) VALUES (?, ?, ?, ?)";
            itemStmt = connection.prepareStatement(itemQuery);

            for (CartItem item : order.getItems()) {
                itemStmt.setInt(1, orderId);
                itemStmt.setInt(2, item.getProduct().getProductId());
                itemStmt.setInt(3, item.getQuantity());
                itemStmt.setDouble(4, item.getProduct().getPrice());
                itemStmt.executeUpdate();
            }

            // Clear cart items
            String clearCartQuery = "DELETE FROM cart_items";
            Statement clearCartStmt = connection.createStatement();
            clearCartStmt.executeUpdate(clearCartQuery);

            connection.commit(); // Commit transaction
            return true;

        } catch (SQLException e) {
            if (connection != null) {
                try {
                    connection.rollback(); // Rollback on error
                } catch (SQLException ex) {
                    ex.printStackTrace();
                }
            }
            throw e;
        } finally {
            if (generatedKeys != null) generatedKeys.close();
            if (itemStmt != null) itemStmt.close();
            if (orderStmt != null) orderStmt.close();
            if (connection != null) {
                connection.setAutoCommit(true);
                connection.close();
            }
        }
    }
}
