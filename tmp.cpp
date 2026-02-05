#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll quick_pow(ll a, ll p) {
    ll ans = 1; 
    while (p) {
        if ((p & 1) == 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        p >>= 1;
    }
    return ans;
}
ll inv(ll n) {
    return quick_pow(n, mod - 2) % mod;
}
ll inv100 = inv(100);
string addzero(ll n, int len) {
    stringstream ss;
    ss << setfill('0') << setw(len) << n;
    return ss.str();
}
ll p[10] = { 0 };
string s[11] = {}; vector<ll>p1(10, 1);
int main() {
    int t; cin >> t;
    s[0] = "1110111"; s[1] = "0010010"; s[2] = "1011101"; s[3] = "1011011";
    s[4] = "0111010"; s[5] = "1101011"; s[6] = "1101111"; s[7] = "1010010";
    s[8] = "1111111"; s[9] = "1111011";
    while (t--) {
        ll c; cin >> c;
        for (int i = 1; i <= 7; i++)cin >> p[i];
        for (int i = 0; i <= 9; i++)p1[i] = 1;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 7; j++) {
                if (s[i][j] == '1')p1[i] = p1[i] * p[j + 1]% mod * inv100 % mod;
                else p1[i] = p1[i] * (100 - p[j + 1])% mod * inv100 % mod;
            }
            // cout<<i<<" "<<p1[i]<<50*inv100%mod<<endl;
        }
        ll ans = 0;
        for (ll i = 0; i <= c; i++) {
            ll b = c - i;
            string a1 = addzero(i, 4); a1 += addzero(b, 4);
            ll num1 = 1;
            for (auto& ch : a1) {
                int m = ch - '0';
                num1 = (num1 * p1[m]) % mod;
            }
            ans = (ans + num1 % mod) % mod;
        }
        cout << ans << '\n';
    }
    return 0;
}