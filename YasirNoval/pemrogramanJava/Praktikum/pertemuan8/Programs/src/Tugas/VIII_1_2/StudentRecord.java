package Tugas.VIII_1_2;

public class StudentRecord {
    private String name;
    private String address;
    private int age;
    private double mathGrade;
    private double englishGrade;
    private double scienceGrade;
    private double average;
    private static int STUDENTCOUNT;

    public StudentRecord() {
        STUDENTCOUNT++;
    }

    public StudentRecord(String name) {
        this.name = name;
    }

    public StudentRecord(String name, String address) {
        this.name = name;
        this.address = address;
    }

    public StudentRecord(double mathGrade, double englishGrade, double scienceGrade) {
        this.mathGrade = mathGrade;
        this.englishGrade = englishGrade;
        this.scienceGrade = scienceGrade;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public double getMathGrade() {
        return mathGrade;
    }

    public void setMathGrade(double mathGrade) {
        this.mathGrade = mathGrade;
    }

    public double getEnglishGrade() {
        return englishGrade;
    }

    public void setEnglishGrade(double englishGrade) {
        this.englishGrade = englishGrade;
    }

    public double getScienceGrade() {
        return scienceGrade;
    }

    public void setScienceGrade(double scienceGrade) {
        this.scienceGrade = scienceGrade;
    }

    public double getAverage() {
        double average = 0;
        average = (mathGrade + englishGrade + scienceGrade) / 3;
        return average;
    }

    public void setAverage(double average) {
        this.average = average;
    }

    public static int getStudentCount() {
        return STUDENTCOUNT;
    }

    public static void setStudentCount(int studentCount) {
        StudentRecord.STUDENTCOUNT = studentCount;
    }
}
