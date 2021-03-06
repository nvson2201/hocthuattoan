#include <iostream>
#include <cmath>
using namespace std;


long long int countSmaller (long long int x) {
    long long int count = 0;
    for (long long int i = 1; i < 1e6; i++) {
        if(x-i*i <= 0) break;
        count += (long long int)sqrt(x - i*i);
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    long long int ID, K;
    cin >> ID >> K;

    long long int left = 2;
    long long int right = 2*1e12;

    while (left < right) {
        long long int mid = left + (right - left)/2;
        if (countSmaller(mid) >= K)
            right = mid;
        else
            left = mid + 1;  
    }
    
    cout << right;

    return 0;
}