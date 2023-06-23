#include<bits/stdc++.h>

using namespace std;
int n, f[1<<24];
//000100: 0 la nguyen am, 1 la phu am
//=> neu [s] la con cua tap phu am thi no ko co nguyen am thi no bi loai (-1)
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		string s;
		cin >> s;
		int mask = (1<<(s[0]-'a'))|(1<<(s[1]-'a'))|(1<<(s[2]-'a'));
		f[mask] += 1;
	}
	for (int i = 0; i < 24; i++){
		for (int mask = 0; mask < (1<<24); mask++) if (mask&(1<<i)){
			f[mask] += f[mask^(1<<i)]; 
		}
	}
	int res = 0;
	for (int i = 0; i < (1<<24); i++) res = res^((n-f[i])*(n-f[i]));
	cout << res;
	
	
	return 0;
}
