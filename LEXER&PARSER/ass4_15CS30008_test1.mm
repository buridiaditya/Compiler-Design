// Testing declarations and expressions

int a = 10;
int b = a;
Matrix c[10][20];

void main(){
	int a = 10;
	int b = 10;
	int c = a*b;
	Matrix e[20][10];
	Matrix f[20][10];
	e[4][5] = e[3][2] + f[5][6];
	e[4][5] = a * f[5][6];
	for( a = 10; a > 0; --a){
		++b;
	}
}
