/**
 * <b>Kelas Lingkaran</b>
 * kelas ini merepresentasikan Lingkaran sebagai suatu tipe data,
 * sebuah bangun datar sudut,
 * berupa himpunan titik-titik yang berjarak sama ke sebuah titik pusat
 * <br>Di bawah <i>field</i> yang dimilikinya adalah jejari, yang menyatakan jarak
 * titik-titik itu ke titik pusat.
 * @author Rezki Yuniarti
 */
public class Lingkaran {
	private float jejari;
	private float diameter;
	private double keliling;
	private double luas;
	
	/** Konstruktor ini menyebabkan jejari lingkaran secara default bernilai 1 */
	Lingkaran() {
		jejari = 1;
	}
	
	/** Konstruktor ini digunakan jika nilai jejari dikustomisasi
	 * @param r nilai jejari bertipe float
	 */
	Lingkaran(float r) {
		jejari = r;
	}
	
	/** Method ini digunakan untuk mengakses nilai jejari, dengan tipe kembalian float,
	 * @return nilai jejari
	 */
	public float getJejari() {
		return jejari;
	}
	
	/** Method ini digunakan untuk mengubah nilai jejari, dengan tipe kembalian void.
	 * @param jejari nilai jejari lingkaran
	 * <br> Masukan nilai <b>float</b> jejari pada parameter method ini.
	 * <br> Contoh : Lingkaran myLingk new Lingkaran( );
	 * <br> 		 float 1 myLingk.setJejari(5);
	 * 
	 */
	public void setJajar(float jejari) {
		this.jejari = jejari;
	}
	
	/** Method ini digunakan untuk menghitung nilai diameter, dengan tipe kembalian float.
	 * @return float diameter
	 * <br> Contoh : Lingkaran myLingk new Lingkaran (5);
	 * <br> 		 float 1 myLingk.getDiameter( );
	 */
	public float getDiameter() {
		diameter = 2 * jejari;
		return diameter;
	}
	
	/** Method ini digunakan untuk menghitung nilai luas lingkaran, dengan tipe kembalian double.
	 * @return double luas
	 * <br> Contoh : Lingkaran myLingk = new Lingkaran (5);
	 * <br> 		  double 1 = myLingk.getLuas();
	 */
	public double getLuas() {
		luas = Math.PI*jejari*jejari;
		return luas;
	}

	/**Method ini digunakan untuk menghitung keliling lingkaran,dengan tipe kembalian double.
	 * <br> Contoh : Lingkaran myLingk = new Lingkaran (5);
	 * <br> 		  double 1 = myLingk.getKeliling();
	 * @return double keliling
	 */
	public double getKeliling() {
		keliling = 2 * Math.PI * jejari;
		return keliling;
	}
}