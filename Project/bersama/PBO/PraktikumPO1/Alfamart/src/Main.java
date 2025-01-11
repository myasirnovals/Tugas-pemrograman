import javax.swing.*;

public class Main extends JFrame {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            AlfamartECommerce frame = new AlfamartECommerce();
            frame.setVisible(true);
        });
    }
}