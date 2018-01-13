import java.util.LinkedList;
import java.util.List;

public class Lehrer {
    private int id;
    private String name;

    private List<Unterricht> unterricht;


    public Lehrer(int id, String name, String fach, String klasse, String tag, int einheit) {
        this.id = id;
        this.name = name;

        this.unterricht = new LinkedList<>();
        unterricht.add(new Unterricht(fach, klasse, tag, einheit));
    }
}
