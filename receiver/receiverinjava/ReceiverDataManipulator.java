package receiverinjava;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class ReceiverDataManipulator{
    private double max = Double.MIN_VALUE;
    private double min = Double.MAX_VALUE;
    private double sma = 0.0;
	List<Double> values = new ArrayList<>();
    double sum = 0.0;

    public void ReceiverDataProcessor(String filePath) throws NumberFormatException, IOException {
    try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
        String line;
        while ((line = br.readLine()) != null) {
            double value = Double.parseDouble(line);
            values.add(value);
            sum += value;

            if (values.size() >= 5) {
                double average = sum / values.size();
                double max = Double.MIN_VALUE;
                double min = Double.MAX_VALUE;

                for (double senderdata : values) {
                    if (senderdata > max) {
                        max = senderdata;
                    }
                    if (senderdata < min) {
                        min = senderdata;
                    }
                }

                System.out.println("Max: " + max);
                System.out.println("Min: " + min);
                System.out.println("SMA: " + average);
                System.out.println();
                
                double oldestValue = values.get(0);
                values.remove(0);
                sum -= oldestValue;
            }
        }
    }
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
