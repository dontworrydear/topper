class Vehicle {
    String vehicleNo;
    String brand;
    double price;

    Vehicle(String vehicleNo, String brand, double price) {
        this.vehicleNo = vehicleNo;
        this.brand = brand;
        this.price = price;
    }

    void displayDetails() {
        System.out.println("Vehicle No: " + vehicleNo);
        System.out.println("Brand: " + brand);
        System.out.println("Price: " + price);
    }
}

class Car extends Vehicle {
    String model;
    String fuelType;

    Car(String vehicleNo, String brand, double price, String model, String fuelType) {
        super(vehicleNo, brand, price);
        this.model = model;
        this.fuelType = fuelType;
    }

    @Override
    void displayDetails() {
        super.displayDetails();
        System.out.println("Model: " + model);
        System.out.println("Fuel Type: " + fuelType);
    }
}

public class VehicleDemo {
    public static void main(String[] args) {
        Vehicle v = new Vehicle("MH12AB1234", "Tata", 500000);
        Car c = new Car("MH14CD5678", "Maruti", 800000, "Swift", "Petrol");

        System.out.println("Vehicle details:");
        v.displayDetails();
        System.out.println("\\nCar details:");
        c.displayDetails();
    }
}
