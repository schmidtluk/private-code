public class Unterricht implements Comparable<Unterricht>{
    private String fach;
    private String klasse;
    private String tag;
    private int einheit;

    public Unterricht(String fach, String klasse, String tag, int einheit) {
        this.fach = fach;
        this.klasse = klasse;
        this.tag = tag;
        this.einheit = einheit;
    }

    @Override
    public int compareTo(Unterricht o) {
        return (this.getTag().compareTo(o.getTag()) != 0?
                this.getTag().compareTo(o.getTag()) : Integer.compare(this.getEinheit(), o.getEinheit()));
    }

    @Override
    public String toString() {
        return "Unterricht{" +
                "fach='" + fach + '\'' +
                ", klasse='" + klasse + '\'' +
                ", tag='" + tag + '\'' +
                ", einheit=" + einheit +
                '}';
    }

    public String getTag() {
        return tag;
    }

    public int getEinheit() {
        return einheit;
    }

    public String getFach() {
        return fach;
    }

    public String getKlasse() {
        return klasse;
    }
}
