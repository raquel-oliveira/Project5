package dissimulator;

public class Reverse implements Pattern{

	public int nextPosition(int position)
	{
		return --position;
	}
	public boolean hasNext(int position, int[] array)
	{
		if(position == 0) return false;
		return true;
	}
	public int initializePosition(int[] array)
	{
		return (array.length - 1);
	}
}
