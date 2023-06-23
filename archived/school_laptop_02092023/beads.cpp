#include<bits/stdc++.h>

using namespace std;
int n, m;
string s, p;

int main(){
	cin >> n >> s >> m >> p;
//	s = s + s;
	for (int i = 0; i < n; i++) if (s[i] == p[0]){
		for (int j = i+1, dem = 1; j != i; j = (j+1)%n){
			if (s[j]==p[dem]) dem++;
			if (dem==m){
				cout << i+1 << endl;
				return 0;
			}
		}
	}
		
	return 0;
}
