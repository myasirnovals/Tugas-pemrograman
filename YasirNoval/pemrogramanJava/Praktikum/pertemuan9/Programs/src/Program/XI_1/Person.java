package Program.XI_1;

public class Person {
    protected String name;
    protected String address;

    public Person() {
        System.out.println("Inside Person: Constructor");
        name = "";
        address = "";
    }

    public Person(String name, String address) {
        this.name = name;
        this.address = address;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }
}
