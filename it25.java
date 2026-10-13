import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;

class Box<T> {
    private T value;

    Box(T value) {
        this.value = value;
    }

    T getValue() {
        return value;
    }
}

public class CollectionsBoxDemo {
    public static void main(String[] args) {
        Box<Integer> numberBox = new Box<>(100);
        Box<String> textBox = new Box<>("Hello");

        System.out.println("Integer Box: " + numberBox.getValue());
        System.out.println("String Box: " + textBox.getValue());

        List<String> names = new ArrayList<>();
        names.add("Asha");
        names.add("Rahul");
        names.add("Asha");

        LinkedList<Integer> numbers = new LinkedList<>();
        numbers.add(1);
        numbers.add(2);
        numbers.add(1);

        Set<String> uniqueNames = new HashSet<>(names);

        System.out.println("ArrayList names (duplicates allowed):");
        Iterator<String> nameIterator = names.iterator();
        while (nameIterator.hasNext()) {
            System.out.println(nameIterator.next());
        }

        System.out.println("LinkedList numbers (duplicates allowed):");
        Iterator<Integer> numberIterator = numbers.iterator();
        while (numberIterator.hasNext()) {
            System.out.println(numberIterator.next());
        }

        System.out.println("Set names (unique values):");
        Iterator<String> setIterator = uniqueNames.iterator();
        while (setIterator.hasNext()) {
            System.out.println(setIterator.next());
        }
    }
}
