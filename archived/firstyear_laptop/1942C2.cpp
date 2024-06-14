//https://media.discordapp.net/attachments/1030096023328149509/1227735054801965177/image.png?ex=66297c5f&is=6617075f&hm=be6a5748de4d2eb60093b34cdb614a1dbceddfe77cb42d409511b4dac8a369ca&=&format=webp&quality=lossless&width=1440&height=405
#include<bits/stdc++.h>

using namespace std;
const int maxN = 2e5+5;
int n, x, y, a[maxN];
void solve(){
	cin >> n >> x >> y;
	for (int i = 0; i < x; i++){
		cin >> a[i];
		a[i]--;
	}
	sort(a,a+x);
	int res = 0;
	vector<int> vec[2];
	for (int i = 0; i < x; i++){
		int d = (a[(i+1)%x]-a[i]+n)%n;
		vec[d%2].push_back(d);
	}
	sort(vec[0].begin(),vec[0].end());
	for (int d: vec[0]){
		int tmp = min((d-2)/2,y);
		res += tmp+(y>=(d-2)/2);
//		cout << d << " " << tmp << " " << (y>=tmp) << "\n";
		x += tmp;
		y -= tmp;
	};
	for (int d: vec[1]){
		int tmp = min((d-1)/2,y);
		res += tmp;
		x += tmp;
		y -= tmp;
	}
	cout << res+x-2 << "\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	solve();
}

