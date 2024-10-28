package Program.IV_7;

public class Grade {
    public static void main(String[] args) {
        double grade = 92.0;
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
