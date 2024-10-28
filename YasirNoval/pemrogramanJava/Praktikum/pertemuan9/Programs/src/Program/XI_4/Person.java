package Program.XI_4;

public class Person {
    protected String name;
    protected String address;

    /**
     * Default Constructor
     */
    public Person() {
        System.out.println("Inside Person:Constructor");
        name = "";
        address = "";
    }

    /**
     * Constructor dengan dua parameter
     * @param name
     * @param address
     */
    public Person(String name, String address) {
        this.name = name;
        this.address = address;
    }

    /**
     * Method accessor
     */
    public String getName() {
        System.out.println("Person name: " + name);
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

