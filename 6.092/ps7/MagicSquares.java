import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class MagicSquares {
	public static boolean isMagicSquare(ArrayList<ArrayList<Integer>> square) {
		int lastSum = -1;
		int sum;
		//checking rows
		for(int i = 0; i < square.size();i++) {
			sum = 0;
			for(int j = 0; j < square.size(); j++) {
				sum += square.get(i).get(j);
			}
			if(lastSum == -1) {
				lastSum = sum;
			} else if(lastSum != sum) {
				return false;
			}
		}
		//checking columns
		for(int j = 0; j < square.size(); j++) {
			sum = 0;
			for(int i = 0; i < square.size(); i++) {
				sum += square.get(i).get(j);
			}
			if(lastSum != sum) {
				return false;
			}
		}
		//checking diagonal - 1
		sum = 0;
		for(int i = 0; i < square.size();i++) {
			sum += square.get(i).get(i);
		}
		if(lastSum != sum) {
			return false;
		}
		//checking diagonal - 2
		sum  = 0;
		for(int i = 0; i < square.size();i++) {
			for(int j = 0; j < square.size(); j++) {
				if (i + j + 1 == square.size()) {
					sum += square.get(i).get(j);
				}
			}
		}
		if(lastSum != sum) {
			return false;
		}
		return true;
		}


	public static void main(String[] args) throws IOException {
		FileReader fr = new FileReader("src/Mercury.txt");
		BufferedReader br = new BufferedReader(fr);
		String myLine;
		ArrayList<ArrayList<Integer>> square = new ArrayList<ArrayList<Integer>>();
		while ((myLine = br.readLine()) != null) {
			ArrayList<Integer> row = new ArrayList<Integer>();
			for (String val : myLine.split("\t")) {
				if (!val.isEmpty()) {
					row.add(Integer.valueOf(val));
				}
			}
			if (!row.isEmpty()) {
				square.add(row);
			}
		}
		System.out.println((isMagicSquare(square)) ? "It is a Magic Square!" : "It is not a Magic Square.");
		br.close();

	}
}
