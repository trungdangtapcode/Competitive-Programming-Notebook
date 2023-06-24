#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> ii;
const int mod = 1e9+7, base5 = 15625;

int getPow(int a, int b){
	int res = 1;
	while (b){
		if (b&1) res = 1ll*a*res%mod;
		a = 1ll*a*a%mod;
		b >>= 1;
	}
	return res;
}

struct bigNum{
	int a[25], l;
	bigNum(long long x){
		memset(a,0,sizeof(a));
		int l = 0;
		while (x){
			a[l++] = x%base5;
			x /= base5;
		}
	}
	bigNum operator+(bigNum other){
		int carry = 0;
		bigNum res = bigNum(0);
		for (int i = 0; i < 25; i++){
			res.a[i] = (a[i]+other.a[i]+carry)%base5;
			carry = (a[i]+other.a[i]+carry)/base5;
		}
		return res;
	}
	bigNum operator*(int other){
		int carry = 0;
		bigNum res = bigNum(0);
		for (int i = 0; i < 25; i++){
			res.a[i] = (a[i]*other+carry)%base5;
			carry = (a[i]*other+carry)/base5;
		}
		return res;
	}
	bigNum operator*(bigNum other){
		bigNum res = bigNum(0);
		for (int i = 0; i < 25; i++){
			bigNum x = (*this)*other.a[i];
			for (int j1 = 24-i, j2 = 24; j1 >= 0; j1--, j2--) x.a[j2] = x.a[j1];
			for (int j = 0; j < i; j++) x.a[j] = 0;
			res = res + x;
		}
		return res;
	}
	void print(){
		int base10 = 1e4, cur = 0;
		vector<int> res(20), base(20);
		base[0] = 1;
		for (int i = 0; i < 25; i++){
			int carry = 0;
			for (int j = 0; j < 20; j++){
				int x = (res[j]+base[j]*a[i]+carry)%base10;
				carry = (res[j]+base[j]*a[i]+carry)/base10;
				res[j] = x;
			}
			carry = 0;
			for (int j = 0; j < 20; j++){
				int x = (base[j]*base5+carry)%base10;
				carry = (base[j]*base5+carry)/base10;
				base[j] = x;
			}
		}
		reverse(res.begin(),res.end());
		bool firstDigit = true;
		for (auto x: res){
			if (x>0&&firstDigit){
				cout << x;
				firstDigit = false;
			} else if (!firstDigit){
				cout << x/1000 << x%1000/100 << x%100/10 << x%10;
			}
		};
		if (firstDigit) cout << 0;
		cout << " ";
	}
};

struct matrix{
	vector<vector<bigNum>> data;
	int n, m;
	matrix(int n, int m){
		this->n = n;
		this->m = m;
		data.assign(n,vector<bigNum>(m,bigNum(0)));
	}
	vector<bigNum> & operator [] (int i) { return data[i]; }
    void setNum(){
    	for (int i = 0; i < min(n,m); i++) data[i][i] = bigNum(1);	
	}
    
    matrix operator*(matrix other){
    	assert(m==other.n);
    	matrix res = matrix(n,other.m);
    	for (int i = 0; i < n; i++) for (int j = 0; j < other.m; j++) for (int k = 0; k < m; k++)
			res[i][j] = res[i][j] + data[i][k]*other[k][j];
    	return res;
	}
	
	matrix operator^(long long x){
		matrix res = matrix(n,m);
		matrix a = *this;
		res.setNum();
		while (x){
			if (x&1) res = res*a;
			a = a*a;
			x >>= 1;
		}
		return res;
	}
    
	void print(){
		for (auto x: data){
			for (auto y: x) y.print();
			cout << "\n";
		}
	}
	
};

int main(){
	//TLE cham vl
//	matrix x = matrix(100,100);
//	x.setNum();
//	x[1][2] = bigNum(69);
//	x.print();
//	x = (x^2)^2;
//	x.print();
//	for (int i = 0; i < 10; i++) x = x*x;
//	x.print();
//	cout << "done";
//	cin >> n >> m >> t;	
	
	return 0;
}

/* [FULL] https://ipsc.ksp.sk/2003/real/solutions/h.html

#include <stdio.h>
#include <string.h>

// * 
// * IPSC 2003 - H - Hordes of bacteria
// * Soluton in bc language
// *
// * Exponentiation of linear transformation matrix
// *   O(N*M*log K + N^3*log(T/M)*(log K)^2)
// *

#define MAXN 200
#define MAXM 2000

// 5^96 bacteria creates a new community in both input files
#define base 15625   // 5^6 = 15625
#define K 16         // (5^6)^16 = 5^96

// output notation
#define base10 10000 // 10^4 = 10000
#define K10 25       // (10^4)^25 = 10^100 > 5^96

int N, M;
long long int T;

// long number stored in quinary notation (or 5^6 notation)
typedef struct {
	int l;
	int n[K];
} big;

// sets a long number to an int (b >= 0)
void big_set_int(big *a, int b)
{
	int i=0;
	while (b && i<K) a->n[i]=b%base, b/=base, i++;
	a->l = i;
}

// sets a long number to a long number
void big_set_big(big *a, big *b)
{
	for (int i=0; i<b->l; i++) a->n[i]=b->n[i];
	a->l = b->l;
}

// adds a long number to a long number
void big_add_big(big *a, big *b)
{
	int i=0, t=0, x;
	while (i<a->l || i<b->l) x=t+(i<a->l?a->n[i]:0)+(i<b->l?b->n[i]:0),
		a->n[i]=x%base, t=x/base, i++;
	while (t && i<K) a->n[i]=t%base, t/=base, i++;
	a->l = i;
	while (a->l && !a->n[a->l-1]) a->l--;
}

// multiplies a long number by an int (b > 0)
void big_mul_int(big *a, int b)
{
	int i=0, t=0, x;
	while (i<a->l) x=t+a->n[i]*b, a->n[i]=x%base, t=x/base, i++;
	while (t && i<K) a->n[i]=t%base, t/=base, i++;
	a->l = i;
	while (a->l && !a->n[a->l-1]) a->l--;
}

// multiplies a long number by a long number
void big_mul_big(big *a, big *b)
{
	if (!a->l) return;
	
	big c;
	for (int i=0; i<a->l; i++) c.n[i]=a->n[i]; c.l=a->l; a->l=0;
	for (int i=0; i<b->l; i++)
	{
		int j=0, t=0, x;
		while (j<c.l && i+j<K)
			a->n[j+i]=(j+i<a->l?a->n[j+i]:0)+c.n[j]*b->n[i], j++;
		for (int k=0; k<j; k++) 
			x=t+a->n[k+i], a->n[k+i]=x%base, t=x/base;
		while (t && j+i<K) a->n[j+i]=t%base, t/=base, j++;
		a->l=j+i;
	}
	while (a->l && !a->n[a->l-1]) a->l--;
}

// prints a long number in decimal notation
void big_print10(big *a)
{
	int b[K10], bl=1, s[K10], sl=0;
	b[0]=1;
	for (int i=0; i<a->l; i++)
	{
		int j=0, t=0, x;
		while (j<bl) x=t+a->n[i]*b[j]+(j<sl?s[j]:0),
			s[j]=x%base10, t=x/base10, j++;
		if (sl<j) sl=j;
		while (t && j<sl) x=t+s[j], s[j]=x%base10, t=x/base10, j++;
		if (t)
		{
			while (t) s[j]=t%base10, t=t/base10, j++;
			sl=j;
		}
		j=0, t=0;
		while (j<bl) x=t+b[j]*base, b[j]=x%base10, t=x/base10, j++;
		while (t) b[j]=t%base, t/=base, j++;
		bl = j;
	}
	if (sl)
	{
		printf("%d", s[sl-1]);
		for (int i=sl-2; i>=0; i--) printf("%04d", s[i]);
	}
	else printf("0");
}

// matrix of linear tranformations filled with long numbers
typedef big matrix[MAXN][MAXN];

// multiplies a matrix from left hand side with a matrix
void matrix_mul_left(matrix *a, matrix *b)
{
	matrix c;
	for (int i=0; i<N; i++) for (int j=0; j<N; j++)
	{
		big_set_int(&c[i][j], 0);
		for (int k=0; k<N; k++)
		{
			big x;
			big_set_big(&x, &(*a)[i][k]);
			big_mul_big(&x, &(*b)[k][j]);
			big_add_big(&c[i][j], &x);
		}
	}
	for (int i=0; i<N; i++) for (int j=0; j<N; j++)
		big_set_big(&(*b)[i][j], &c[i][j]);
}

int main(void)
{
	scanf("%d %d %lld ", &N, &M, &T);
	scanf("%*s ");

	// matrix a -- matrix of all M linear transformations
	// matrix b -- matrix of first T%M linear transformations
	matrix a, b;
	for (int i=0; i<N; i++) for (int j=0; j<N; j++)
		big_set_int(&a[i][j], i==j?1:0),
		big_set_int(&b[i][j], i==j?1:0);
	for (int i=1; i<=M; i++)
	{
		char trans[20]; int p1, p2; big x;
		scanf("%s %d %d ", trans, &p1, &p2);
		if (!strcmp(trans, "die")) for (int j=0; j<N; j++)
			big_set_int(&a[j][p1], 0);
		else if (!strcmp(trans, "reproduce")) for (int j=0; j<N; j++)
			big_mul_int(&a[j][p1], p2);
		else if (!strcmp(trans, "copy")) for (int j=0; j<N; j++)
			big_add_big(&a[j][p1], &a[j][p2]);
		else if (!strcmp(trans, "teleport")) for (int j=0; j<N; j++)
			big_add_big(&a[j][p1], &a[j][p2]),
			big_set_int(&a[j][p2], 0);
		else if (!strcmp(trans, "swap")) for (int j=0; j<N; j++)
			big_set_big(&x, &a[j][p1]),
			big_set_big(&a[j][p1], &a[j][p2]),
			big_set_big(&a[j][p2], &x);
		else if (!strcmp(trans, "merry-go-round")) 
			for (int j=0; j<N; j++)
			{
				big_set_big(&x, &a[j][N-1]);
				for (int k=N-1; k; k--)
					big_set_big(&a[j][k], &a[j][k-1]);
				big_set_big(&a[j][0], &x);
			}
		if (i == T%M) 
			for (int j=0; j<N; j++) for (int k=0; k<N; k++)
				big_set_big(&b[j][k], &a[j][k]);
	}

	// we want to compute a^{T/M} * b
	//  - if T/M = 2k   then a^{2k} * b   = (a * a)^k * b
	//  - if T/M = 2k+1 then a^{2k+1} * b = (a * a)^k * (a * b)

	// computes a^{T/M} * b with O(lg(T/M)) matrix multyplications
	long long int exp=T/M;
	while (exp)
	{
		if (exp%2) matrix_mul_left(&a, &b);
		if (exp/2) matrix_mul_left(&a, &a);
		exp/=2;
	}

	// multyplies the begining vector (1, 1, ..., 1) by the computed 
	// matrix a^{T/M} * b and outputs the solution
	for (int i=0; i<N; i++)
	{
		big x;
		big_set_int(&x, 0);
		for (int j=0; j<N; j++) big_add_big(&x, &b[j][i]);
		big_print10(&x);
		printf("\n");
	}

	return 0;
}
*/
