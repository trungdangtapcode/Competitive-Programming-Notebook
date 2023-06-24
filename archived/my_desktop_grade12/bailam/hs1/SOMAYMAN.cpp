#include<bits/stdc++.h>

using namespace std;
long long int u, v;
vector<long long int> luckylist;

void tries(long long int num, int k){
	luckylist.push_back(num);
	if (k>=10){
		return;
	}
	tries(10*num+4,k+1);
	tries(10*num+7,k+1); 
}

int main(){
	freopen("SOMAYMAN.INP","r",stdin);
	freopen("SOMAYMAN.OUT","w",stdout);
	
	tries(0,0);
	sort(luckylist.begin(),luckylist.end());
	cin >> u >> v;
	long long int res = 0;
	for (int i = 0; i < luckylist.size()-1; i++){
		if (luckylist[i]<u&&v<=luckylist[i+1]){
			res = (v-u+1)*luckylist[i+1];
			break;
		};
		if (luckylist[i]<u&&u<=luckylist[i+1]){
			res += (luckylist[i+1]-u+1)*luckylist[i+1];
		} else if (u<=luckylist[i]&&luckylist[i+1]<v){
			res += (luckylist[i+1]-luckylist[i])*luckylist[i+1];
		} else if (luckylist[i]<v&&v<=luckylist[i+1]){
			res += (v-luckylist[i])*luckylist[i+1];
		};
	}
	cout << res;
	
	return 0;
}
