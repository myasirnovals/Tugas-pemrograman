package Program.VIII_4;

import Program.VIII_3.StudentRecord;

public class StudentRecordExample {
    public static void main(String[] args) {
        // membuat 3 object StudentRecord
        StudentRecord dayu = new StudentRecord();
        StudentRecord lani = new StudentRecord();
        StudentRecord bambang = new StudentRecord();

        StudentRecord karyono = new StudentRecord("Karyono");
        StudentRecord songjongki = new StudentRecord("Song Jong-Ki", "Cibaduyut");
        StudentRecord masbejo = new StudentRecord(80, 90, 100);

        StudentRecord ujang = new StudentRecord("Ujang Ronaldo", 'L');

        // memberi nama siswa
        dayu.setName("Dayu Anderson");
        lani.setName("Lani Rukoyah");
        bambang.setName("Cristopher Bambang");

        // Menampilkan nama siswa "Dayu"
        System.out.println(dayu.getName());

        // Menampilkan jumlah siswa
        System.out.println("Count = " + StudentRecord.getStudentCount());
        StudentRecord annaRecord = new StudentRecord();
        annaRecord.setName("Anna");
        annaRecord.setAddress("Philipina");
        annaRecord.setAge(15);
        annaRecord.setMathGrade(80);
        annaRecord.setEnglishGrade(95.5);
        annaRecord.setScienceGrade(100);

        // overload method
        annaRecord.print(annaRecord.getName());
        annaRecord.print(
                annaRecord.getEnglishGrade(), annaRecord.getMathGrade(), annaRecord.getScienceGrade()
        );
        annaRecord.print(annaRecord.getName());
    }
}
