package test;

import static org.junit.Assert.*;


import org.junit.Test;

import dissimulator.MessageTreatment;

public class FrequencyTest {

	@Test
	public void frequencyMessageTest() 
	{
		MessageTreatment msg = new MessageTreatment();
		String message = "aabccdee";
		assertEquals(msg.getNbIterations(message), "{b:1, d:1, a:2, c:2, e:2}");
	}
}
