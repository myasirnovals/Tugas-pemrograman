package Tugas.V_1;

public class ArithmeticOperation {
    public static void main(String[] args) {
        if (args.length > 0) {
            int sum = 0;
            for (String arg : args) {
                sum += Integer.parseInt(arg);
            }
            System.out.println("sum = " + sum);

            int difference = Integer.parseInt(args[0]);
            for (int i = 1; i < args.length; i++) {
                difference -= Integer.parseInt(args[i]);
            }
            System.out.println("difference = " + difference);

            int product = Integer.parseInt(args[0]);
            for (int i = 1; i < args.length; i++) {
                product *= Integer.parseInt(args[i]);
            }
            System.out.println("product = " + product);

            int quotient = Integer.parseInt(args[0]);
            for (int i = 1; i < args.length; i++) {
                quotient /= Integer.parseInt(args[i]);
            }
            System.out.println("quotient = " + quotient);
        }
    }
}
