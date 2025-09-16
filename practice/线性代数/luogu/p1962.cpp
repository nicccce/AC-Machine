//https://www.luogu.com.cn/problem/P1962
// 题目：斐波那契数列 - 矩阵快速幂解法
// 用矩阵快速幂计算斐波那契数列第n项，时间复杂度O(log n)
#include<bits/stdc++.h>
using namespace std;
#define int long long  // 将int定义为long long，避免斐波那契数溢出
#define pb push_back
// N: 未使用常量, dem: 矩阵维度(2x2), mod: 取模用的质数
const int N=1e9+9,dem=2,mod=1e9+7;
struct matrix{int m[dem][dem];};  // 定义2x2矩阵结构体

// 矩阵乘法运算符重载
matrix operator * (const matrix& a,const matrix& b){
    matrix c;
    memset (c.m, 0, sizeof(c.m));  // 初始化结果矩阵为0
    // 标准矩阵乘法实现
    for(int i=0;i<dem;i++)
        for(int j=0;j<dem;j++)
            for(int k=0;k<dem;k++)
                c.m[i][j]=(c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;  // 每次乘法后取模防止溢出
    return c;
}

// 矩阵快速幂算法，计算矩阵a的n次幂
matrix pow_matrix(matrix a, int n){
    matrix ans;
    memset(ans.m,0,sizeof(ans.m));  // 初始化单位矩阵
    for(int i=0;i<dem;i++)ans.m[i][i]=1;  // 单位矩阵主对角线为1
    // 快速幂核心算法
    while(n){
        if(n&1)ans = ans*a;  // 如果n的二进制最低位为1，则累乘当前矩阵
        a=a*a;  // 矩阵平方
        n>>=1;  // n右移一位，相当于n/=2
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    auto solve = [&]() {
        int n;cin>>n;
        // 斐波那契数列前两项都是1
        if(n==1||n==2){
            cout<<1;return;
        }
        // 构造斐波那契递推关系的转移矩阵
        // [F(n+1)]   [1 1] [F(n)  ]
        // [F(n)  ] = [1 0] [F(n-1)]
        matrix b = {
            1,1,
            1,0
        };
        // 计算转移矩阵的(n-2)次幂
        matrix c = pow_matrix(b,n-2);
        // F(n) = F(2)*c.m[0][0] + F(1)*c.m[0][1] = 1*c.m[0][0] + 1*c.m[0][1]
        cout<<(c.m[0][0]+c.m[0][1])%mod;
    };

    // int t;
    // for(cin >> t; t--; )
    solve();
    return 0;
}