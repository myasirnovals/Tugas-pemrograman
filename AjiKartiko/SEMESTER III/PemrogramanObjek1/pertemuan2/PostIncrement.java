public class PostIncrement {
    public static void main(String[] args) {
        int a = 5;
        System.out.println("Nilai awal a: " + a);
        int b = a++;  // a disimpan ke b terlebih dahulu, kemudian a ditambah 1
        System.out.println("Setelah a++, nilai a: " + a);
        System.out.println("Nilai b setelah assignment: " + b);
    }
}