void main(){
	int a = 9,b = 18;
	double c = 7.27,d = c;
	char e = a, f = 'p';
	Matrix A[3][3]; // Matrix initialization not handled eg. A[3][3] = {2,2,2;2,2,2}
	a = -a;
	a -= a;
	a += a;
	a *= a;
	a /= a;
	a %= a;
	if(a > b) b--;
	else b++;
	a >>= b;
	a |= b;
	return;
}

// Things Not Handled:

// Matrix Initialization
// if(constant) constant conditionals
// Matrix Transpose M.'