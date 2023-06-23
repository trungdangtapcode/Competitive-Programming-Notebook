#include<bits/stdc++.h>

using namespace std;
int n, q, x, cha[1000005];
char c;
vector<pair<char,int>> query;

int timcha(int x){
	return cha[x] = (cha[x]==x?x:timcha(cha[x]));
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n+1; i++) cha[i] = i;
	while (q--){
		cin >> c >> x;
		if (c=='-'){
			cha[x] = timcha(x+1);
		} else {
			cout << (timcha(x)==n+1?-1:timcha(x)) << "\n";
		}
	}
	
	return 0;
}
