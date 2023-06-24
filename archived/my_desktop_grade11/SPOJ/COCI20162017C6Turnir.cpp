#include <bits/stdc++.h>

using namespace std;
int n, m;
vector <pair<long long int,int>> a;
int result[2000000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;
	m = 1;
	for (int i = 1; i <= n; i++) m *= 2;
	for (int i = 0; i < m; i++){
		long long int x;
		cin >> x;
		a.push_back({x,i});
	}
	
	sort(a.begin(),a.end());
	//for (auto& it: a) cout << it.first << " " << it.second << endl;
	int base = 1;
	int i = 1, rank = n+1;
	for (auto& it: a){ //i la index trong pascal (vi tri co thu tu)
		if (i>=base){
			rank--;
			base *= 2;
		}
		result[it.second] = rank;
		i++;
	}
	
	for (int i = m-1; i>0; i-- ){
		//cout << (*it).first << " " << (*it).second << endl;
		if (a[i].first==a[i-1].first){
			result[a[i-1].second] = result[a[i].second];
		}
	}
	for (int i = 0; i < m; i++) cout << result[i] << " ";
	return 0;
}
