
int add(int a, int b){
	return a+b;
}



int main(){
	int a = 10;
	int b = 20;
	if(a < b){
		a++;
	}
	if(b < a){
		b = add(a,b);
	}
	b = b + add(a,b);
	return 1;
}
