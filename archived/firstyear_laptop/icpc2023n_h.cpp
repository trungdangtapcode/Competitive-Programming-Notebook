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
int n, m, k, f[105][10005];
bool check[105];
const int inf = 1e19;
main(){
	cin >> n >> m >> k;
	k--;
	cout << inf*5 << "\n";
	f[1][0] = 1;
	f[2][0] += 1;
	f[2][2] -= 1;
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= m; j++){
			(f[i][j] = f[i][j]+f[i][j-1]);
//			f[i][j] = min(f[i][j],inf);
//			if (f[i][j]>inf){
//				for (int k = j; k <= m; k++) f[i][k] = inf;
//				break;
//			}
		};
		for (int j = 0; j <= m; j++){
			f[i+1][j] = f[i+1][j]+f[i][j];
//			if (f[i+1][j]>inf*5){
//				cout << i+1 << " " << j << " " << f[i+1][j] << " by " << f[i][j] << '\n';
//				break;
//			}
//			if (f[i][j]>inf){
//				for (int k = j; k <= m; k++) f[i][k] = inf;
//				break;
//			}
			f[i+1][j+i+1] = f[i+1][j+i+1]-f[i][j];
		}
	}
	cout << f[n][m] << '\n';
	if (k>=f[n][m]){
		cout << -1;
		return 0;
	}
	vector<int> res;
//	cout << f[2][1] << "--\n";
	int pref = 0;
	for (int i = 1; i < n; i++){
		int greater = 0;
		for (int j = 1; j <= n; j++){
//			if (check[j]==false){
//				smaller++;
//			}
			if (check[j]){
				greater++;
				continue;
			}
			int cur = (i-1-greater)*0+(j-1-greater) + pref;	
//			cout << i << " " << j << " " << k << " " << cur << "x\n";
//			cout << i << " " << j << " " << cur << "\n";
//			cout << "f[" << n-i << "][" << m-cur << "] = " << f[n-i][m-cur] << "\n"; 
//			if (k==0){
//				cout << j << "_... \n";
//				res.push_back(j);
//				check[j] = 1;
//				break;
//			}
			if (cur>m){
				cout << -1;
				return 0;
			};
			if (k>=f[n-i][m-cur]){
				k -= f[n-i][m-cur];
			} else {
//				cout << j << "... \n";
				pref = cur;
				res.push_back(j);
				check[j] = 1;
				break;
			}
		}
	}
	for (int x: res) cout << x << " ";
	for (int i = 1; i <= n; i++) if (!check[i]) cout << i << " ";
	return 0;	
}
