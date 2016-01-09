package dissimulator;

public class Direct implements Pattern{

	public int nextPosition(int position)
	{
		return ++position;
	}
	public boolean hasNext(int position, int[] array)
	{
		if(position == array.length - 1) return false;
		return true;
	}
	public int initializePosition(int[] array)
	{
		return 0;
	}
}
