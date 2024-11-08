import java.util.Scanner;

public class ArithmeticApp {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        Arithmetic arithmetic = new Arithmetic();

        System.out.print("Input value 1: ");
        arithmetic.setValue1(input.nextDouble());

        System.out.print("Input value 2: ");
        arithmetic.setValue2(input.nextDouble());

        System.out.println("Plus: " + arithmetic.plus());
        System.out.println("Minus: " + arithmetic.minus());
        System.out.println("Multiply: " + arithmetic.multiply());

        if (arithmetic.getValue2() != 0) {
            System.out.println("Divide: " + arithmetic.divide());
        } else {
            System.out.println("Error: Can't divide by zero 0");
        }
    }
}
