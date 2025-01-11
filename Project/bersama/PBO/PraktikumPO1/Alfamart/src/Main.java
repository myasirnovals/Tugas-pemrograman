import javax.swing.*;
import java.awt.*;

public class Main extends JFrame {
    private CardLayout cardLayout;
    private JPanel mainPanel;

    public Main() {
        setTitle("Alfamart E-Commerce");
        setSize(800, 600);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // CardLayout untuk halaman
        cardLayout = new CardLayout();
        mainPanel = new JPanel(cardLayout);

        // Tambahkan halaman ke CardLayout
        mainPanel.add(createProductPanel(), "Produk");
        mainPanel.add(createFlashSalePanel(), "Promosi");
        mainPanel.add(createCartPanel(), "Keranjang");
        mainPanel.add(createContactPanel(), "Hubungi Kami");

        add(mainPanel, BorderLayout.CENTER);
    }

    // Method helper untuk membuat panel
    private JPanel createProductPanel() {
        return new AlfamartECommerce();
    }

    private JPanel createFlashSalePanel() {
        return new FlashSaleView();
    }

    private JPanel createCartPanel() {
        return new CartView();
    }

    private JPanel createContactPanel() {
        return new ContactForm();
    }

    // Tambahkan method untuk mengakses cardLayout dari panel lain
    public void showCard(String name) {
        cardLayout.show(mainPanel, name);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            Main frame = new Main();
            frame.setVisible(true);
        });
    }
}
