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

        cardLayout = new CardLayout();
        mainPanel = new JPanel(cardLayout);

        mainPanel.add(createProductPanel(), "Produk");
        mainPanel.add(createFlashSalePanel(), "Promosi");
        mainPanel.add(createCartPanel(), "Keranjang");
        mainPanel.add(createContactPanel(), "Hubungi Kami");
        mainPanel.add(new CheckoutView(), "Checkout");

        add(mainPanel, BorderLayout.CENTER);
    }

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
