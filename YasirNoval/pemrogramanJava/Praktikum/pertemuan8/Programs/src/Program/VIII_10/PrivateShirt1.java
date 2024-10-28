package Program.VIII_10;

public class PrivateShirt1 {
    //ID default untuk baju
    private int idBaju = 0;

    //default
    private String keterangan = "-keterangan Diperlukan-";

    //Kode warna R=Merah, G=Hijau, B=Biru, U=Tidak Ditentukan
    private char kodeWarna = 'U';

    //Harga default untuk semua barang
    private double harga = 0.0;

    //Default untuk jumlah barang
    private int jmlStok = 0;

    public int getIdBaju() {
        return idBaju;
    }

    public void setIdBaju(int idBaju) {
        this.idBaju = idBaju;
    }

    public String getKeterangan() {
        return keterangan;
    }

    public void setKeterangan(String keterangan) {
        this.keterangan = keterangan;
    }

    public char getKodeWarna() {
        return kodeWarna;
    }

    public void setKodeWarna(char kodeWarna) {
        this.kodeWarna = kodeWarna;
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
