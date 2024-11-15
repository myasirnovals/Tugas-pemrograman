// package Program.IV_5;

import java.util.Scanner;

public class LessOrGreater {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int value1, value2;

        System.out.print("Masukan value1: ");
        value1 = input.nextInt();

        System.out.print("Masukan value2: ");
        value2 = input.nextInt();

        if (value1 > value2) {
            System.out.println(value1);
        } else {
            System.out.println(value2);
        }
    }
}
