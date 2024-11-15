 package Tugas.IV_3;

import java.util.Scanner;

public class GradeElseIf {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int grade;

        System.out.print("Masukan grade: ");
        grade = input.nextInt();

        if (grade >= 60) {
            System.out.println("LULUS!");
        } else if (grade > 33){
            System.out.println("GAGAL");
        } else {
            System.out.println("Anda salah jurusan");
        }
    }
}
