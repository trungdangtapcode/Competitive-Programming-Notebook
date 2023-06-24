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
 
// Function to count total number of pairs
// of elements whose sum is prime
int numPairsWithPrimeSum(long int* arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long int sum = arr[i] + arr[j];
            if (isPrime(sum)) {
            	//cout << arr[i] << " " << arr[j] << endl;
                count++;
            }
        }
    }
    return count;
}
 
// Driver Code
int main()
{
    //int arr[] = { 1, 2, 3, 4, 5 };
    int n;
    cin >> n;
    long int arr[2000];
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	} 
    cout << numPairsWithPrimeSum(arr, n); //copy tren mang do hihi
    return 0;
}
