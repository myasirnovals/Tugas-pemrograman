package Tugas.TA;

public abstract class Shape {
    public double getArea() {
        return 0;
    }

    public String getName(){
        return "Shape";
    }

    public void information(){
        System.out.println("Name: " + getName());
        System.out.println("Area: " + getArea());
    }
}
