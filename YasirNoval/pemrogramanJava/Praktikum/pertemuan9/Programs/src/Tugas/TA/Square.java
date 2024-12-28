package Tugas.TA;

public class Square extends Shape{
    private double s;
    private String name;

    public double getS() {
        return s;
    }

    public void setS(double s) {
        this.s = s;
    }

    @Override
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public double getArea() {
        return Math.pow(getS(), 2);
    }

    @Override
    public void information() {
        super.information();
    }
}
