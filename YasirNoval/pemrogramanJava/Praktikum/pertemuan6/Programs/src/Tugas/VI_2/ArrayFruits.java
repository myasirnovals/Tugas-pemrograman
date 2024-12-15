package Tugas.VI_2;

public class ArrayFruits {
    public static void main(String[] args) {
        var fruits = new String[]{"Apple", "Banana", "Cherry"};

        for (String fruit : fruits) {
            System.out.print(fruit + " ");
        }

        fruits[1] = "Orange";
        System.out.println();

        for (String fruit : fruits) {
            System.out.print(fruit + " ");
        }
    }
}
