public class TugasRelationalDemo {
    public static void main(String[] args) {
        // beberapa nilai variabel
        int i = 37;
        int j = 42;
        int k = 42;

        System.out.println("Nilai variabel...");
        System.out.println("    i = " + i);
        System.out.println("    j = " + j);
        System.out.println("    k = " + k);

        // lebih besar dari
        System.out.println("Lebih besar...");
        System.out.println("    i > j = " + (i > j));
        System.out.println("    j > i = " + (j > i));
        System.out.println("    k > j = " + (k > j));

        // lebih besar atau sama dengan
        System.out.println("Lebih besar atau sama dengan...");
        System.out.println("    i >= j = " + (i >= j));
        System.out.println("    j >= i = " + (j >= i));
        System.out.println("    k >= j = " + (k >= j));

        // lebih kecil
        System.out.println("Lebih kecil...");
        System.out.println("    i < j = " + (i < j));
        System.out.println("    j < i = " + (j < i));
        System.out.println("    k < j = " + (k < j));

        // lebih kecil atau sama dengan
        System.out.println("Lebih kecil atau sama dengan...");
        System.out.println("    i <= j = " + (i <= j));
        System.out.println("    j <= i = " + (j <= i));
        System.out.println("    k <= j = " + (k <= j));

        // sama dengan
        System.out.println("Sama dengan...");
        System.out.println("    i == j = " + (i == j));
        System.out.println("    j == i = " + (j == i));
        System.out.println("    k == j = " + (k == j));

        // tidak sama dengan
        System.out.println("Tidak sama dengan...");
        System.out.println("    i != j = " + (i != j));
        System.out.println("    j != i = " + (j != i));
        System.out.println("    k != j = " + (k != j));
    }
}
