package Tugas.VI_2;

public class ArrayOfStringsExam {
    public static void main(String[] args) {
        String[] anArray = {"String One", "String Two", "String Three"};
        char[] arChar = {'a', 'b', 'c'};
        for (int i = 0; i < anArray.length; i++) {
            System.out.println(anArray[i].toLowerCase() + " " + arChar[i]);
        }
    }
}
