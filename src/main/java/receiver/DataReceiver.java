package receiver;

public class DataReceiver {

	 public static void main(String[] args) {
	ReceiverDataManipulator receiver=new ReceiverDataManipulator();
	receiver.ReceiverDataProcessor(TextfileInput.TempInput_filePath);
	receiver.ReceiverDataProcessor(TextfileInput.SOCInput_filePath);
		 }
	    }

