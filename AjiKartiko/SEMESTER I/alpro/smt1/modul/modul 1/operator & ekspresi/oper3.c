#define max(a,b) ((a>b) ? a:b) 

int main(){
	
	int i = 0;
	int j = 0;
	char c = 8;
	char d = 10;
	char e = max (c, d); 
	int k = max (i, j); 
	
	printf("Nilai e = %d \n",e); 
	printf("Nilai k = %d \n", k);
	i = 2;
	j = 3;
	k = max (i++, j++);
	printf("Nilai k = %d \n", k);

	return 0;
	
}
