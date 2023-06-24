#include <iostream>
using namespace std;

template <class T>
inline void in(T &x)
{
	register T c = getchar();
	x = 0;
	T neg = 0;
	for (; ((c < 48 || c>57) && c != '-'); c = getchar());
	if (c == '-') { neg = 1; c = getchar(); }
	for (; c > 47 && c < 58; c = getchar()) { x = (x << 1) + (x << 3) + c - 48; }
	if (neg) x = -x;
}
template <typename T> void Write(T x) {if (x > 9) Write(x/10); putchar(x%10+48);}
template <typename T> void write(T x) {if (x < 0) {putchar('-'); x = -x;} Write(x);}

int n, m, a, sum1, sum2;
const int p = 1e9+7;
int main(){
	in(n); in(m);
	for (int i = 1, tmp = 0; i <= n; i++){
		in(a);
		tmp = (tmp+a)%p;
		sum1 = (sum1+1ll*a*i-tmp)%p;
	}
	for (int i = 1, tmp = 0; i <= m; i++){
		in(a);
		tmp = (tmp+a)%p;
		sum2 = (sum2+1ll*a*i-tmp)%p;
	}
	write((1ll*sum1*sum2%p+p)%p);
	
	return 0;
}

/*
#include <bits/stdc++.h>

using namespace std;
int n, m, a, sum1, sum2;
const int p = 1e9+7;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	for (int i = 1, tmp = 0; i <= n; i++){
		cin >> a;
		tmp = (tmp+a)%p;
		sum1 = (sum1+abs(1ll*a*i-tmp+1ll*p*p))%p;
	}
	for (int i = 1, tmp = 0; i <= m; i++){
		cin >> a;
		tmp = (tmp+a)%p;
		sum2 = (sum2+abs(1ll*a*i-tmp+1ll*p*p))%p;
	}
	cout << (1ll*sum1*sum2%p+p)%p << '\n';
	
	return 0;
}
*/
