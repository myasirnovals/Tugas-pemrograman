public class ConditionalOperator {
    public static void main(String[] args) {
        String status = "";
        int grade = 80;

        // Status dari siswa
        status = (grade >= 60) ? "Passed" : "Fail";

        // Cetak status
        System.out.println(status);
    }
}
