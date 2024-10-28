package Program.XI_4;

public class Student extends Person{
    public Student() {
        // cobakan Satu persatu konstruktor induk yang
        // di overload. Pakai super bergantian
        // amati hasilnya dan analisa
//        super("SomeName", "SomeAddress");
//        super();
//        super.name = "name";
        System.out.println("Inside Student:Constructor");
    }

    public String getName() {
        System.out.println("Student Name: " + name);
        return name;
    }

    public static void main(String[] args) {
        Student anna = new Student();
    }
}
