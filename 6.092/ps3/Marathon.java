
public class Marathon {
	public static int best(int[] times) {
		int min = 0;
		for (int i = 1; i < times.length; i++) {
			if (times[i] < times[min]) {
				min = i;
			}
		}

		return min;
	}

	public static int second_best(int[] times) {
		int first = best(times);
		int min = 0;
		for (int i = 1; i < times.length; i++)
			if (i != first)
				if (times[i] < times[min])
					min = i;

		return min;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String[] names = { "Elena", "Thomas", "Hamilton", "Suzie", "Phil", "Matt", "Alex", "Emma", "John", "James",
				"Jane", "Emily", "Daniel", "Neda", "Aaron", "Kate" };

		int[] times = { 341, 273, 278, 329, 445, 402, 388, 275, 243, 334, 412, 393, 299, 343, 317, 265 };
		int first = best(times);
		System.out.println(names[first] + ":" + times[first]);
		int second = second_best(times);
		System.out.println(names[second] + ":" + times[second]);
	}

}
