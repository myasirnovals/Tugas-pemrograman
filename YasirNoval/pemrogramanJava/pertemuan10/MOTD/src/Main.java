import java.util.Random;

public class Main {
    public static void main(String[] args) {
        Ramalan[] ramalans = new Ramalan[2];
        ramalans[0] = new RamalanBaik();
        ramalans[1] = new RamalanBuruk();

        Random random = new Random();
        Ramalan ramalanAcak = ramalans[random.nextInt(ramalans.length)];

        System.out.println("Ramalan Anda: " + ramalanAcak.getRamalan());
    }
}