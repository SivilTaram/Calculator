import org.junit.After;
import org.junit.Before;
import org.junit.jupiter.api.Test;

class MainTest {
	  @Before
	 public void setUp() throws Exception {
	        System.out.println("ø™ º≤‚ ‘");
	  }
	
	  @After
   public void tearDown() throws Exception {
	       System.out.println("≤‚ ‘Ω· ¯");
	   }
	

	
	  

	  @Test
	    public void MakeFormula() {
	        String sum = Main.MakeFormula();
	     System.out.println("MakeFormula:"+sum);
	    }
		
	  @Test
	    public void solve() {
	      String sum = Main.Solve("11+22");
	     System.out.println("solve:11+22=33");
	    }
}
