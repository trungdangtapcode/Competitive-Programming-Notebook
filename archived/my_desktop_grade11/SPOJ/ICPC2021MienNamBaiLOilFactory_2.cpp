#include <bits/stdc++.h>

using namespace std;
bool isAllEven = false; 
int n;
vector<int> a;
map<int,int> odd, even;
string s;
int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i]%2==0) even[a[i]]++;
		else odd[a[i]]++;
	}
	cin >> s;
	
	long long int res = 0; //sum
	for (int i = 0; i < n; i++) res += a[i];
	for (int i = 0; i < s.length(); i++){
		if (s[i]=='0'){ //even -> even + odd
			map <int, int> tmp;
			for (auto it: even){
				int key = it.first;
				int cnt = it.second;
				
				res -= (long long int)(key/2)*cnt;
				int tmpKey = (key/2);
				if (tmpKey%2==0) tmp[tmpKey] += cnt;
				else odd[tmpKey] += cnt;
			}
			even = move(tmp);
		}
		if (s[i]=='1'){ //odd -> even
//			map <int, int> tmp;
			for (auto it: odd){
				int key = it.first;
				int cnt = it.second;
				
				res -= cnt;
				int tmpKey = key-1;
				even[tmpKey] += cnt;
			}
			odd.clear();
//			odd = move(tmp);
		}
		cout << res << '\n';
	}
//	cout << res;
	
	return 0;
}
