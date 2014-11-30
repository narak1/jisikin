
import Calendar.JCalendar;

public class JCalTest
{
public static void main(String[] args)
{
	JCalendar jcal = new JCalendar();   //JCalendar °´Ã¼

	if( args.length == 2 )
	{
		jcal.setCalendar(Integer.parseInt(args[0]), Integer.parseInt(args[1])-1, 1);
	}
	System.out.println("Year()=" + jcal.getYear());
	System.out.println("Month()=" + (jcal.getMonth()+1));
	System.out.println("Today()=" + jcal.getToday());
	System.out.println("FirstdayOfWeek()=" + jcal.getFirstdayOfWeek());
	System.out.println("Lastday()=" + jcal.getLastday());

	int afterEmpty = 42 - jcal.getLastday() - jcal.getFirstdayOfWeek();
	System.out.println("afterEmpty=" + afterEmpty);

}
}
