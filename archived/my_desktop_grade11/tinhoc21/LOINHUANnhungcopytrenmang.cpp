#include <bits/stdc++.h>
using namespace std;
 
int maxLen(long int arr[], long int n)
{
    unordered_map<long int, long int> presum;
 
    long int sum = 0; 
    long int max_len = 0; 
    for (long int i = 0; i < n; i++) {
		sum += arr[i];
        if (arr[i] == 0 && max_len == 0){
            max_len = 1;
        	//cout << "chao "<<(arr[i] == 0 && max_len == 0)<< endl;
		}
        if (sum == 0)
            max_len = i + 1;
        
        if (presum.find(sum) != presum.end()) {
            max_len = max(max_len, i - presum[sum]);
        }
        else {
            presum[sum] = i;
        }
    }
 
    if (max_len>0) return max_len; else return -1;
}
 
int main()
{
    long int n;
	long int a[100005];
	cin >> n;
	for (long int i = 0; i < n; i++){ //dit me nham tu LOINHUAN.cpp 1->n
		cin >> a[i];
	}
    cout << maxLen(a, n);
 
    return 0;
}
