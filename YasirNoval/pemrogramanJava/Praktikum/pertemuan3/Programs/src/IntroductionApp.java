import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class IntroductionApp {
    public static void main(String[] args) throws IOException {
        BufferedReader dataIn = new BufferedReader(new InputStreamReader(System.in));

        String name = "";
        String hobby = "";

        System.out.print("Please Enter Your Name: ");
        name = dataIn.readLine();

        System.out.print("Please Enter Your Hobby: ");
        hobby = dataIn.readLine();

        System.out.println("So your hobby is " + hobby + ". Nice hobby Mr." + name);
    }
}
