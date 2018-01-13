import java.io.*;
import java.util.Map;
import java.util.TreeMap;

public class Unterrichtsplanung {
    private TreeMap<Integer, Lehrer> lehrerTreeMap;
    private TreeMap<String, Unterricht> klassenTreeMap;

    private void read(){
        try (BufferedReader br = new BufferedReader(new FileReader("unterricht.txt"))){
            String line;
            String[] split;

            Lehrer ph;
            while ((line = br.readLine()) != null){
                split = line.split(";");

                ph = new Lehrer(Integer.parseInt(split[0]), split[1], split[2], split[3], split[4], Integer.parseInt(split[5]));
                lehrerTreeMap.put(Integer.parseInt(split[0]), ph);
                klassenTreeMap.put(split[3], new Unterricht(split[2], split[3], split[4], Integer.parseInt(split[5])));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private void tellUnterricht(String klassenname, String tag, int einheit){
        for (Map.Entry<String, Unterricht> entry : klassenTreeMap.entrySet()){
            if (entry.getKey().equals(klassenname)){
                if (entry.getValue().getTag().equals(tag)){
                    if (entry.getValue().getEinheit() == einheit){
                        entry.getValue().toString();
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
    }
}
