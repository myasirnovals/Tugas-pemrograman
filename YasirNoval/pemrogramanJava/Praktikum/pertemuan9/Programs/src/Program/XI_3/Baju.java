package Program.XI_3;

public class Baju extends Pakaian{
    // Kode Warna R=Merah, B=Biru, G=Hijau, U=Belum Ditentukan
    public static char kodeWarna = 'U';

    // Method ini menampilkan nilai untuk suatu item
    public static void main(String[] args) {

        System.out.println("ID Baju: " + getID());
        System.out.println("Keterangan: " + getKeterangan());
        System.out.println("Kode Warna: " + kodeWarna);
        System.out.println("Harga Baju: " + getHarga());
        System.out.println("Jumlah Stok: " + getJmlStok());
    }
}
