package Program.VII_8;

public class ElevatorTwo {
    private boolean doorOpen = false;
    private int currentFloor = 1;
    private final int TOP_FLOOR = 5;
    private final int BOTTOM_FLOOR = 1;

    public boolean isDoorOpen() {
        return doorOpen;
    }

    private void setDoorOpen(boolean doorOpen) {
        this.doorOpen = doorOpen;
    }

    public int getCurrentFloor() {
        return currentFloor;
    }

    private void setCurrentFloor(int currentFloor) {
        if (currentFloor > TOP_FLOOR) {
            this.currentFloor = TOP_FLOOR;
        } else {
            this.currentFloor = Math.max(currentFloor, BOTTOM_FLOOR);
        }
    }

    public void openDoor() {
        System.out.println("Opening door.");
        setDoorOpen(true);
        System.out.println("Door is open.");
    }

    public void closeDoor() {
        System.out.println("Closing door.");
        setDoorOpen(false);
        System.out.println("Door is closed.");
    }

    public void goToFloor(int floor) {
        System.out.println("Going to floor " + floor + ".");
        setCurrentFloor(floor);
        System.out.println("Floor: " + getCurrentFloor());
    }

}
