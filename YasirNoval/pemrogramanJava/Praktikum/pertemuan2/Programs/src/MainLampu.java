public class MainLampu {
    public static void main(String[] args) {
        // Membuat objek lampu
        Lampu lampuKamar = new Lampu();

        // Memanggil metode pada objek
        lampuKamar.hidupkan();  // Output: Lampu menyala.
        lampuKamar.matikan();   // Output: Lampu mati.

        // Memeriksa status lampu
        if (lampuKamar.apakahMenyala()) {
            System.out.println("Lampu masih menyala.");
        } else {
            System.out.println("Lampu sudah dimatikan.");
        }
    }
}
