package Tugas.TA;

public class Circle extends Shape{
    private double r;
    private String name;

    public double getR() {
        return r;
    }

    public void setR(double r) {
        this.r = r;
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
        return Math.PI * Math.pow(getR(), 2);
    }

    @Override
    public void information() {
        super.information();
    }
}
