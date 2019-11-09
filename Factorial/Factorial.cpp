unsigned int factorial (unsigned int n){
	int num = 1;

	for (int i = 2; i <= n; i++)
		{
			num = num * i;
		}
	
	return num;
}