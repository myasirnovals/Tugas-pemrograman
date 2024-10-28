package Program.VIII_2;

import Program.VIII_1.StudentRecord;

public class StudentRecordExample {
    public static void main(String[] args) {
        // membuat 3 object StudentRecord
        StudentRecord annaRecord = new StudentRecord();
        StudentRecord beahRecord = new StudentRecord();
        StudentRecord crisRecord = new StudentRecord();

        // memberi nama siswa
        annaRecord.setName("Anna");
        beahRecord.setName("Bea Hutapea");
        crisRecord.setName("Mighty Might Cris");

        // Menampilkan nama siswa "Anna"
        System.out.println(annaRecord.getName());

        // Menampilkan nama siswa "Beah"
        System.out.println(beahRecord.getName());

        // Menampilkan nama siswa "Cris"
        System.out.println(crisRecord.getName());

        // Menampilkan jumlah siswa
        System.out.println("Count = " + StudentRecord.getStudentCount());
    }
}
