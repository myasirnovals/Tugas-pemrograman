package Program.VII_8;

public class TestElevatorTwo {
    public static void main(String[] args) {
        ElevatorTwo myElevatorTwo = new ElevatorTwo();
        myElevatorTwo.openDoor();
        System.out.println("Is door open? " + myElevatorTwo.isDoorOpen());
        myElevatorTwo.closeDoor();
        myElevatorTwo.goToFloor(1);
        myElevatorTwo.goToFloor(5);
        System.out.println("What floor is this? " + myElevatorTwo.getCurrentFloor());
    }
}
