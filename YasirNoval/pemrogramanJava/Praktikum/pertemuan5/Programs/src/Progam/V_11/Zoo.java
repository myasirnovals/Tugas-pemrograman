package Progam.V_11;

import Progam.V_10.Kangoroo;
import Progam.V_8.Lion;
import Progam.V_9.Horse;

public class Zoo {
    public static void main(String[] args) {
        Lion singa = new Lion("Singa");
        singa.setFilum("Chordata");
        singa.setKelas("Mammalia");
        singa.setOrdo("Carnivora");
        singa.setFamili("Felidae");
        singa.setGenus("Panthera");
        singa.setSpesies("Panthera leo");
        singa.cetakInformasi();

        Horse kuda = new Horse("Kuda");
        kuda.setFilum("Chordata");
        kuda.setKelas("Mammalia");
        kuda.setOrdo("Perissodactyla");
        kuda.setFamili("Equidae");
        kuda.setGenus("Equus");
        kuda.setSpesies("Equus caballus");
        kuda.cetakInformasi();

        Kangoroo kangguru = new Kangoroo("Kangguru Merah");
        kangguru.setFilum("Chordata");
        kangguru.setKelas("Mammalia");
        kangguru.setOrdo("Diprot odontia");
        kangguru.setFamili("Macropodidae");
        kangguru.setGenus("Osphranter");
        kangguru.setSpesies("Osphranter rufus");
        kangguru.cetakInformasi();
    }
}
