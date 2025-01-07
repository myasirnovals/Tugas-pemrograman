import javax.swing.*;

public class Main extends JFrame {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            AlfamartECommerce app = new AlfamartECommerce();
            app.setVisible(true);
        });
    }
}