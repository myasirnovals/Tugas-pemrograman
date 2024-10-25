package Program.III_2;

import javax.swing.*;

public class ConditionalOperatorGUI {
    public static void main(String[] args) {
        String grade = JOptionPane.showInputDialog("Masukan Grade");
        String status = "";

        // Status dari siswa
        status = (Double.parseDouble(grade) >= 60) ? "Passed" : "Fail";

        // Cetak status
        JOptionPane.showMessageDialog(null, status);
    }
}
