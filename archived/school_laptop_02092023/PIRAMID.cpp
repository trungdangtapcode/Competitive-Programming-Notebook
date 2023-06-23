#include<bits/stdc++.h>

using namespace std;
//template<class integer>
//inline integer to_int(const string& s, size_t* idx = 0, int base = 10) {
//    size_t n = s.size(), i = idx ? *idx : 0; bool sign = false; integer x = 0;
//    if (s[i] == '-')
//        ++i, sign = true;
//    function<int(char)> char_to_digit = [&](char c) {
//        static const int d[] = {'a'-10,'0'}; 
//        return tolower(c)-d[isdigit(c)]; };
//    while (i < n)
//        x *= base, x += char_to_digit(s[i++]);
//    if (idx)
//        *idx = i; 
//    return sign ? -x : x; }
// 
//template<class integer>
//inline string to_string(integer x, int base = 10) {
//    bool sign = false; string s;
//    if (x < 0)
//        x = -x, sign = true;
//    function<char(int)> digit_to_char = [](int d) {
//        static const char c[] = {'a'-10,'0'};
//        return c[d < 10]+d; };
//    do 
//        s += digit_to_char(x%base), x /= base;
//    while (x > 0); 
//    if (sign)
//        s += '-';
//    reverse(s.begin(),s.end());
//    return s; }
// 
//template<class integer>
//inline istream& read(istream& is, integer& x) {
//    string s; is >> s, x = to_int<integer>(s); return is; }
// 
//template<class integer>
//inline ostream& write(ostream& os, integer x) { return os << to_string(x); }
// 
//using  lll =   signed __int128; 
//using ulll = unsigned __int128;
// 
//inline istream& operator>>(istream& is,  lll &x) { return  read(is,x); }
//inline istream& operator>>(istream& is, ulll &x) { return  read(is,x); }
//inline ostream& operator<<(ostream& os,  lll  x) { return write(os,x); }
//inline ostream& operator<<(ostream& os, ulll  x) { return write(os,x); }

#define int long long

int k, n, m;

__int128 f(int x){
	return ((__int128)x*(x+1)/2);
}
__int128 f2(int x){
	return ((__int128)x*(x+1)/2*(2*x+1)/3);
}
void in(__int128 x){
	int p = 1e18;
	if (x<p) return cout << (int)(x) << "\n", void();
	cout << (int)(x/p) << setw(18) << setfill('0') << (int)(x%p) << "\n";
}

main(){
	int t; cin >> t;
	while (t--){
		cin >> n >> m;
		k = min(n,m);
		in((__int128)k*n*m - f(k-1)*(m+n) + f2(k-1));
	}
	return 0;
}
