package Program.VI_7;

public class ArrayMulti {
    public static void main(String[] args) {
        // elemen 512 x 128 dari integer array
        int[][] twoD = new int[512][128];

        // karakter array 8 x 16 x 24
        char[][][] threeD = new char[8][16][24];

        // String array 4 baris x 2 kolom
        String[][] kidsName = {
                {"Barra", "Aldebaran"},
                {"Arham", "Adit"},
                {"Koko", "Zyo"},
                {"Ibam", "Keanu"}
        };
        System.out.println(kidsName[0][0]);
    }
}
