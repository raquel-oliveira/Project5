package dissimulator;

public interface Pattern {

	public int nextPosition(int position);
	public boolean hasNext(int position, int[] array);
	public int initializePosition(int[] array);
}
