import org.junit.Assert;
import org.junit.Test;

public class MainTest {

    @Test
    public void solve() {
        String sum = Main.Solve("11+22");
        Assert.assertEquals("11+22=33", sum);
    }
}