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
int f[1000005][4];
main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	map<char,vector<int>> mp;
	mp['I'] = {};
	mp['C'] = {1,3};
	mp['P'] = {2};
	string s;
	while (cin >> s){
		if (s=="$") break;
		int n = s.length();
		s = "#" + s;
		for (int i = 1; i <= n; i++){
			for (int j = 0; j < 4; j++) f[i][j] = f[i-1][j]; 
			if (s[i]=='I') f[i][0]++;
			if (mp.count(s[i])) for (int j: mp[s[i]]){
				f[i][j] += f[max(i-2,(int)0)][(j+3)%4];
			}
//			for (int j = 0; j < 4; j++) cout << f[i][j] << " "; cout << "\n";
		}
//		cout << f[1][0] << "\n";
		cout << f[n][3] << "\n";
	}
	
	return 0;
}
