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

int fact[20005], inFact[20005], inNum[20005];
const int p = 1e9+7;

int calcCatalan(int x){
	return 1ll*fact[2*x]*inFact[x]%p*inFact[x+1]%p;
}

int main(){
	
	fact[0] = fact[1] = inFact[0] = inFact[1] = inNum[0] = inNum[1] = 1;
	for (int i = 2; i <= 2e4; i++){
		fact[i] = (1ll*fact[i-1]*i)%p;
		inNum[i] = 1ll*inNum[p%i]*(p-p/i)%p;
		inFact[i] = 1ll*inFact[i-1]*inNum[i]%p;
	} 
	
	int t, x; cin >> t;
	while (t--){
		in(x);
		write(calcCatalan(x)); putchar('\n');
	}
	return 0;
}
