public class PreDecrement {
    public static void main(String[] args) {
        int a = 5;
        System.out.println("Nilai awal a: " + a);
        int b = --a;  // a akan dikurangi 1 sebelum disimpan ke b
        System.out.println("Setelah --a, nilai a: " + a);
        System.out.println("Nilai b setelah assignment: " + b);
    }
}
