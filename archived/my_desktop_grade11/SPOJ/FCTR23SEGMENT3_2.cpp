#include <bits/stdc++.h>

using namespace std;
int n, k;
vector <pair<long long int,long long int>> a;
vector <long long int> aR; //lower_bound
vector <long long int> aL;
int nxt[200005][100];

void input(){
	int inn;
	cin >> inn;
	vector <pair<long long int,long long int>> inp;
	for (int i = 0; i < inn; i++){
		long long int x, y;
		cin >> x >> y;
		inp.push_back({x,y});
	}
	sort(inp.begin(),inp.end());
	long long int last = -1;
	for (int i = 0; i < inn; i++){
		if (inp[i].second>last) {
			last = inp[i].second; 
			a.push_back(inp[i]); 
			aL.push_back(inp[i].first); 
			aR.push_back(inp[i].second);
		}
	}
	n = a.size();
	
	memset(nxt,0,sizeof(nxt));
	k = log(n)/log(2)+1;
	int j = 0;
	for (int i = 0; i < n; i++){
		while (j<n&&aL[j]<=aR[i]+1) j++;
		nxt[i][0] = j-1; //dixa
	}
	for (int i = 1; i <= k; i++){
		for (int j = 0; j < n; j++){
			nxt[j][i] = nxt[nxt[j][i-1]][i-1];
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
//	for (int i = 0; i < n; i++){
//		cout << a[i].first<<"|"<<aL[i] << " " << a[i].second<<"|" <<aR[i]<< "   "  << endl;
//	}
//	cout << endl;
//	for(int i = 0; i <= k; ++i){
//        for(int u = 0; u < n; ++u) cout << nxt[u][i] << " ";
//		cout << endl;
//	}
	
	
	int q;
	long long int x, y;
	int up, down;
	cin >> q;
	for (int i = 0; i < q; i++){
		int res = 1;
		cin >> x >> y;
		int BS = upper_bound(aL.begin(),aL.end(),x)-aL.begin()-1;
		if (BS == -1) { cout << -1 << "\n"; continue; } //outL
		if (aR[BS] >= y) { cout <<  1 << "\n"; continue; } //can't solve for length is 1 ;(
		
		for(int i = k; i >= 0; --i)
	        if (aR[nxt[BS][i]] < y) {
	            BS = nxt[BS][i];
	            res += 1<<i;
	        }
		
		bool outR = true;
		for(int i = 0; i < k; ++i) 
        	if (aR[nxt[BS][i]] >= y){
            	cout << (res + 1<<i) << "\n";
            	outR = false;
            	break;
            }
        if (outR) cout << -1 << "\n";
	}
	
		
	return 0;
}
