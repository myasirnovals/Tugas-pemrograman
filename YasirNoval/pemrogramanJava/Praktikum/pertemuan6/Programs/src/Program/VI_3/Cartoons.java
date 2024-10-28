package Program.VI_3;

public class Cartoons {
    public static void main(String[] args) {
        String[][] cartoons = {
                {"Flintstones", "Fred", "Wilma", "Pebbles", "Dino"},
                {"Rubbles", "Barney", "Betty", "Bam Bam"},
                {"Jetsons", "George", "Jane", "Elroy", "Judy", "Rosie", "Astro"},
                {"Scooby Doo Gang", "Scooby Doo", "Shaggy", "Velma", "Fred", "Daphne"}
        };

        for (int i = 0; i < cartoons.length; i++) {
            System.out.println(cartoons[i][0] + ": ");
            for (int j = 0; j < cartoons[i].length; j++) {
                System.out.println(cartoons[i][j] + " ");
            }
            System.out.println();
        }
    }
}
