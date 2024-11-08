public class Arithmetic {
    private double value1;
    private double value2;

    public double getValue1() {
        return value1;
    }

    public void setValue1(double value1) {
        this.value1 = value1;
    }

    public double getValue2() {
        return value2;
    }

    public void setValue2(double value2) {
        if (value2 != 0) {
            this.value2 = value2;
        } else {
            System.out.println("Error: Can't divide by zero 0\n");
        }
    }

    public double plus() {
        return value1 + value2;
    }

    public double minus() {
        return value1 - value2;
    }

    public double multiply() {
        return value1 * value2;
    }

    public double divide() {
        return value1 / value2;
    }
}
