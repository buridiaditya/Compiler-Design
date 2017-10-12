int a = 10;
int b = a;
Matrix c[10][20];
int func(int a,int b){
	b = ++a;
	return b;
}

void main(){
	int a = 10;
	int b = 10;
	int c = a*b;
	int * d = &a;
	Matrix e[20][10];
	Matrix f[20][10];
	e[4][5] = e[3][2] + f[5][6];
	e[2][3] = (*d) + c;
	b = func(a,b);
	while(a--){
		a = 10;
	}
}
