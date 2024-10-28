package Program.XI_3;

public class Pakaian {
    // Default ID untuk semua Pakaian
    private static int ID = 0;

    // default
    private static String keterangan = "-keterangan diperlukan-";

    private static double harga = 0.0;     // Harga default untuk semua pakaian
    private static int jmlStok = 0;    // jumlah default untuk semua Pakaian

    // Static member ditambahkan dalam
    // constructor
    // untuk mengahasilkan ID yang unik

    private static int UNIQUE_ID = 0;
    public Pakaian() {
        ID = UNIQUE_ID;
    }

    public static int getID() {
        return ID;
    }

    public static String getKeterangan() {
        return keterangan;
    }

    public void setKeterangan(String keterangan) {
        this.keterangan = keterangan;
    }

    public static double getHarga() {
        return harga;
    }

    public void setHarga(double harga) {
        this.harga = harga;
    }

    public static int getJmlStok() {
        return jmlStok;
    }

    public void setJmlStok(int jmlStok) {
        this.jmlStok = jmlStok;
    }
}
