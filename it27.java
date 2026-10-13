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

public class EmployeeCollectionsDemo {
    public static void main(String[] args) {
        Box<Integer> box = new Box<>(500);
        System.out.println("Box contains employee ID: " + box.getValue());

        ArrayList<Integer> employeeIds = new ArrayList<>();
        employeeIds.add(101);
        employeeIds.add(102);
        employeeIds.add(101);

        LinkedList<String> employeeNames = new LinkedList<>();
        employeeNames.add("Amit");
        employeeNames.add("Priya");
        employeeNames.add("Amit");

        Set<Integer> uniqueIds = new HashSet<>(employeeIds);

        System.out.println("Employee IDs (List):");
        Iterator<Integer> idIt = employeeIds.iterator();
        while (idIt.hasNext()) {
            System.out.println(idIt.next());
        }

        System.out.println("Employee names (LinkedList):");
        Iterator<String> nameIt = employeeNames.iterator();
        while (nameIt.hasNext()) {
            System.out.println(nameIt.next());
        }

        System.out.println("Unique employee IDs (Set):");
        Iterator<Integer> uniqueIt = uniqueIds.iterator();
        while (uniqueIt.hasNext()) {
            System.out.println(uniqueIt.next());
        }
    }
}
