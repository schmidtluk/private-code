import java.io.DataOutputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Map;
import java.util.TreeMap;

public class ScheduleIO {
    public void writeBinary(TreeMap<String, Unterricht> klassenTreeMap, String klassenname){
        try (DataOutputStream dos = new DataOutputStream(new FileOutputStream(klassenname + ".bin"))){
            for (Map.Entry<String, Unterricht> entry: klassenTreeMap.entrySet()){
                if (entry.getKey().equals(klassenname)){
                    dos.writeUTF(klassenname);
                    dos.writeUTF(entry.getValue().getFach());
                    dos.writeUTF(entry.getValue().getKlasse());
                    dos.writeUTF(entry.getValue().getTag());
                    dos.write(entry.getValue().getEinheit());
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
