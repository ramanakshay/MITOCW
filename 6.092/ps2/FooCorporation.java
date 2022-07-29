
public class FooCorporation {
	public static void print_total_pay(double basepay, int hours_worked) {
		if(hours_worked > 60 || basepay < 8.0) {
			if(hours_worked > 60) {
				System.out.println("Error. Working too much.");
			}
			if(basepay < 8.0) {
				System.out.println("Error. Paid too less.");
			} 
		} else if(hours_worked>40) {
			int overtime = hours_worked - 40;
			System.out.println(basepay*40+basepay*1.5*overtime);
		} else {
		System.out.println(basepay*hours_worked);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		print_total_pay(7.5,35);
		print_total_pay(8.2,47);
		print_total_pay(10,73);
	}

}
