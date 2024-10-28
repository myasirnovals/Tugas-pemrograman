public class ConditionalOperator {
	public static void main(String[] args){
		String status = "";
		int grade = 80;

		//status dari siswa
		status = (grade >= 60)?"Passed":"Fail";

		//cetak status
		System.out.println( status );
	}
}