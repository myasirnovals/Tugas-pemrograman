package dao;

import model.ContactMessage;
import database.DBConnection;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ContactMessageDAO {
    private Connection connection;

    public ContactMessageDAO() {
        connection = DBConnection.getConnection();
    }

    public boolean save(ContactMessage message) throws SQLException {
        String sql = "INSERT INTO contact_messages (name, phone, email, message) VALUES (?, ?, ?, ?)";

        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            stmt.setString(1, message.getName());
            stmt.setString(2, message.getPhone());
            stmt.setString(3, message.getEmail());
            stmt.setString(4, message.getMessage());

            return stmt.executeUpdate() > 0;
        }
    }

    public List<ContactMessage> getAllMessages() throws SQLException {
        List<ContactMessage> messages = new ArrayList<>();
        String sql = "SELECT * FROM contact_messages ORDER BY created_at DESC";

        try (Statement stmt = connection.createStatement();
             ResultSet rs = stmt.executeQuery(sql)) {

            while (rs.next()) {
                ContactMessage message = new ContactMessage(
                        rs.getInt("message_id"),
                        rs.getString("name"),
                        rs.getString("phone"),
                        rs.getString("email"),
                        rs.getString("message"),
                        rs.getTimestamp("created_at")
                );
                messages.add(message);
            }
        }
        return messages;
    }
}
