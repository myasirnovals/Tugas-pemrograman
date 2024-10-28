package Program.VII_9;

public class StudentRecordExample {
    public static void main(String[] args) {
        // membuat 3 object StudentRecord
        StudentRecord annaRecord = new StudentRecord();
        StudentRecord beahRecord = new StudentRecord();
        StudentRecord crisRecord = new StudentRecord();

        // memberi nama siswa
        annaRecord.setName("Anna");
        beahRecord.setName("Bea Hana");
        crisRecord.setName("Mighty Might Cris");

        // menampilkan nama siswa
        System.out.println(annaRecord.getName());
        System.out.println(beahRecord.getName());
        System.out.println(crisRecord.getName());

        // menampilkan jumlah siswa
        System.out.println("Count = " + StudentRecord.getStudentCount());
    }
}
