#include <iostream>
int n, a, mmax = -1e9-5;
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
int main(){
	in(n);
	while (n--){
		in(a);
		if (mmax<a) mmax = a;
	}
	write(mmax);
	return 0;
}
