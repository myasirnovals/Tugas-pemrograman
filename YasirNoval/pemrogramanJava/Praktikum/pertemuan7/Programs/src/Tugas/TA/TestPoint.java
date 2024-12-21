package Tugas.TA;

public class TestPoint {
    public static void main(String[] args) {
        Point point = new Point(-5, 3, 2);
        System.out.println(point.getX());
        System.out.println(point.getY());
        System.out.println(point.getZ());

        point.setX(10);
        point.setY(-5);
        point.setZ(3);

        point.geser(3);
        point.geser(3, 4);
        point.geser(3, 4, 5);

        System.out.println(point.getX());
        System.out.println(point.getY());
        System.out.println(point.getZ());
    }
}
