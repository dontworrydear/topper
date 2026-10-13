interface SmartDevice {
    void batteryUsage();
    void maintenanceCost();
}

abstract class Device {
    abstract void operate();

    void powerOn() {
        System.out.println("Device powered on");
    }
}

class Smartphone extends Device implements SmartDevice {
    void operate() {
        System.out.println("Smartphone is making a call");
    }

    public void batteryUsage() {
        System.out.println("Smartphone battery: 10% per hour");
    }

    public void maintenanceCost() {
        System.out.println("Smartphone maintenance: Rs. 3000 per year");
    }
}

class SmartWatch extends Device implements SmartDevice {
    void operate() {
        System.out.println("Smartwatch is tracking activity");
    }

    public void batteryUsage() {
        System.out.println("Smartwatch battery: 5% per hour");
    }

    public void maintenanceCost() {
        System.out.println("Smartwatch maintenance: Rs. 1000 per year");
    }
}

public class SmartDeviceDemo {
    public static void main(String[] args) {
        Smartphone phone = new Smartphone();
        SmartWatch watch = new SmartWatch();

        phone.powerOn();
        phone.operate();
        phone.batteryUsage();
        phone.maintenanceCost();

        System.out.println();

        watch.powerOn();
        watch.operate();
        watch.batteryUsage();
        watch.maintenanceCost();
    }
}
