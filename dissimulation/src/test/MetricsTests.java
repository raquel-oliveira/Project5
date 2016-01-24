package test;

import static org.junit.Assert.*;

import org.junit.Before;
import org.junit.Test;

import dissimulator.Metrics;
import java.util.BitSet;
import java.util.HashMap;

public class MetricsTests {

	Metrics met;
	
	@Before
	public void construct()
	{
		met = new Metrics();
	}
	
	@Test
	/**
	 * Verify if the compression_saving calculation is right. 
	 * Here, the compressed message is much longer than
	 * the original one. The result must be negative.
	 */
	public void compressionSavingsTest()
	{
		String originalMessage = "abc";
		BitSet compressedMessage = new BitSet();
		compressedMessage.set(41);
		
		double sizeSaved = met.getCompressionSavings(originalMessage, compressedMessage);
		assertTrue(sizeSaved < 0);
	}
}
