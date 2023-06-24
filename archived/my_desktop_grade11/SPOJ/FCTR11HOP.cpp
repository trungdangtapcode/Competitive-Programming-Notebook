// Online C++ compiler to run C++ program online

#include <iostream>
long long int n, k;
int main() {
    // Write C++ code here
    std::cin >> n >> k;
    std::cout << n/k+(n%k!=0);

    return 0;
}
