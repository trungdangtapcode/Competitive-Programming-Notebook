#include<bits/stdc++.h>

using namespace std;
string s, res;
int n, cnt[105]; 
int main(){
	cin >> s;
	n = s.length();
	for (char c: s){
		cnt[c-'A']++;
	}
	for (int i = 0; i <= 'Z'-'A'; i++){
		while (cnt[i]>=2){
			res.push_back(i+'A');
			cnt[i] -= 2;
		}
	}
	for (int i = 0, dem = 0; i <= 'Z'-'A'; i++){
		if (cnt[i]==1){
			if (dem==1){
				cout << "NO SOLUTION";
				return 0;
			}
			res.push_back(i+'A');
			dem = 1;
		}
	}
	for (int i = n/2-1; i >= 0; i--) res.push_back(res[i]);
	cout << res;
	
	return 0;
}
