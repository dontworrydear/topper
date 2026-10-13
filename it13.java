interface FuelEfficient {
    void fuelEfficiency();
    void maintenanceCost();
}

abstract class Vehicle {
    abstract void move();

    void startEngine() {
        System.out.println("Engine started");
    }
}

class Car extends Vehicle implements FuelEfficient {
    void move() {
        System.out.println("Car moves on four wheels");
    }

    public void fuelEfficiency() {
        System.out.println("Car fuel efficiency: 15 km per liter");
    }

    public void maintenanceCost() {
        System.out.println("Car maintenance cost: Rs. 5000 per year");
    }
}

class Motorcycle extends Vehicle implements FuelEfficient {
    void move() {
        System.out.println("Motorcycle moves on two wheels");
    }

    public void fuelEfficiency() {
        System.out.println("Motorcycle fuel efficiency: 30 km per liter");
    }

    public void maintenanceCost() {
        System.out.println("Motorcycle maintenance cost: Rs. 2000 per year");
    }
}

public class FuelEfficientDemo {
    public static void main(String[] args) {
        Car car = new Car();
        Motorcycle bike = new Motorcycle();

        car.startEngine();
        car.move();
        car.fuelEfficiency();
        car.maintenanceCost();

        System.out.println();

        bike.startEngine();
        bike.move();
        bike.fuelEfficiency();
        bike.maintenanceCost();
    }
}
