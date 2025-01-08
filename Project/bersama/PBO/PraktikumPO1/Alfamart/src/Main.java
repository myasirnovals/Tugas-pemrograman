import javax.swing.*;

public class Main extends JFrame {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            ProductDetail frame = new ProductDetail();
            frame.setVisible(true);
        });
    }
}