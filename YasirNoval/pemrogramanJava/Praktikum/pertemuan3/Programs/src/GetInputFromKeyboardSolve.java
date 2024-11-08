import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class GetInputFromKeyboardSolve {
    public static void main(String[] args) {
        BufferedReader dataIn = new BufferedReader(new InputStreamReader(System.in));

        String name = "";
        System.out.println("Please Enter Your Name: ");

        try {
            name = dataIn.readLine();
        } catch (IOException e) {
            // Todo Auto-generated catch block
            e.printStackTrace();
        }

        System.out.println("Hello " + name + "!");
    }
}
