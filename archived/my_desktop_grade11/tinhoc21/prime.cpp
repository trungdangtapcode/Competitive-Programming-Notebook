#include <bits/stdc++.h>
using namespace std;
 
// Function to check whether a
// number is prime or not
bool isPrime(long int num)
{
	if (num < 0) return false;
    if (num == 0 || num == 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
 

 
// Driver Code
int main()
{
    int n;
    cin >> n;
    long int arr[2000];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	} 
	long int s = 0, count = 0;
	for (int i = 0; i < n; i++){
		if (isPrime(arr[i])){
			s += arr[i];
			count++;
		}
	}
	cout << count << " " << s;
    //cout << numPairsWithPrimeSum(arr, n); //copy tren mang do hihi
    return 0;
}
