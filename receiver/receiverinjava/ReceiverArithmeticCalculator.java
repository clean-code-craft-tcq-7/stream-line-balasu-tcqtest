package receiverinjava;

import java.io.IOException;
import java.util.Scanner;

public class ReceiverArithmeticCalculator extends ReceiverDataManipulator {

	public void ReceiverCalculations(String filePath) throws NumberFormatException, IOException {
		try (Scanner scanner = new Scanner(filePath)) {
			int[] values = new int[5];
			int count = 0;
			double sum = 0;
			double max = Integer.MIN_VALUE;
			double min = Integer.MAX_VALUE;

			while (scanner.hasNextInt()) {
				int value = scanner.nextInt();

				max = Math.max(max, value);
				min = Math.min(min, value);

				sum += value;
				if (count < 5) {
					values[count] = value;
				} else {
					sum -= values[0];
					for (int i = 0; i < 4; i++) {
						values[i] = values[i + 1];
					}
					values[4] = value;
				}
				count++;
				double movingAverage = (count < 5) ? sum / count : sum / 5;
			}
		}
	}
}
