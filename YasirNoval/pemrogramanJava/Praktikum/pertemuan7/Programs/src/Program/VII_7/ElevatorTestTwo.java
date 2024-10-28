package Program.VII_7;

import Program.VII_5.Elevator;

public class ElevatorTestTwo {
    public static void main(String[] args) {
        Elevator myElevator = new Elevator();
        myElevator.openDoor();
        myElevator.closeDoor();
        myElevator.goUp();
        myElevator.goUp();
        myElevator.goUp();
        myElevator.openDoor();
        myElevator.closeDoor();
        myElevator.goDown();
        myElevator.openDoor();
        myElevator.closeDoor();
        myElevator.goDown();

        int curFloor = myElevator.getFloor();
        System.out.println("Current Floor: " + curFloor);
        myElevator.setFloor(curFloor + 1);
        myElevator.openDoor();
    }
}
