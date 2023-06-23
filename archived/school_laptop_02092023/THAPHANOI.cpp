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

int n;
int val;
string res, inp;
void f(int k, int s, int t, int tmp){
	if (val==0||k==0) return;
	if (val<=((int)1<<(k-1))-1){
		f(k-1,s,tmp,t);
		return;
	}
	val -= ((int)1<<(k-1))-1;
	for (int i = 1; i <= k-1; i++) res[i] = tmp - 1 + 'A';
	if (val) res[k] = t - 1 + 'A', val--; //k = 1
	f(k-1,tmp,t,s);
}
int g(int k, int s, int t, int tmp){
	if (k==0) return 0;
	if (inp[k]==s-1+'A') return g(k-1,s,tmp,t);
	return g(k-1,tmp,t,s)+((int)1<<(k-1));
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> val;
	res.assign(n+1,'A');
	res[0] = '#';
	f(n,1,3,2);
	cout << res.substr(1,n) << "\n";
	cin >> inp;
	inp = "#" + inp;
	cout << g(n,1,3,2);
	
	return 0;
}
