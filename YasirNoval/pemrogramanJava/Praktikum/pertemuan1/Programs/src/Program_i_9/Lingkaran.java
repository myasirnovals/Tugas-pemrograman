package Program_i_9;


/**
 * <b>Kelas Lingkaran</b>
 * Kelas ini merepresentasikan Lingkaran sebagai suatu tipe data,
 * sebuah bangun datar sudut,
 * berupa himpunan titik-titik yang berjarak sama ke sebuah titik pusat
 * <br>Dibawah <i>field</i> yang dimilikinya adalah jejari, yang menyatakan jarak
 * titik-titik itu ke titik pusat
 * @author Muhamad Yasir Noval
 */
public class Lingkaran {
    private float jejari;
    private float diameter;
    private double keliling;
    private double luas;

    /**
     * Konstruktor ini menyebabkan jejari lingkaran secara default bernilai 1
     */
    Lingkaran(){
        jejari = 1;
    }

    /**
     * Konstruktor ini digunakan jika nilai jejari dikustomisasi
     * @param jejari bertipe data float
     */
    Lingkaran(float jejari) {
        this.jejari = jejari;
    }

    /**
     * Method ini digunakan untuk mengakses nilai jejari, dengan tipe kembalian float
     * @return nilai jejari
     */
    public float getJejari() {
        return jejari;
    }

    /**
     * Method ini digunakan untuk mengubah nilai jejari, dengan tipe kembalian void.
     * @param jejari nilai jejari lingkaran
     * <br> Masukan nilai <b>float</b> jejari pada parameter method ini.
     * <br> Contoh: Lingkaran myLink = new Lingkaran();
     * <br>         float l = mylink.setJejari(5);
     */
    public void setJejari(float jejari) {
        this.jejari = jejari;
    }

    /**
     * Method ini digunakan untuk menghitung nilai diameter, dengan tipe kembalian float.
     * @return float diameter
     * <br> Contoh : Lingkaran myLink = new Lingkaran(5);
     * <br>          float l = mylink.getDiameter();
     */
    public float getDiameter() {
        diameter = 2 * jejari;
        return diameter;
    }

    public void setDiameter(float diameter) {
        this.diameter = diameter;
    }

    /**
     * Method ini digunakan untuk menghitung nilai keliling lingkaran, dengan tipe kembalian double.
     * @return double keliling
     * <br> Contoh : Lingkaran myLink = new Lingkaran(5);
     * <br>          double l = mylink.getKeliling();
     */
    public double getKeliling() {
        return keliling;
    }

    public void setKeliling(double keliling) {
        this.keliling = keliling;
    }

    /**
     * Method ini digunakan untuk menghitung nilai luas lingkaran, dengan tipe kembalian double.
     * @return double luas
     * <br> Contoh : Lingkaran myLink = new Lingkaran(5);
     * <br>          double l = mylink.getLuas();
     */
    public double getLuas() {
        luas = Math.PI * jejari * jejari;
        return luas;
    }

    public void setLuas(double luas) {
        this.luas = luas;
    }
}
