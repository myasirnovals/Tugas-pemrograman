package Tugas.TA;

public class Point {
    private int x;
    private int y;
    private int z;

    public Point(int x, int y, int z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getZ() {
        return z;
    }

    public void setZ(int z) {
        this.z = z;
    }

    public void geser(int dx)  {
        x += dx;
    }

    public void geser(int dx, int dy)  {
        x += dx;
        y += dy;
    }

    public void geser(int dx, int dy, int dz)  {
        x += dx;
        y += dy;
        z += dz;
    }
}
