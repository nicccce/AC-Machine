// https://ac.nowcoder.com/acm/problem/253619
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	auto solve=[&](){
		int n;
		string s;
		cin>>s;
        int l=0,r=0;
        for(auto c:s){
            if(c=='(')l++;
            else{
                if(l>0)l--;
                else r++;
            }
        }
        if(l!=r)cout<<-1<<endl;
        elsecout<<r<<endl;
		
	};
    int t;
    for(cin>>t;t;t--)
    solve();
}