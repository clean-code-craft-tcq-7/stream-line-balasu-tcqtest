package test;

import static org.junit.Assert.*;

import java.io.IOException;

import org.junit.Test;

import receiverinjava.ReceiverDataManipulator;
import receiverinjava.TextfileInput;

public class DataReceiverTest {


	    @Test
	    public void testParameterReader() throws NumberFormatException, IOException {
	        ReceiverDataManipulator reader = new ReceiverDataManipulator();
	        reader.ReceiverDataProcessor(TextfileInput.TempInput_filePath);
	        reader.ReceiverDataProcessor(TextfileInput.SOCInput_filePath);
	        assertEquals(10.0, reader.getMax(), 0.001);
	        assertEquals(1.0, reader.getMin(), 0.001);
	        assertEquals(5.5, reader.getSMA(), 0.001);
	    }
	}


