public class Main {
    public static void main(String[] args) {
        Mahasiswa yasir = new Mahasiswa("Muhamad Yasir Noval");
        yasir.nim = "2350081004";
        yasir.kelas = "A";

        Kucing shiroko = new Kucing("Shiroko");
        shiroko.age = 3;
        shiroko.bb = 3;

        Ikan koi = new Ikan("Koi");
        koi.panjang = 6;
        koi.perairan = "Air tawar";

        yasir.cetakInfo();
        yasir.memilikiKucing(shiroko);
        System.out.println();

        shiroko.cetakInfo();
        shiroko.makan(koi);
        System.out.println();

        koi.cetakInfo();
        koi.berenang();
        System.out.println();
    }
}