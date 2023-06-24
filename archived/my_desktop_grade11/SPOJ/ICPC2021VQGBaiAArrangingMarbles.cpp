#include <bits/stdc++.h>

using namespace std;
int cnt[1005], cnt0[1005], n, posmax, posmin, tmp;
vector<int> cntpos[1005];
int a[1000005];

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
    
	cin >> n;
	for (int i = 0, x; i < n*n; i++){
		cin >> x;
		cnt[x]++;
		cntpos[x].push_back(i);
	}
	
	cout << "YES" << '\n';
	
	for (int i = 0; i < n; i++){
		//for (int j = 1; j <= n+1; j++) cout << j << ": " << cnt[j] << endl;
		posmax = -1; posmin = -1;
		for (int j = 1, mmax = -1e9, mmin = 1e9; j <= n+1; j++) if (cnt[j]){
			if (mmax<=cnt[j]){
				mmax = cnt[j];
				posmax = j;
			}
			if (mmin>cnt[j]){
				mmin = cnt[j];
				posmin = j;
			}
		}
		tmp = min(cnt[posmin],n);
		//cntpos[marble] list of pos increase but cnt[marble] is decrease so need size()-x
		//cout << i << " -> "; 
		for (int j = 0; j < tmp; j++) a[cntpos[posmin][cntpos[posmin].size()-cnt[posmin]]] = i, cnt[posmin]--;// cout << cnt[posmin] << " " << cntpos[posmin].size() << endl;
		//for (int j = 0; j < tmp; j++) cout << posmin << "-", cnt[posmin]--; //way 2: ans.(cout) => query => answer
		for (int j = tmp+1; j <= n; j++) a[cntpos[posmax][cntpos[posmax].size()-cnt[posmax]]] = i, cnt[posmax]--; //alway right
		//for (int j = tmp+1; j <= n; j++) cout << posmax << "+", cnt[posmax]--; //alway right
		
	}
	for (int i = 0; i < n*n; i++) cout << a[i]+1 << " ";
	
	return 0;
}
