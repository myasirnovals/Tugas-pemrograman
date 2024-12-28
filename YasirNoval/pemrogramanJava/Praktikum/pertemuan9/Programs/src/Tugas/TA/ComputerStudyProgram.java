package Tugas.TA;

public class ComputerStudyProgram extends StudentRecord{
    private double computerGrade;

    public double getComputerGrade() {
        return computerGrade;
    }

    public void setComputerGrade(double computerGrade) {
        this.computerGrade = computerGrade;
    }

    public ComputerStudyProgram(double mathGrade, double englishGrade, double scienceGrade, double computerGrade) {
        super(mathGrade, englishGrade, scienceGrade);
        this.computerGrade = computerGrade;
    }

    @Override
    public double getAverage() {
        return (getMathGrade() + getEnglishGrade() + getScienceGrade() + getComputerGrade()) / 4;
    }

    @Override
    public void setAverage(double average) {
        super.setAverage(average);
    }
}
