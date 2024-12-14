public class Ikan {
    public String nama;
    public double panjang;
    public String perairan;

    public Ikan(String nama) {
        this.nama = nama;
    }

    public void berenang() {
        System.out.println("ikan " + nama + " berenang");
    }

    public void cetakInfo() {
        System.out.println("Nama " + nama);
        System.out.println("Panjang ikan " + panjang + " cm");
        System.out.println("Hidup di " + perairan);
    }
}
