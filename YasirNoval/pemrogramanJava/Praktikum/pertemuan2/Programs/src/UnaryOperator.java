public class UnaryOperator {
    public static void main(String[] args) {
        int i = 10;
        int j = 3;
        int k = 0;

        // cetaklah hasil operasi nilai k di console, berapa
        // nilainya kemudian analisa
        k = ++j + i;
        System.out.println(k);

        k = j++ + i;
        System.out.println(k);

        k = --j + i;
        System.out.println(k);

        k = j-- + i;
        System.out.println(k);
    }
}
