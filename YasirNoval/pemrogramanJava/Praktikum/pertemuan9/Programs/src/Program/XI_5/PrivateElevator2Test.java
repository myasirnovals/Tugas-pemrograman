package Program.XI_5;

public class PrivateElevator2Test {
    public static void main(String[] args) {
        PrivateElevator2 privateElevator2 = new PrivateElevator2();
        privateElevator2.buka();
        privateElevator2.tutup();
        privateElevator2.turun();
        privateElevator2.naik();
        privateElevator2.naik();
        privateElevator2.buka();
        privateElevator2.tutup();
        privateElevator2.turun();
        privateElevator2.buka();
        privateElevator2.turun();
        privateElevator2.tutup();
        privateElevator2.turun();
        privateElevator2.turun();

        int lantai = privateElevator2.getLantaiSkrg();

        if (lantai != 5 && !privateElevator2.getStatusPintu()) {
            privateElevator2.setLantaiSkrg(5);
        }

        privateElevator2.setLantaiSkrg(10);
        privateElevator2.buka();
    }
}
