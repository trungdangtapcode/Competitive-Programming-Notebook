#include <bits/stdc++.h>

using namespace std;
int n;
vector <pair<long long int,long long int>> a;
vector <long long int> aR; //lower_bound
vector <long long int> aL;
vector <int> prv;

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
			int BS = lower_bound(aR.begin(),aR.end(),inp[i].first)-aR.begin();
//			cout << i <<  " " << BS << endl; 
			while (a.size()>BS+1){
				cout <<"size: " <<a.size()-1<<" and " << BS << endl;
				a.pop_back();
				aL.pop_back();
				aR.pop_back();
			}
			last = inp[i].second; 
			a.push_back(inp[i]); 
			aL.push_back(inp[i].first); 
			aR.push_back(inp[i].second);
		
		}
	}
	n = a.size();
	for (int i = 0; i < n; i++)
		if (i > 0)
			if (a[i].first<=a[i-1].second+1) prv.push_back(prv[i-1]); else prv.push_back(i); //, cout <<"cung " <<inp[i].first<<" " <<inp[i-1].second << endl;
		else prv.push_back(0);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	for (int i = 0; i < n; i++){
		cout << a[i].first<<"|"<<aL[i] << " " << a[i].second<<"|" <<aR[i]<< "   " << prv[i] << endl;
	}
	cout << endl;
	
	int q;
	long long int x, y;
	int up, down;
	cin >> q;
	for (int i = 0; i < q; i++){
		cin >> x >> y;
		up = upper_bound(aL.begin(),aL.end(),x)-aL.begin()-1;
		down = lower_bound(aR.begin(),aR.end(),y)-aR.begin();
		if (prv[down] <= up&&up>=0&&down<n) cout << down-up+1 << endl; else cout << -1 << endl;
	}
	
		
	return 0;
}
