#include<bits/stdc++.h>

using namespace std;
int n, type, x, y, cha[200005], q, nxt[200005];
char c;
vector<pair<char,int>> query;

int timcha(int x){
	return cha[x] = (cha[x]==x?x:timcha(cha[x]));
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 1; i <= n; i++) cha[i] = i, nxt[i] = i+1;
	while (q--){
		cin >> type >> x >> y;
		if (type==1){
			cha[timcha(x)] = timcha(y);
		} else if (type==2){
			for (int i = x; i <= y;){
				cha[timcha(i)] = timcha(y);
				int tmp = i; i = nxt[i];
				nxt[tmp] = nxt[y];
			}
		} else {
			cout << (timcha(x)==timcha(y)?"YES\n":"NO\n");
		}
	}
	
	return 0;
}
