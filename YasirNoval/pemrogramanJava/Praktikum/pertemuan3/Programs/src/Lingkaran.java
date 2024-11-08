public class Lingkaran {
    private double r;

    public double getPI() {
        return 3.14;
    }

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
    }

    public double luas() {
        return getPI() * Math.pow(r, 2);
    }

    public double keliling() {
        return 2 * getPI() * r;
    }
}
