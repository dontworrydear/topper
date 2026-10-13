import java.util.ArrayList;
import java.util.LinkedList;
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

public class StudentCollectionsDemo {
    public static void main(String[] args) {
        Box<String> box = new Box<>("Student data");
        System.out.println("Box contains: " + box.getValue());

        ArrayList<String> names = new ArrayList<>();
        names.add("Asha");
        names.add("Rahul");
        names.add("Asha");

        LinkedList<Integer> rollNumbers = new LinkedList<>();
        rollNumbers.add(11);
        rollNumbers.add(12);
        rollNumbers.add(11);

        Set<String> uniqueNames = new HashSet<>(names);

        System.out.println("Student names:");
        Iterator<String> nameIt = names.iterator();
        while (nameIt.hasNext()) {
            System.out.println(nameIt.next());
        }

        System.out.println("Roll numbers:");
        Iterator<Integer> rollIt = rollNumbers.iterator();
        while (rollIt.hasNext()) {
            System.out.println(rollIt.next());
        }

        System.out.println("Unique student names:");
        Iterator<String> uniqueIt = uniqueNames.iterator();
        while (uniqueIt.hasNext()) {
            System.out.println(uniqueIt.next());
        }
    }
}
