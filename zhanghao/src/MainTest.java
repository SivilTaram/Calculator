import org.junit.Assert;
import org.junit.Test;

/**
 * @author: zhanghao
 * @date: 2021/9/30-19:14
 */
public class MainTest {

    @Test
    public void solve() {
        String sum = Main.Solve("11+22");
        Assert.assertEquals("11+22=33", sum);
    }
}