
import org.junit.Assert;
import org.junit.Test;
public class MainTest {
    @Test
    public void solvesum() {
        String sum = Main.Solve("11+22");
        Assert.assertEquals("11+22=33", sum);
    }
    @Test
    public void solvejian() {
        String jian= Main.Solve("22-11");
        Assert.assertEquals("22-11=11", jian);
    }
    @Test
    public void solveji() {
        String ji = Main.Solve("10*2");
        Assert.assertEquals("10*2=20", ji);
    }
    @Test
    public void solvechu() {
        String chu = Main.Solve("22/11");
        Assert.assertEquals("22/11=2", chu);
    }
}
