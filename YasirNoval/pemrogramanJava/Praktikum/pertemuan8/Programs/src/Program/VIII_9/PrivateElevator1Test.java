package Program.VIII_9;

import Program.VIII_8.PrivateElevator1;

public class PrivateElevator1Test {
    public static void main(String[] args) {
        PrivateElevator1 privateElevator1 = new PrivateElevator1();

        privateElevator1.setBukaPintu(true);    // penumpang masuk
        privateElevator1.setBukaPintu(false);   // pintu ditutup
        // pergi ke lantai 0 dibawah gedung
        privateElevator1.setLantaiSkrg(0);
        privateElevator1.setLantaiSkrg(1);

        // lompat ke lantai 7 (hanya ada 5 lantai dalam gedung)
        privateElevator1.setLantaiSkrg(7);
        privateElevator1.setBukaPintu(true);    // penumpang masuk/keluar
        privateElevator1.setBukaPintu(false);
        privateElevator1.setLantaiSkrg(1);  // menuju lantai pertama
        privateElevator1.setBukaPintu(true);    // penumpang masuk/keluar
        privateElevator1.setLantaiSkrg(2); // elevator bergerak tanpa menutup pintu
        privateElevator1.setBukaPintu(false);
        privateElevator1.setLantaiSkrg(1);
        privateElevator1.setLantaiSkrg(0);
    }
}
