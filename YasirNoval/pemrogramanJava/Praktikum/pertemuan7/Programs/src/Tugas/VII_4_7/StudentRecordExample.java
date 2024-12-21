package Tugas.VII_4_7;

import Program.VII_9.StudentRecord;

public class StudentRecordExample {
    public static void main(String[] args) {
        // membuat 3 object StudentRecord
        StudentRecord annaRecord = new StudentRecord();
        annaRecord.setName("Anna Belle");
        annaRecord.setAddress("Cimahi");
        annaRecord.setAge(19);
        annaRecord.setScienceGrade(57.6);
        annaRecord.setMathGrade(77.6);
        annaRecord.setEnglishGrade(47.6);

        StudentRecord beahRecord = new StudentRecord();
        beahRecord.setName("Beah Belle");
        beahRecord.setAddress("Cimahi");
        beahRecord.setAge(19);
        beahRecord.setScienceGrade(57.6);
        beahRecord.setMathGrade(77.6);
        beahRecord.setEnglishGrade(47.6);

        StudentRecord crisRecord = new StudentRecord();
        crisRecord.setName("Cris Belle");
        crisRecord.setAddress("Cimahi");
        crisRecord.setAge(19);
        crisRecord.setScienceGrade(57.6);
        crisRecord.setMathGrade(77.6);
        crisRecord.setEnglishGrade(47.6);

        // menampilkan nama siswa
        annaRecord.infoStudent();
        beahRecord.infoStudent();
        crisRecord.infoStudent();

        // menampilkan jumlah siswa
        System.out.println("Count = " + StudentRecord.getStudentCount());
    }
}
