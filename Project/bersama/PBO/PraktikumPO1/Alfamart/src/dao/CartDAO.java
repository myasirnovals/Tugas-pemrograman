package dao;

import model.CartItem;
import model.Product;
import database.DBConnection;
import java.sql.*;
import java.util.ArrayList;

public class CartDAO {
    private final ProductDAO productDAO;

    public CartDAO() {
        this.productDAO = new ProductDAO();
    }

    public ArrayList<CartItem> getAllCartItems() throws SQLException {
        ArrayList<CartItem> cartItems = new ArrayList<>();
        String query = "SELECT * FROM cart_items";

        try (Connection connection = DBConnection.getConnection();
             Statement stmt = connection.createStatement();
             ResultSet rs = stmt.executeQuery(query)) {

            while (rs.next()) {
                int cartItemId = rs.getInt("cart_item_id");
                int productId = rs.getInt("product_id");
                int quantity = rs.getInt("quantity");

                // Menggunakan method getProductById yang baru
                Product product = productDAO.getProductById(productId);

                if (product != null) {
                    CartItem item = new CartItem(cartItemId, product, quantity);
                    item.setCreatedAt(rs.getString("created_at"));
                    cartItems.add(item);
                }
            }
        }
        return cartItems;
    }

    public void updateQuantity(int cartItemId, int newQuantity) throws SQLException {
        String query = "UPDATE cart_items SET quantity = ? WHERE cart_item_id = ?";

        try (Connection connection = DBConnection.getConnection();
             PreparedStatement stmt = connection.prepareStatement(query)) {

            stmt.setInt(1, newQuantity);
            stmt.setInt(2, cartItemId);
            stmt.executeUpdate();
        }
    }

    public void deleteItem(int cartItemId) throws SQLException {
        String query = "DELETE FROM cart_items WHERE cart_item_id = ?";

        try (Connection connection = DBConnection.getConnection();
             PreparedStatement stmt = connection.prepareStatement(query)) {

            stmt.setInt(1, cartItemId);
            stmt.executeUpdate();
        }
    }

}
