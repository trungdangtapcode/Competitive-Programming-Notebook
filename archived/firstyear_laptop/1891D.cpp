#include<bits/stdc++.h>

using namespace std;
template<class integer>
inline integer to_int(const string& s, size_t* idx = 0, int base = 10) {
    size_t n = s.size(), i = idx ? *idx : 0; bool sign = false; integer x = 0;
    if (s[i] == '-')
        ++i, sign = true;
    function<int(char)> char_to_digit = [&](char c) {
        static const int d[] = {'a'-10,'0'}; 
        return tolower(c)-d[isdigit(c)]; };
    while (i < n)
        x *= base, x += char_to_digit(s[i++]);
    if (idx)
        *idx = i; 
    return sign ? -x : x; }
 
template<class integer>
inline string to_string(integer x, int base = 10) {
    bool sign = false; string s;
    if (x < 0)
        x = -x, sign = true;
    function<char(int)> digit_to_char = [](int d) {
        static const char c[] = {'a'-10,'0'};
        return c[d < 10]+d; };
    do 
        s += digit_to_char(x%base), x /= base;
    while (x > 0); 
    if (sign)
        s += '-';
    reverse(s.begin(),s.end());
    return s; }
 
template<class integer>
inline istream& read(istream& is, integer& x) {
    string s; is >> s, x = to_int<integer>(s); return is; }
 
template<class integer>
inline ostream& write(ostream& os, integer x) { return os << to_string(x); }
 
using  lll =   signed __int128; 
using ulll = unsigned __int128;
 
inline istream& operator>>(istream& is,  lll &x) { return  read(is,x); }
inline istream& operator>>(istream& is, ulll &x) { return  read(is,x); }
inline ostream& operator<<(ostream& os,  lll  x) { return write(os,x); }
inline ostream& operator<<(ostream& os, ulll  x) { return write(os,x); }
#define int __int128
const int maxN = 2e5+5, mod = 1e9+7;
int a[maxN], n;
//int g(int x){
//	return log(x)/log((int)(__lg(x)));
//}
int cacl2(int l, int r){
	return max(r-l+1,(int)0);
}
int calc(int base, int l, int r){
	int cur = 1, res = 0;
//	cout << base << " " << l << ".." << r << ": ";
	for (int i = 0; cur <= r; cur *= base, i++){
		int x = cur, y = cur*base-1;
		(res += cacl2(max(l,x),min(y,r))*i)%= mod;
	}	
//	cout << res << "\n";
	return res;
}
void solve(){
//	for (int i = 4; i <= 100; i++){
//		cout << i << ". " << g(i) << " " << (int)(__lg(i)) << "\n";
//	}
//	cout << g(1000000000000000ll) << "\n";
	int l, r;
	cin >> l >> r;
	int res = 0;
	for (int i = 3; i <= 60; i++){
		int x = ((int)1<<(i-1)), y = ((int)1<<i)-1;
		(res += calc(i-1,max(x,l),min(y,r)))%= mod;
	}
	cout << res << "\n";
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--)
	solve();
	return 0;
}
