#include <bits/stdc++.h>

using namespace std;
int k, n;
vector<int> a;

bool check(int x){
	int sumOR = 0, res = 0;
	for (int i = 0; i < n; i++){
		sumOR |= a[i];
//		cout << (sumOR&x) << " " << x <<" " <<(sumOR&x==x)<< endl;
		if ((sumOR&x)==x) res++, sumOR = 0; 
		//AND(sumOR)=x=>x la con (chung) (cua) tat ca sumOR
	}
//	cout << (sumOR&x==x) << " " << res << endl;
	return (res>=k);
}

int main(){
	ios::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	cin >> n >> k;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	//2^30 = 1.07e9
	int res = 0;
	for (int i = 30; i >= 0; i--){ //greedy: all in theo thu tu tu dien (kha chac chan)
		if (check(res+(1<<i))) res += (1<<i);
	}
	cout << res;
	
	return 0;
}
