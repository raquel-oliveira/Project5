package test;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import dissimulator.Metrics;
import java.util.BitSet;

public class MetricsTests {

	Metrics met;
	
	@Before
	public void construct()
	{
		met = new Metrics();
	}
	
	@Test
	public void compressionSavingsTest()
	{
		String originalMessage = "abc";
		BitSet compressedMessage = new BitSet();
		compressedMessage.set(41);
		System.out.println(compressedMessage.length());
		
		double sizeSaved = met.getCompressionSavings(originalMessage, compressedMessage);
		assertTrue(sizeSaved < 0);
	}

}
