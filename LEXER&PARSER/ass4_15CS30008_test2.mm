// Testing function definitions and function calling

int func(int a,int b){
	b = ++a;
	return b;
}

void main(){
	int a = 10;
	int b = 10;

	b = func(a,b);
}
