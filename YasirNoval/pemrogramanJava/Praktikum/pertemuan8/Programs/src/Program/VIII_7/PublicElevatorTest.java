package Program.VIII_7;

import Program.VIII_6.PublicElevator;

public class PublicElevatorTest {
    public static void main(String[] args) {
        PublicElevator publicElevator = new PublicElevator();
        publicElevator.bukaPintu = true;    // penumpang masuk
        publicElevator.bukaPintu = false;    // pintu ditutup

        // pergi ke lantai 0 dibawah gedung
        publicElevator.lantaiSkrg--;
        publicElevator.lantaiSkrg++;

        // lompat ke lantai 7 (hanya ada 5 lantai dalam gedung)
        publicElevator.lantaiSkrg = 7;
        publicElevator.bukaPintu = true;    // penumpang masuk/keluar
        publicElevator.bukaPintu = false;
        publicElevator.lantaiSkrg = 1;
        publicElevator.bukaPintu = true;    // penumpang masuk/keluar

        // elevator bergerak tanpa menutup pintu
        publicElevator.lantaiSkrg++;
        publicElevator.bukaPintu = false;
        publicElevator.lantaiSkrg--;
        publicElevator.lantaiSkrg--;
    }
}
