package Tugas.VII_8;

import java.awt.*;

public class LingkunganRumah {
    public static void main(String[] args) {
        Kucing michael = new Kucing();
        Kucing garfield = new Kucing();

        michael.setWarnaBulu(new Color(1, 1, 0));
        michael.setNama("Michael");
        michael.setUsia(3);
        michael.setBb(4.5);
        michael.setStatusJinak(true);
        michael.diadopsi("Rezki Yuniarti");
        michael.cetakInformasi();

        garfield.setWarnaBulu(new Color(0, 1, 1));
        garfield.setNama("Garfield");
        garfield.setUsia(3);
        garfield.setBb(4.5);
        michael.setStatusJinak(false);
        garfield.diadopsi("Rezki Yuniarti");
        garfield.cetakInformasi();
    }
}
