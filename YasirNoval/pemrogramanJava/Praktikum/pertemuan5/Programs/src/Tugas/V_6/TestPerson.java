package Tugas.V_6;

import Progam.V_6.OOP.Person;

public class TestPerson {
    public static void main(String[] args) {
        Person dokter = new Person();
        dokter.cetakBiodata("Dokter", 'L', "Jl. Tripel X");
        dokter.cetakFisik(45, "March 43, 2076", 184, 90);
    }
}
