package Program.III_1;

import java.util.Scanner;

public class Addition {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num1;
        int num2;
        int sum;

        System.out.print("Masukan nilai integer pertama = ");
        num1 = input.nextInt();

        System.out.print("Masukan nilai integer kedua = ");
        num2 = input.nextInt();

        sum = num1 + num2;

        System.out.println("Hasil penjumlahannya adalah " + sum);
    }
}
