int printInt(int a);
int fib(int n){
	if(n<=1)
		return 0;
	return fib(n-1) + fib(n-2);
}

int mul(int a,int b){
 	return a*b;
}

int main(){
	
	int c = 3,a = 4;
	int b = mul(c,(mul(a,a)));
	int d = fib(b-1) + fib(fib(b-1));
	char e = fib(d);
	d = printInt(d);
	return 0;
}
