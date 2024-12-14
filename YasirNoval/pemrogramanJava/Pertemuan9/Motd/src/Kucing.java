public class Kucing {
    public String nama;
    public double bb;
    public int age;

    public Kucing(String nama) {
        this.nama = nama;
    }

    public void makan(Ikan ikan) {
        System.out.println(nama + " makan ikan " + ikan.nama);
    }

    public void cetakInfo() {
        System.out.println("Nama " + nama);
        System.out.println("Berat Badan " + bb + " kg");
        System.out.println("Umur " + age);
    }
}
