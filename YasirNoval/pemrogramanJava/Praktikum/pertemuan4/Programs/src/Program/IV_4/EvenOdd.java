// package Program.IV_4;

import java.util.Scanner;

public class EvenOdd {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int angka;

        System.out.print("Masukan angka: ");
        angka = input.nextInt();

        if (angka > 0) {
            if (angka % 2 == 0) {
                System.out.println("EVEN");
            } else {
                System.out.println("ODD");
            }
        } else {
            System.out.println("Bukan bilangan bulat positif yang lebih dari nol");
        }
    }
}
