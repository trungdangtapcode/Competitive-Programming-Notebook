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

int n, s, dp[75][355];
bool p[1005];
vector<int> v;

int f(int k, int x){
	if (k==s){
		return 1;
	}
	if (dp[k][x]!=-1) return dp[k][x];
//	int &res = dp[k]px
	int res = f(k+1,x);
	for (int p = v[k]; p <= x; p *= v[k]) res = max(res,p*f(k+1,x-p));
	return dp[k][x] = res;
}

main(){
	for (int i = 2; i <= 360; i++) p[i] = 1;
	for (int i = 2; i*i <= 360; i++) if (p[i]) for (int j = i*i; j <= 360; j+=i) p[j] = 0;
	for (int i = 2; i <= 360; i++) if (p[i]) v.push_back(i);
	for (int i = 0; i <= 72; i++) for (int j = 0; j <= 350; j++) dp[i][j] = -1;
	
	s = v.size();
	cin >> n;
	cout << f(0,n);
	
//	for (int i = 1; i <= 350; i++) cout << f(0,i) << " ";
	
	return 0;
}

/*

int n;
int lcm(int a, int b){
	return a/__gcd(a,b)*b;
}
map<pair<int,int>,int> dp;

int f(int x, int y){
	if (x==0) return y;
//	cout << x << " " << y << endl;
	if (dp.count({x,y})) return dp[{x,y}]; 
	int res = 0;
	for (int i = 1; i <= x; i++) res = max(res,f(x-i,lcm(y,i)));
	return dp[{x,y}] = res;
}

string g(int x){
	map<int,int> mp;
	for (int i = 2; i*i <= x; i++){
		while (x%i==0) mp[i]++, x/=i;
	}
	if (x>1) mp[x]++;
	for (auto it: mp) cout << it.first << "^" << it.second << "*";
	if (mp.empty()) cout << "1^1";
	return "\n";
}

int main(){
//	cin >> n;
//	for (int i = 0; i <= n; i++) dp[i] = -1;
//	cout << f(n,1);
	for (int i = 1; i <= 50; i++){
		cout << i << " = " << f(i,1) << " = ";
		cout << g(f(i,1));
	};
	
	return 0;
}

*/


