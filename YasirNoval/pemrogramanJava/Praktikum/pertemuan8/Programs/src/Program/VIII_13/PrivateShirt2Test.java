package Program.VIII_13;

import Program.VIII_12.PrivateShirt2;

public class PrivateShirt2Test {
    public static void main(String[] args) {
        PrivateShirt2 privateShirt2 = new PrivateShirt2();
        char kodeWarna;

        // mengisi kode warna yang valid
        privateShirt2.setKodeWarna('R');
        kodeWarna = privateShirt2.getKodeWarna();

        // kelas PrivateShirt2Test bisa
        // mengisi sebuah kodeWarna yang valid
        System.out.println("Kode Warna: " + kodeWarna);

        // mengisi kode warna yang salah
        privateShirt2.setKodeWarna('Z');
        kodeWarna = privateShirt2.getKodeWarna();

        // kelas PrivateShirt2Test bisa mengisi
        // sebuah kodeWarna yang salah
        // Kode Warna masih R
        System.out.println("Kode Warna: " + kodeWarna);
    }
}
