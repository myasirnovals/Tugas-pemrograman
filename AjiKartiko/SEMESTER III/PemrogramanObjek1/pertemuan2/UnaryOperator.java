public class UnaryOperator {
	public static void main(String[] args){
		int i = 10;
		int j = 3;
		int k = 0;
		
		//cetaklah hasil operasi nilai k di console, berapa
		//nilai nya kemudian analisa

		//First Operation
		k = ++j + i;
		System.out.println("k after first operation(k = ++j + i):" + k);
		System.out.println("j after first operation: " + j);

		//Second Operation
		k = j++ + i;
		System.out.println("k after second operation(k = j++ + i):" + k);
		System.out.println("j after second operation: " + j);
		
	}
}