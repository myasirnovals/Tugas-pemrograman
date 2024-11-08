import javax.swing.*;
import java.text.NumberFormat;
import java.text.ParsePosition;

public class IntroductionGUIApp {
    public static void main(String[] args) {
        int result;

        String value1 = JOptionPane.showInputDialog("Input value 1 [Integer]");
        String value2 = JOptionPane.showInputDialog("Input value 2 [Integer]");

        if (isNumeric(value1) && isNumeric(value2)) {
            if (Integer.parseInt(value2) != 0) {
                String operator = JOptionPane.showInputDialog("Input operator [+, -, *, /]");
                switch (operator) {
                    case "+":
                        result = Integer.parseInt(value1) + Integer.parseInt(value2);
                        break;
                    case "-":
                        result = Integer.parseInt(value1) - Integer.parseInt(value2);
                        break;
                    case "*":
                        result = Integer.parseInt(value1) * Integer.parseInt(value2);
                        break;
                    case "/":
                        result = Integer.parseInt(value1) / Integer.parseInt(value2);
                        break;
                    default:
                        System.out.println("Are you sick bro?");
                        return;
                }
            } else {
                System.out.println("Error: Can't divide by zero 0");
                return;
            }
        } else {
            System.out.println("Are you sick bro?");
            return;
        }

        // Cetak status
        JOptionPane.showMessageDialog(null, result);
    }

    public static boolean isNumeric(String s) {
        ParsePosition position = new ParsePosition(0);
        NumberFormat.getInstance().parse(s, position);
        return s.length() == position.getIndex();
    }
}
