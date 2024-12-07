package Tugas.V_1;

public class CommandLineExam {
    public static void main(String[] args) {
        if (args.length == 1) {
            System.out.println(args[0]);
        } else {
            for (String arg : args) {
                System.out.println(arg);
            }
        }
    }
}
