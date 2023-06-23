#include<bits/stdc++.h>

using namespace std;
int n, q, x, px, cha[300005];
char c;
vector<pair<char,int>> query;

int timcha(int x){
	return cha[x] = (cha[x]==x?x:timcha(cha[x]));
}
int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) cha[i] = i;
	q = n;
	while (q--){
		cin >> x;
		px = timcha(x);
		cout << px << " ";
		cha[px] = timcha(px%n+1);
	}
	
	return 0;
}
