abstract class Animal {
    abstract void makeSound();
}

class Dog extends Animal {
    void makeSound() {
        System.out.println("Dog says: Bark");
    }
}

class Cat extends Animal {
    void makeSound() {
        System.out.println("Cat says: Meow");
    }
}

public class AnimalDemo {
    public static void main(String[] args) {
        Animal[] animals = { new Dog(), new Cat() };

        for (Animal animal : animals) {
            animal.makeSound();
        }
    }
}
