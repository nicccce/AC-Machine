// https://leetcode.cn/problems/trionic-array-ii/?envType=daily-question&envId=2026-02-04
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class Solution {
public:
    long long maxSumTrionic(vector<int>& numsi) {
        vector<ll> nums(numsi.size());
        for(int i=0;i<numsi.size();i++){
            nums[i]=numsi[i];
        }
        int n=nums.size();
        vector<ll> prefix(n), suffix(n);
        prefix[0]=nums[0];
        ll inf=LONG_LONG_MAX-0x003f3f3f3f3f3f3f;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                if(prefix[i-1]==-inf)
                    prefix[i]=nums[i]+nums[i-1];
                else
                prefix[i]=max(prefix[i-1]+nums[i],(ll)nums[i]+nums[i-1]);
            }else{
                prefix[i]=-inf;
            }
            // cout<<prefix[i]<<" ";
        }
        // cout<<endl;
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                if(suffix[i+1]==-inf)
                    suffix[i]=nums[i]+nums[i+1];
                else
                    suffix[i]=max(suffix[i+1]+nums[i],(ll)nums[i]+nums[i+1]);
            }else{
                suffix[i]=-inf;
            }
            // cout<<suffix[i]<<" ";
        }
        // cout<<endl;
        ll ans=LONG_LONG_MIN,sum=-inf;
        for(int i=1;i<n-1;i++){
            // cout<<prefix[i]<<" "<<suffix[i]<<"\n";
            if(nums[i]<nums[i-1]){  
                ans=max(ans,sum+suffix[i]);
                sum=max(sum+nums[i],prefix[i]);
            }else{                                                                                                                                                                                                                                          
                sum=prefix[i];
            }
            // cout<<sum<<" ";
        }
        return ans;
    }
};


ll qpow(ll b, ll p, ll mod)
{
    ll r = 1;
    while (p)
    {
        if (p & 1)
            r = r * b % mod;
        b = b * b % mod, p >>= 1;
    }
    return r;
}
int ex_gcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        int d = ex_gcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int solve_linear_congruence_equation(int a, int b, int n)
{
    int x, y;
    int d = ex_gcd(a, n, x, y);
    if (b % d)
        return -1;
    n /= d;
    return ((long long)x * (b / d) % n + n) % n;
}
