import java.io.FileNotFoundException;
import java.io.PrintStream;

public class File{
    public static void main(String[] args) throws FileNotFoundException {
        PrintStream ps = new PrintStream("D:\\1.txt");
        System.setOut(ps);
        System.out.println("看看我在哪里？");
        System.out.println("==============");
        System.out.println("我在D盘下的1.txt文件中去了。");
        ps.close();
    }
}