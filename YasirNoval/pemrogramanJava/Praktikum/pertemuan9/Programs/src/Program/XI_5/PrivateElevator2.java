package Program.XI_5;

public class PrivateElevator2 {
    private boolean bukaPintu = false;
    private int lantaiSkrg = 1;
    private int berat = 0;

    private final int KAPASITAS = 1000;
    private final int LANTAI_ATAS = 5;
    private final int LANTAI_BAWAH = 1;

    public void buka(){
        bukaPintu = true;
    }

    public void tutup() {
        hitungKapasitas();
        if (berat <= KAPASITAS) {
            bukaPintu = false;
        } else {
            System.out.println("Elevator kelebihan beban");
            System.out.println("Pintu akan tetap terbuka sampai seseorang keluar");
        }
    }

    private void hitungKapasitas() {
        berat = (int) (Math.random() * 1500);
        System.out.println("Berat: " + berat);
    }

    public void naik() {
        if (!bukaPintu) {
            if (lantaiSkrg < LANTAI_ATAS) {
                lantaiSkrg++;
                System.out.println(lantaiSkrg);
            } else {
                System.out.println("Sudah mencapai lantai atas");
            }
        } else {
            System.out.println("Pintu masih terbuka");
        }
    }

    public void turun() {
        if (!bukaPintu) {
            if (lantaiSkrg > LANTAI_BAWAH) {
                lantaiSkrg--;
                System.out.println(lantaiSkrg);
            } else {
                System.out.println("Sudah mencapai lantai bawah");
            }
        } else {
            System.out.println("Pintu masih terbuka");
        }
    }

    public void setLantaiSkrg(int tujuan) {
        if ((tujuan >= LANTAI_BAWAH) && (tujuan <= LANTAI_ATAS)) {
            while (lantaiSkrg != tujuan) {
                if (lantaiSkrg < tujuan) {
                    naik();
                } else {
                    turun();
                }
            }
        } else {
            System.out.println("Lantai Salah");
        }
    }

    public int getLantaiSkrg() {
        return lantaiSkrg;
    }

    public boolean getStatusPintu(){
        return bukaPintu;
    }
}
