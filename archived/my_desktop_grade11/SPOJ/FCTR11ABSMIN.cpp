#include <iostream>
#include <vector>
#include <algorithm>
int n;
long long int mmin = 4e9+5;
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
	vector<int> a(n);
	for (auto& it: a) in(it);
	sort(a.begin(),a.end());
	for (int i = 0; i < n-1; i++) mmin = min(mmin,1ll*a[i+1]-a[i]);
	
	write(mmin);
	return 0;
}
