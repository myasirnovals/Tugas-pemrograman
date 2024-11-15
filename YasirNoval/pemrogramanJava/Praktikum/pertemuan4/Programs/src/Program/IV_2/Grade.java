// package Program.IV_2;

import java.util.Scanner;

public class Grade {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int grade;

        System.out.print("Masukan grade: ");
        grade = input.nextInt();

        if (grade > 60) {
            System.out.println("Selamat!");
        } else {
            System.out.println("Coba lagi!");
        }
    }
}
