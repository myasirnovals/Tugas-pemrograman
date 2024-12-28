package Program.XI_3;

public class Baju extends Pakaian{
    // Kode Warna R=Merah, B=Biru, G=Hijau, U=Belum Ditentukan
    public static char kodeWarna = 'U';

    // Method ini menampilkan nilai untuk suatu item
    public static void main(String[] args) {
        Pakaian pakaian = new Pakaian();

        System.out.println("ID Baju: " + pakaian.getID());
        System.out.println("Keterangan: " + pakaian.getKeterangan());
        System.out.println("Kode Warna: " + kodeWarna);
        System.out.println("Harga Baju: " + pakaian.getHarga());
        System.out.println("Jumlah Stok: " + pakaian.getJmlStok());
    }
}
