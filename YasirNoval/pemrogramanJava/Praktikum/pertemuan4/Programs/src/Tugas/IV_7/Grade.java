 package Tugas.IV_7;

import java.util.Scanner;

public class Grade {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        System.out.println("Masukan nilai grade: ");
        double grade = input.nextDouble();

        if (grade >= 90) {
            System.out.println("Excellent!");
        } else if ((grade < 90) && (grade >= 80)) {
            System.out.println("Bagus!");
        } else if ((grade < 80) && (grade >= 60)) {
            System.out.println("Belajar lagi!");
        } else {
            System.out.println("Maaf, Anda gagal.");
        }
    }
}
