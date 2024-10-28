package Program.VIII_8;

public class PrivateElevator1 {
    private boolean bukaPintu = false;
    private int lantaiSkrg = 1;
    private int berat = 0;
    private final int KAPASITAS = 1000;
    private final int LANTAI_ATAS = 5;
    private final int LANTAI_BAWAH = 1;

    public boolean isBukaPintu() {
        return bukaPintu;
    }

    public void setBukaPintu(boolean bukaPintu) {
        this.bukaPintu = bukaPintu;
    }

    public int getLantaiSkrg() {
        return lantaiSkrg;
    }

    public void setLantaiSkrg(int lantaiSkrg) {
        this.lantaiSkrg = lantaiSkrg;
    }

    public int getBerat() {
        return berat;
    }

    public void setBerat(int berat) {
        this.berat = berat;
    }
}
