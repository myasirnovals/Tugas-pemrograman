package model;

import java.sql.Timestamp;

public class ContactMessage {
    private int messageId;
    private String name;
    private String phone;
    private String email;
    private String message;
    private Timestamp createdAt;

    public ContactMessage(String name, String phone, String email, String message) {
        this.name = name;
        this.phone = phone;
        this.email = email;
        this.message = message;
    }

    public ContactMessage(int messageId, String name, String phone,
                          String email, String message, Timestamp createdAt) {
        this.messageId = messageId;
        this.name = name;
        this.phone = phone;
        this.email = email;
        this.message = message;
        this.createdAt = createdAt;
    }

    public int getMessageId() {
        return messageId;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }

    public Timestamp getCreatedAt() {
        return createdAt;
    }
}
