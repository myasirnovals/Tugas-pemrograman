package Tugas.TA;

import java.util.Objects;

public class KingdomAnimalia {
    private String name;
    private String filum;
    private String kelas;
    private String ordo;
    private String famili;
    private String genus;
    private String spesies;

    public KingdomAnimalia(String name, String filum, String kelas, String ordo, String famili, String genus, String spesies) {
        this.name = name;
        this.filum = filum;
        this.kelas = kelas;
        this.ordo = ordo;
        this.famili = famili;
        this.genus = genus;
        this.spesies = spesies;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        if (Objects.equals(name, "")) {
            this.name = "none";
        } else {
            this.name = name;
        }
    }

    public String getFilum() {
        return filum;
    }

    public void setFilum(String filum) {
        if (Objects.equals(filum, "")) {
            this.filum = "none";
        } else {
            this.filum = filum;
        }
    }

    public String getKelas() {
        return kelas;
    }

    public void setKelas(String kelas) {
        if (Objects.equals(kelas, "")) {
            this.kelas = "none";
        } else {
            this.kelas = kelas;
        }
    }

    public String getOrdo() {
        return ordo;
    }

    public void setOrdo(String ordo) {
        if (Objects.equals(ordo, "")) {
            this.ordo = "none";
        } else {
            this.ordo = ordo;
        }
    }

    public String getFamili() {
        return famili;
    }

    public void setFamili(String famili) {
        if (Objects.equals(famili, "")) {
            this.famili = "none";
        } else {
            this.famili = famili;
        }
    }

    public String getGenus() {
        return genus;
    }

    public void setGenus(String genus) {
        if (Objects.equals(genus, "")) {
            this.genus = "none";
        } else {
            this.genus = genus;
        }
    }

    public String getSpesies() {
        return spesies;
    }

    public void setSpesies(String spesies) {
        if (Objects.equals(spesies, "")) {
            this.spesies = "none";
        } else {
            this.spesies = spesies;
        }
    }

    public void cetakInformasi() {
        System.out.println("Nama Hewan: " + getName());
        System.out.println("Filum : " + getFilum());
        System.out.println("Kelas : " + getKelas());
        System.out.println("Bangsa : " + getOrdo());
        System.out.println("Keluarga : " + getFamili());
        System.out.println("Marga : " + getGenus());
        System.out.println("Jenis : " + getSpesies());
        System.out.println();
    }
}