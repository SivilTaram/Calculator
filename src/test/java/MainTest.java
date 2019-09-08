import org.junit.Assert;
import org.junit.Test;

import javax.script.ScriptEngine;
import javax.script.ScriptEngineFactory;
import javax.script.ScriptEngineManager;
import javax.script.ScriptException;
import java.util.List;
import java.util.Vector;

import static org.junit.Assert.*;

public class MainTest {
    int n;
    Vector<String> fs;

    public MainTest() {
        this.n = 1000;
        this.fs = new Vector<String>();
        for (int i = 0; i < n; i++) {
            String f = Main.MakeFormula();
            this.fs.add(f);
        }
    }

    @org.junit.Test
    public void solve_test1() throws ScriptException {
        ScriptEngineManager sem = new ScriptEngineManager();
//        List<ScriptEngineFactory> list = sem.getEngineFactories();
//        for (ScriptEngineFactory f: list) {
//            System.out.println(f.getNames());
//        }
        ScriptEngine se = sem.getEngineByName("js");
        assert se != null : "jython is not available";
        for (String f : this.fs) {
            System.out.println(f);
            String ground_true = se.eval(f).toString();
            String result = Main.Solve(f);
            int eq_idx = result.indexOf("=");
//            assert ground_true.equals(result.substring(eq_idx + 1)): "Ground true is {}, but the result is {}".format(ground_true, result);
            Assert.assertEquals("not equal", ground_true, result.substring(eq_idx + 1));
        }
    }

    @Test
    public void solve_test2() {
        String f = "98-42*76+58";
        Main.Solve(f);
    }
}
