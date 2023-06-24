#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
long long int INF = 1e12, res, sumLake;
int n;
long long int h[1000000], maxL[1000000], maxR[1000000], sum[1000000];
int prv[1000000], nxt[1000000];
stack <int> s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	//ifstream inFile;
	//inFile.open("E:\\Lab\\Padoru\\test1.txt");
	cin >> n; 
	for (int i = 1; i <= n; i++) cin >> h[i];
	//inFile.close();
	
	h[0] = INF; h[n+1] = INF;
	s.push(0); //s chi toi gia tri index cua mang nen moi gan h[0] = INF
	for (int i = 1; i <= n; i++){
		while (h[i] > h[s.top()]){
			nxt[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) s.pop(); s.push(0);
	for (int i = n; i >= 1; i--){
		while (h[i] > h[s.top()]){
			prv[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	
	//for (int i = 1; i <= n; i++) cout << nxt[i] << " " ; cout << endl;
	
	
	maxL[0] = -INF; maxR[n+1] = -INF; sum[0] = 0;
	for (int i = 1; i <= n; i++) maxL[i] = max(maxL[i-1],h[i]);
	for (int i = n; i >= 1; i--) maxR[i] = max(maxR[i+1],h[i]);
	for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + h[i];
	
	sumLake = 0;
	for (int i = 1; i <= n; i++){
		sumLake += max(min(maxL[i],maxR[i])-h[i],(long long int)0);
	}
	res = 0;
	for (int i = 1; i <= n; i++){
		if ((h[i]<maxR[i]&&h[i]<maxL[i])||(h[i]>=maxR[i]&&h[i]>=maxL[i])) continue;
		long long int tmp = 0;
		
		if (h[i] < maxR[i]) tmp += nxt[i]-i-1;
		if (h[i] < maxL[i]) tmp += i-prv[i]-1;
		
		res = max(res,sumLake+tmp);
	}
	
	cout << res;
	
	return 0;
}




//	for (int i = 1; i <= n; i++) if (h[i]>=maxL[i-1]){
//		maxL[i] = h[i];
//		prv[i] = i;
//	} else {
//		maxL[i] = maxL[i-1];
//		prv[i] = prv[i-1];
//	}
//	for (int i = n; i >= 1; i--) if (h[i]>=maxR[i+1]){
//		maxR[i] = h[i];
//		nxt[i] = i;
//	} else {
//		maxR[i] = maxR[i+1];
//		nxt[i] = nxt[i+1];
//	}

//	sumLake = 0;
//	int lastNxt = -1, lastPrv = -1;
//	for (int i = 1; i <= n; i++) if (lastNxt!=nxt[i]||lastPrv!=prv[i]){
//		//long long int maxH = max( min(maxL[i]+1,maxR[i]) , min(maxL[i],maxR[i]+1) ); //tham lam 2 th lay cai cao hon
//		lastNxt = nxt[i]; lastPrv = prv[i];
//		long long int maxH = min(maxL[i],maxR[i]);
//		//cout << prv[i] <<" " << maxH << " "<< nxt[i] <<  endl;
//		//cout << maxH*(nxt[i]-prv[i]-1)-(sum[nxt[i]-1]-sum[prv[i]]) << endl;
//		//res = max(res,maxH*(nxt[i]-prv[i]-1)-(sum[nxt[i]-1]-sum[prv[i]]));
//		sumLake += max(maxH*(nxt[i]-prv[i]-1)-(sum[nxt[i]-1]-sum[prv[i]]),(long long int)0);	
//	}
//	res = 0;
//	lastNxt = -1, lastPrv = -1;
//	for (int i = 1; i <= n; i++) if (lastNxt!=nxt[i]||lastPrv!=prv[i]){
//		lastNxt = nxt[i]; lastPrv = prv[i];
//	}
