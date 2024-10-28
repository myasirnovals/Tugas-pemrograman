package Program.VII_1;

public class TestPassByValue {
    public static void main(String[] args) {
        int i = 10;
        System.out.println(i);
        test(i);
        System.out.println(i);
    }

    public static void test(int j) {
        j = 33;
    }
}
