package Program.VII_9;

public class StudentRecord {
    private String name;
    private String address;
    private int age;
    private double mathGrade;
    private double englishGrade;
    private double scienceGrade;
    private double average;
    private static int studentCount;

    public StudentRecord() {
        studentCount++;
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
        return studentCount;
    }

    public static void setStudentCount(int studentCount) {
        StudentRecord.studentCount = studentCount;
    }

    public void infoStudent() {
        System.out.println("Nama: " + getName());
        System.out.println("Umur: " + getAge());
        System.out.println("Alamat: " + getAddress());
        System.out.println("ScienceGrade: " + getScienceGrade());
        System.out.println("MathGrade: " + getMathGrade());
        System.out.println("EnglishGrade: " + getEnglishGrade());

        if (getScienceGrade() == 0 && getEnglishGrade() == 0 && getMathGrade() == 0) {
            setAverage(0);
            System.out.println("Rata-rata: " + getAverage());
        } else {
            System.out.println("Rata-rata: " + getAverage());
        }

        System.out.println();
    }
}
