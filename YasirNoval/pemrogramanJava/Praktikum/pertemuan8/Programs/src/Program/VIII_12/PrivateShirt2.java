package Program.VIII_12;

public class PrivateShirt2 {
    private int idBaju = 0;     //ID default untuk baju
    private String keterangan = "-keterangan Diperlukan-";

    //Kode warna R=Merah, G=Hijau, B=Biru, U=Tidak Ditentukan
    private char kodeWarna = 'U';
    private double harga = 0.0;     //Harga default untuk semua barang
    private int jmlStok = 0;    //Default untuk jumlah barang

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
        switch (kodeWarna) {
            case 'R':
            case 'G':
            case 'B':
                this.kodeWarna = kodeWarna;
                break;
            default:
                System.out.println("kodeWarna salah, gunakan R, G, atau B");
        }
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
