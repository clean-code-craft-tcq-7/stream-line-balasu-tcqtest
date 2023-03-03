package receiverinjava;

import java.io.IOException;

public class DataReceiver {

	 public static void main(String[] args) throws NumberFormatException, IOException {
	ReceiverDataManipulator receiver=new ReceiverDataManipulator();
	receiver.ReceiverDataProcessor(TextfileInput.TempInput_filePath);
	receiver.ReceiverDataProcessor(TextfileInput.SOCInput_filePath);
		 }
	    }

