#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        double i = (1.0+sqrt(1-4*(2-2*n)))/2;
        cout << (abs(i-(int)i)<0.0000001 ? "1" : "0") << "\n";
    }	
    return 0;
}