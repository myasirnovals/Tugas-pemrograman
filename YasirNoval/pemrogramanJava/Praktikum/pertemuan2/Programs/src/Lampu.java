public class Lampu {
    // State atau atribut dari lampu
    private boolean menyala;

    // Constructor untuk membuat objek Lampu
    public Lampu() {
        // Ketika lampu baru dibuat, ia akan dalam keadaan mati
        this.menyala = false;
    }

    // Behavior atau metode untuk 'menyalakan' lampu
    public void hidupkan() {
        menyala = true;
        System.out.println("Lampu menyala.");
    }

    // Behavior atau metode untuk 'mematikan' lampu
    public void matikan() {
        menyala = false;
        System.out.println("Lampu mati.");
    }

    // Metode untuk memeriksa status lampu
    public boolean apakahMenyala() {
        return menyala;
    }
}
