package Program.IV_6;

import java.util.Scanner;

public class LessOrGreaterThreeValues {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int values1, values2, values3;

        System.out.print("Masukan value ke-1: ");
        values1 = input.nextInt();

        System.out.print("Masukan value ke-2: ");
        values2 = input.nextInt();

        System.out.print("Masukan value ke-3: ");
        values3 = input.nextInt();

        if (values1 > values2) {
            System.out.println(Math.max(values1, values3));
        } else {
            System.out.println(Math.max(values2, values3));
        }
    }
}

