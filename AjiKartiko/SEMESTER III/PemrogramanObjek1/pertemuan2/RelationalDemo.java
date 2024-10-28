public class RelationalDemo{
	public static void main(String[] args){
		//beberapa nilai variable
		int i = 37;
		int j = 42;
		int k = 42;
		
		System.out.println("Nilai Variabel...");
		System.out.println("	i = " + i);
		System.out.println("	j = " + j);
		System.out.println("	k = " + k);
		
		//lebih besar dari
		System.out.println("Lebih besar...");
		System.out.println("	i = " + (i > j));
		System.out.println("	j = " + (j > i));
		System.out.println("	k = " + (k > j));

		//lebih besar atau sama dengan
		System.out.println("lebih besar atau sama dengan...");
		System.out.println("	i > j = " + (i > j));
		System.out.println("	j > i = " + (j > i));
		System.out.println("	k > j = " + (k > j));

		//lebih kecil
		System.out.println("lebih kecil...");
		System.out.println("	i < j = " + (i < j));
		System.out.println("	j <= i = " + (j <= i));
		System.out.println("	k == j = " + (k == j));
		System.out.println("	i != j = " + (i != j));
	}
}