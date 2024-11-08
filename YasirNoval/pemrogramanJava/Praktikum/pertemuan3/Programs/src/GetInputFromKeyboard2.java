import javax.swing.*;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class GetInputFromKeyboard2 {
    public static void main(String[] args) {
        BufferedReader dataIn = new BufferedReader(new InputStreamReader(System.in));
        String name = "", hobby = "";

        name = JOptionPane.showInputDialog("Your name: ");
        hobby = JOptionPane.showInputDialog("Your hobby: ");

        String msg = ("So your hobby is " + hobby + ", nice hobby mister." + name);
        JOptionPane.showMessageDialog(null, msg);

        System.out.println("So your hobby is " + hobby + ", nice hobby mister." + name);
    }
}
