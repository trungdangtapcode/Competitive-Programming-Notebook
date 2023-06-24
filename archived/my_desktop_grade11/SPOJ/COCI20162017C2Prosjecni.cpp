#include <bits/stdc++.h>

using namespace std;

template <typename T> inline void read(T & x)
{
    char c; bool nega=0;
    while((!isdigit(c=getchar()))&&c!='-');
    if(c=='-')
    {
        c=getchar();
        nega=1;
    }
    x=c-48;
    while(isdigit(c=getchar()))
    {
        x=x*10+c-48;
    }
    if(nega) x=-x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}

int n, jump1, jump2;
int main(){
	
	read(n);
	n--;
	if (n==1){putchar('-'); putchar('1'); putchar('\n'); return 0;}
//	if (n==0){putchar('1'); putchar('\n'); return 0;}
	jump1 = n*(n+1)/2;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			write(j + 1 + jump1*i); putchar(' '); 
			//row vi tri [n-1]. Cong thuc: (1+[k]+...+n+[k]+sum+[k])/(n+1) = n+[k]
		}
		write(n*(n+1)/2 + jump1*i); putchar('\n'); //row vi tri [n-1] (2)
		jump2 += n*(n+1)/2 + jump1*i;
	}
	jump2 -= n*(n+1)/2;
	for (int i = 0; i < n; i++) write(i + 1 + jump2), putchar(' '); 
	//col vi tri [n-1]. Cong thuc: (1*[k]+...+n*[k]+sum*[k])/(n+1) = n*[k]
	write(n*(n+1)/2 + jump2); putchar('\n');
	//ca row va col vi tri [n-1][n-1]. Ket hop co 2 cong thuc
	
	return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//int n, f[105], sumf;
//int main(){
//	
//	cin >> n;
//	n--;
//	if (n<2){cout << -1 << '\n'; return 0;}
//	for (int i = 0; i < n; i++){
//		for (int j = 0; j < n; j++){
//			cout << i*n*(n+1)/2 + j + 1 << ' ';
//			f[j] += i*n*(n+1)/2 + j + 1;
//		}
//		cout << (i+1)*n*(n+1)/2 << '\n'; //lam moi row co vi tri [n-1]
//		f[n] += (i+1)*n*(n+1)/2;
//	}
//	for (int i = 0; i < n; i++) cout << (i+1)*n+n*(n+1)/2*n*(n-1)/2 << ' ', sumf += f[i]; //lam moi col co vi tri [n-1]
//	cout << (sumf&f[n]) << '\n';//lam moi row va col co vi tri [n-1][n-1]
//	assert(sumf==f[n]);
//	
//	return 0;
//}
