package Progam.V_7;

import java.awt.*;

public class Kucing {
    public String nama;
    public Color warnaBulu;
    public int usia;

    public double bb;
    public boolean statusJinak;
    public String majikan;

    public void cetakInformasi() {
        System.out.println("Kucing bernama : " + nama);
        System.out.println("Warna Bulu : " + warnaBulu);
        System.out.println("Usia : " + usia);
        System.out.println("Berat Badan : " + bb);
        System.out.println("Jinak? : " + apakahJinak());
        System.out.println("Diadopsi oleh : " + majikan);
    }

    public void diadopsi(String majikan) {
        this.majikan = majikan;
        this.statusJinak = true;
    }

    public boolean apakahJinak() {
        return statusJinak;
    }

    public void dilepas() {
        this.majikan = "";
        this.statusJinak = false;
    }
}