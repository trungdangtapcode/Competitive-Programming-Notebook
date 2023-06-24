#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <fstream>
#include <string.h>
//#include <algorithm>
//functional
//limit
//numeric_limits

using namespace std;


int main() {
	long int n, k;
	long int result = -1;
	long long int *a = new long long int[1000001];
	long long int *sum = new long long int[1000001];
	cin >> n >> k;
	sum[0] = 0;
	for (long int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] %= k; //chi thao tac voi so du
		a[i] = (a[i] + k)%k; //-a (mod k) = k-a (mod k)
		//-a (mod k) = -(a (mod k)) = k-a (mod k) (-a la k-a khi thao tac (-a+(k-a)=k)), k-a>0 nhu ta can
		sum[i] = (sum[i-1] + a[i])%k; //sum[j] - sum[i-1] chia het cho k => sum[j] va sum[i-1] cung so modular
	}
	//unordered_map<long long int, long int> presum;
	//for (long int i = 0; i <= n; i++){
	//	if (presum.find(sum[i]) != presum.end()){
	//		result = max(result, i - presum[sum[i]]);
	//	} else {
	//		presum[sum[i]] = i;
	//	}
	//}
	//cout << result;
	long int *modK = new long int[1000001];
	for (long int i = 0; i < k; i++) modK[i] = -1;
	for (long int i = n; i >= 0; i--) modK[sum[i]] = i;
	for (long int i = 0; i <= n; i++){
		if (modK[sum[i]]!=-1){
			result = max(result,i-modK[sum[i]]); //modK tra ve la i-1 nhung j-(i-1)+1 = j-i
		}
	}
	if (result>0) cout << result; else cout << -1;
	
	
	
	
	return 0;
}
