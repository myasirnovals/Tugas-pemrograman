// package Tugas.TA;

public class Days {
    public static void main(String[] args) {
        String[] namahari = {
                "Senin", "Selasa", "Rabu", "Kammis", "Jumat", "Sabtu", "Minggu"
        };

        System.out.println("Tampilkan hari menggunakan for loop");
        for (int i = 0; i < namahari.length; i++) {
            System.out.print(namahari[i] + " ");
        }

        System.out.println("\nTampilkan hari menggunakan while loop");
        int i = 0;
        while (i < namahari.length) {
            System.out.print(namahari[i] + " ");
            i++;
        }
    }
}
