package Program.IV_8;

public class GradeCaseOf {
    public static void main(String[] args) {
        int grade = 92;
        switch (grade) {
            case 100:
                System.out.println("Excellent!");
                break;
            case 90:
                System.out.println("Bagus!");
                break;
            case 80:
                System.out.println("Belajar lagi!!");
                break;
            default:
                System.out.println("Maaf, Anda gagal.");
        }
    }
}
