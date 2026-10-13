interface EnergyEfficient {
    void powerConsumption();
    void maintenanceCost();
}

abstract class Appliance {
    abstract void operate();

    void switchOn() {
        System.out.println("Appliance switched on");
    }
}

class WashingMachine extends Appliance implements EnergyEfficient {
    void operate() {
        System.out.println("Washing machine washes clothes");
    }

    public void powerConsumption() {
        System.out.println("Washing machine: 500 watts");
    }

    public void maintenanceCost() {
        System.out.println("Washing machine maintenance: Rs. 1500 per year");
    }
}

class Refrigerator extends Appliance implements EnergyEfficient {
    void operate() {
        System.out.println("Refrigerator keeps food cool");
    }

    public void powerConsumption() {
        System.out.println("Refrigerator: 200 watts");
    }

    public void maintenanceCost() {
        System.out.println("Refrigerator maintenance: Rs. 2000 per year");
    }
}

public class ApplianceDemo {
    public static void main(String[] args) {
        WashingMachine w = new WashingMachine();
        Refrigerator r = new Refrigerator();

        w.switchOn();
        w.operate();
        w.powerConsumption();
        w.maintenanceCost();

        System.out.println();

        r.switchOn();
        r.operate();
        r.powerConsumption();
        r.maintenanceCost();
    }
}
