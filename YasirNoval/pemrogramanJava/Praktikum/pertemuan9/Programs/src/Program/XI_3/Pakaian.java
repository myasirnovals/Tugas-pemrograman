package Program.XI_3;

public class Pakaian {
    // Default ID untuk semua Pakaian
    private int ID = 0;

    // default
    private String keterangan = "-keterangan diperlukan-";

    private double harga = 0.0;     // Harga default untuk semua pakaian
    private int jmlStok = 0;    // jumlah default untuk semua Pakaian

    // Static member ditambahkan dalam
    // constructor
    // untuk mengahasilkan ID yang unik
    private static int UNIQUE_ID = 0;
    public Pakaian() {
        ID = UNIQUE_ID++;
    }

    public int getID() {
        return ID;
    }

    public String getKeterangan() {
        return keterangan;
    }

    public void setKeterangan(String keterangan) {
        this.keterangan = keterangan;
    }

    public double getHarga() {
        return harga;
    }

    public void setHarga(double harga) {
        this.harga = harga;
    }

    public int getJmlStok() {
        return jmlStok;
    }

    public void setJmlStok(int jmlStok) {
        this.jmlStok = jmlStok;
    }
}
