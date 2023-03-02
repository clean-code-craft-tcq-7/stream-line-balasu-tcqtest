package receiverinjava;

import java.io.IOException;

public class ReceiverDataManipulator {
	private double max = Double.MIN_VALUE;
	private double min = Double.MAX_VALUE;
	private double sma = 0.0;

	public void ReceiverDataProcessor(String filePath) throws NumberFormatException, IOException {
		ReceiverArithmeticCalculator calculate = new ReceiverArithmeticCalculator();
		calculate.ReceiverCalculations(filePath);
	}

	public double getMax() {
		return max;
	}

	public double getMin() {
		return min;
	}

	public double getSMA() {
		return sma;
	}
}
