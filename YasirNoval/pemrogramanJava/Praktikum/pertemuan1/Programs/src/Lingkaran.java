/**
 * <b>Kelas Lingkaran</b>
 * Kelas ini merepresentasikan Lingkaran sebagai suatu tipe data,
 * sebuah bangun datar sudut,
 * berupa himpunan titik-titik yang berjarak sama ke sebuah titik pusat
 * <br>Dibawah <i>field</i> yang dimilikinya adalah jejari, yang menyatakan jarak
 * titik-titik itu ke titik pusat
 *
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
    Lingkaran() {
        jejari = 1;
    }

    /**
     * Konstruktor ini digunakan jika nilai jejari dikustomisasi
     *
     * @param jejari bertipe data float
     */
    Lingkaran(float jejari) {
        this.jejari = jejari;
    }

    /**
     * Method ini digunakan untuk mengakses nilai jejari, dengan tipe kembalian float
     *
     * @return nilai jejari
     */
    public float getJejari() {
        return jejari;
    }

    /**
     * Method ini digunakan untuk mengubah nilai jejari, dengan tipe kembalian void.
     * 		     <br> Masukan nilai <b>float</b> jejari pada parameter method ini.
     *	             <br> Contoh: Lingkaran myLink = new Lingkaran();
     *               <br>         float l = mylink.setJejari(5);
     * @param jejari nilai jejari lingkaran
     *      
     */
    public void setJejari(float jejari) {
        this.jejari = jejari;
    }

    /**
     * Method ini digunakan untuk menghitung nilai diameter, dengan tipe kembalian float.
     * <br> Contoh : Lingkaran myLink = new Lingkaran(5);
     * <br>          float l = mylink.getDiameter();
     * @return float diameter
     * 
     */
    public float getDiameter() {
        diameter = 2 * jejari;
        return diameter;
    }

    /**
     * Method ini digunakan untuk menghitung nilai keliling lingkaran, dengan tipe kembalian double.
     * <br> Contoh : Lingkaran myLink = new Lingkaran(5);
     * <br>          double l = mylink.getKeliling();
     * @return double keliling
     * 
     */
    public double getKeliling() {
        keliling = 2 * Math.PI * jejari;
        return keliling;
    }

    /**
     * Method ini digunakan untuk menghitung nilai luas lingkaran, dengan tipe kembalian double.
     * <br> Contoh : Lingkaran myLink = new Lingkaran(5);
     * <br>          double l = mylink.getLuas();
     * @return double luas
     * 
     */
    public double getLuas() {
        luas = Math.PI * jejari * jejari;
        return luas;
    }
}
