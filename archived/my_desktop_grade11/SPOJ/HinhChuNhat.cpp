#include <bits/stdc++.h>
//theo canh: O(n^2log(n^2))
//co the sort theo diem dpt O(n^2logn) 
#define int long long int

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,ii> i4;
vector<ii> a;
vector<i4> edge;
int n;

bool check(i4 a, i4 b){
	if (a.first.first+a.second.first!=b.first.first+b.second.first) return false;
	if (a.first.second+a.second.second!=b.first.second+b.second.second) return false;
	return (a.first.first-a.second.first)*(a.first.first-a.second.first)+(a.first.second-a.second.second)*(a.first.second-a.second.second)==(b.first.first-b.second.first)*(b.first.first-b.second.first)+(b.first.second-b.second.second)*(b.first.second-b.second.second);
}
int calcS(i4 a, i4 b){
	return sqrt(((b.first.first-a.first.first)*(b.first.first-a.first.first)+(b.first.second-a.first.second)*(b.first.second-a.first.second))
		*((b.second.first-a.first.first)*(b.second.first-a.first.first)+(b.second.second-a.first.second)*(b.second.second-a.first.second)));
}

int32_t main(){
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	for (int i = 0; i < n; i++) for (int j = 0; j < i; j++){
		//edge.push_back({{a[i].first+a[j].first,a[i].second+a[j].second}})
		edge.push_back({a[i],a[j]});
	}
	sort(edge.begin(),edge.end(),[](i4 a, i4 b){
		if (a.first.first+a.second.first!=b.first.first+b.second.first) return (a.first.first+a.second.first<b.first.first+b.second.first);
		if (a.first.second+a.second.second!=b.first.second+b.second.second) return (a.first.second+a.second.second<b.first.second+b.second.second);
		return (a.first.first-a.second.first)*(a.first.first-a.second.first)+(a.first.second-a.second.second)*(a.first.second-a.second.second)<=(b.first.first-b.second.first)*(b.first.first-b.second.first)+(b.first.second-b.second.second)*(b.first.second-b.second.second);
	});
	//for (auto it: edge) cout << it.first.first << "," << it.first.second << " " <<  it.second.first << "," << it.second.second << endl; 
	int res = 0;
	for (int i = 0; i < n*(n-1)/2-1;){
//		int tmp = 0;
//		while (i<n*(n-1)/2-1&&check(edge[i],edge[i+1])){
//			res += ++tmp;
//			i++;
//		}
//		if (check(edge[i],edge[i+1])){
//			res = max(res,calcS(edge[i],edge[i+1]));
//			auto it = edge[i], it1 = edge[i+1];
//			cout << it.first.first << "," << it.first.second << " " <<  it.second.first << "," << it.second.second << endl; 
//			cout << "-> "<< it1.first.first << "," << it1.first.second << " " <<  it1.second.first << "," << it1.second.second << endl; 
		int j = i;
		while (j<n*(n-1)/2-1&&check(edge[j],edge[j+1])){
			j++;
		}
//		j++;
		for (int x = i; x <= j; x++) for (int y = i; y < x; y++) res = max(res,calcS(edge[x],edge[y]));
		i = j+1;
	}
	cout << res;
	return 0;
}
