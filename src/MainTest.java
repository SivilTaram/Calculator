import org.junit.Test;
import org.junit.Assert;
import org.junit.Test;
import static org.junit.Assert.*;

public class MainTest {

    @Test
    public void solve() {
        String sum = Main.Solve("21+13");
        Assert.assertEquals("21+13=34", sum);
    }
}