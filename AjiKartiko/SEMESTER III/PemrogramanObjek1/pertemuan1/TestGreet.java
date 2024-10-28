//
//Sample "Welcome to java programming!" application
//
public class TestGreet {
	public static void main (String[] args) {
		Greeting hello = new Greeting();
		hello.greet();
	}
}
public class Greeting {
    // Method untuk menampilkan pesan sambutan
    public void greet() {
        System.out.println("Welcome to java programming!");
    }
}