public class Mahasiswa {
    public String nama;
    public String nim;
    public String kelas;

    public Mahasiswa() {

    }

    public Mahasiswa(String nama) {
        this.nama = nama;
    }

    public void memilikiKucing(Kucing kucing) {
        System.out.println(nama + " memiliki kucing " + kucing.nama);
    }

    public void cetakInfo() {
        System.out.println("Nama " + nama);
        System.out.println("NIM " + nim);
        System.out.println("Kelas " + kelas);
    }
}
