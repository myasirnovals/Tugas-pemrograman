package Tugas.TA;

public class Zoo {
    public static void main(String[] args) {
        Kangaroo[] kangaroos = new Kangaroo[5];
        Horse[] horses = new Horse[5];
        Lion[] lions = new Lion[5];

        for (int i = 0; i < kangaroos.length; i++) {
            System.out.println("Memasukan taksonomi Kanguru ke-" + i);
            kangaroos[i] = new Kangaroo(
                    "walabi",
                    "Chordata",
                    "Mama",
                    "Diprodontia",
                    "Macropodidae",
                    "Lagorchestes",
                    "Lagorchestes leporides"
            );
        }

        for (int i = 0; i < horses.length; i++) {
            System.out.println("Memasukan taksonomi Kuda ke-" + i);
            horses[i] = new Horse(
                    "Kuda",
                    "Chordata",
                    "Mamalia",
                    "Perissodactyla",
                    "Equidae",
                    "Equus",
                    "Equus caballus"
            );
        }

        for (int i = 0; i < lions.length; i++) {
            System.out.println("Memasukan taksonomi Singa ke-" + i);
            lions[i] = new Lion(
                    "Singa",
                    "Chordata",
                    "Mamalia",
                    "Carnivora",
                    "Felidae",
                    "Panthera",
                    "Panthera leo"
            );
        }

        for (Kangaroo kangaroo : kangaroos) {
            kangaroo.cetakInformasi();
        }

        for (Horse hors : horses) {
            hors.cetakInformasi();
        }

        for (Lion lion : lions) {
            lion.cetakInformasi();
        }
    }
}
