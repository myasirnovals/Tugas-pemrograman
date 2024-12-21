package Tugas.TA;

public class Zoo {
    public static void main(String[] args) {
        Kangaroo[] kangaroos = new Kangaroo[5];
        kangaroos[0] = new Kangaroo();
        kangaroos[0].setName("walabi");
        kangaroos[0].setFilum("Chordata");
        kangaroos[0].setKelas("Mamalia");
        kangaroos[0].setOrdo("Diprodontia");
        kangaroos[0].setFamili("Macropodidae");
        kangaroos[0].setGenus("Lagorchestes");
        kangaroos[0].setSpesies("Lagorchestes leporides");

        Horse[] horses = new Horse[5];
        horses[0] = new Horse();
        horses[0].setName("Kuda");
        horses[0].setFilum("Chordata");
        horses[0].setKelas("Mamalia");
        horses[0].setOrdo("Perissodactyla");
        horses[0].setFamili("Equidae");
        horses[0].setGenus("Equus");
        horses[0].setSpesies("Equus caballus");

        Lion[] lions = new Lion[5];
        lions[0] = new Lion();
        lions[0].setName("Singa");
        lions[0].setFilum("Chordata");
        lions[0].setKelas("Mamalia");
        lions[0].setOrdo("Carnivora");
        lions[0].setFamili("Felidae");
        lions[0].setGenus("Panthera");
        lions[0].setSpesies("Panthera leo");

        kangaroos[0].cetakInformasi();
        horses[0].cetakInformasi();
        lions[0].cetakInformasi();
    }
}
