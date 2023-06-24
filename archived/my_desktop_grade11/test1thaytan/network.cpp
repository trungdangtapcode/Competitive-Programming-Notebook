#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int, pair<int,int>> id;
vector<id> edge;
vector<int> cha (1005),uutien (1005); //uutien = size
using namespace std;
int timcha(int x){ //update
	if (cha[x]==x) return x;
	cha[x] = timcha(cha[x]);
	return cha[x];
}
void hop(int a, int b){
	if (timcha(a)==timcha(b)) return;//updated nen dung mang cha[] cua a voi b thoai mai
	if (uutien[cha[a]]>=uutien[cha[b]]){
		uutien[cha[a]]+= uutien[cha[b]];
		cha[cha[b]] = cha[a];
	} else {
		uutien[cha[b]]+= uutien[cha[a]];
		cha[cha[a]] = cha[b];
	}
}
int main(){
	int n, m, p;
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		cha[i] = i;
		uutien[i] = 1;
	}
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		edge.push_back({0,{a-1,b-1}});
	}
	for (int i = 0; i < p; i++){
		int a, b;
		long long int c;
		cin >> a >> b>> c;
		edge.push_back({c,{a-1,b-1}});
	}
	sort(edge.begin(),edge.end());
	//for (auto& i : edge){ cout <<i.first << " " << i.second.first << " " << i.second.second << endl; } //tu nhien dap an dung nen them cho vui
	long long int result = 0;
	for (auto& i : edge){
		//for (int i = 0; i < n; i++) cout << cha[i] << " "; cout << endl;
		if (timcha(i.second.first) != timcha(i.second.second)){
			hop(i.second.first,i.second.second);
			result += i.first;
		}
	}
	for (int i = 0; i < n; i++) timcha(i); //update lan cuoi
	cout << result;
	return 0;
}
