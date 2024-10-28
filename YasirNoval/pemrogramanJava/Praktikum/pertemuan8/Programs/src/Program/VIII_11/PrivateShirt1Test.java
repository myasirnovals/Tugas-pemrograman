package Program.VIII_11;

import Program.VIII_10.PrivateShirt1;

public class PrivateShirt1Test {
    public static void main(String[] args) {
        PrivateShirt1 privateShirt1 = new PrivateShirt1();
        char kodeWarna;
        // Mengisi kode warna yang valid
        privateShirt1.setKodeWarna('R');
        kodeWarna = privateShirt1.getKodeWarna();
        // kelas PrivateShirt1Test bisa mengisi sebuah kodeWarna yang valid
        System.out.println("Kode Warna: " + kodeWarna);
        // mengisi kode warna yang salah
        privateShirt1.setKodeWarna('Z');
        kodeWarna = privateShirt1.getKodeWarna();
        // kelas PrivateShirt1Test bisa mengisi sebuah kodeWarna yang salah
        System.out.println("Kode Warna: " + kodeWarna);
    }
}
