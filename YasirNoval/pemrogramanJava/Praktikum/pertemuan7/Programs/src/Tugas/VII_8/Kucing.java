package Tugas.VII_8;

import java.awt.*;

public class Kucing {
    private String nama;
    private Color warnaBulu;
    private int usia;

    private double bb;
    private boolean statusJinak;
    private String majikan;

    public String getNama() {
        return nama;
    }

    public void setNama(String nama) {
        this.nama = nama;
    }

    public Color getWarnaBulu() {
        return warnaBulu;
    }

    public void setWarnaBulu(Color warnaBulu) {
        this.warnaBulu = warnaBulu;
    }

    public int getUsia() {
        return usia;
    }

    public void setUsia(int usia) {
        this.usia = usia;
    }

    public double getBb() {
        return bb;
    }

    public void setBb(double bb) {
        this.bb = bb;
    }

    public boolean isStatusJinak() {
        return statusJinak;
    }

    public void setStatusJinak(boolean statusJinak) {
        this.statusJinak = statusJinak;
    }

    public String getMajikan() {
        return majikan;
    }

    public void setMajikan(String majikan) {
        this.majikan = majikan;
    }

    public void cetakInformasi() {
        System.out.println("Kucing bernama : " + getNama());
        System.out.println("Warna Bulu : " + getWarnaBulu());
        System.out.println("Usia : " + getUsia());
        System.out.println("Berat Badan : " + getBb());
        System.out.println("Jinak? : " + apakahJinak());
        System.out.println("Diadopsi oleh : " + getMajikan());
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
