#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
const int N=1e5,mod=998244353;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);

    auto solve = [&]() {
        int n;
        cin>>n;
        vector<vector<char>> matr(7,vector<char>(n,'.'));
        int p2=-1,p4=-1;
        for(int i=0;i<n;i++){
            cin>>matr[0][i];
        }for(int i=0;i<n;i++){
            if(matr[0][i]=='.')matr[1][i]='#';
            else if((i!=0&&matr[0][i-1]=='.')||(i!=n-1&&matr[0][i+1]=='.')) p2=i;
        }
        for(int i=0;i<n;i++){
            cin>>matr[6][i];
        }
        for(int i=0;i<n;i++){
            if(matr[6][i]=='.')matr[5][i]='#';
            else if((i!=0&&matr[6][i-1]=='.')||(i!=n-1&&matr[6][i+1]=='.')) p4=i;
        }
        if(p2==-1&&p4==-1){
            cout<<"Yes\n";
            for(int i=0;i<7;i++){
            for(int j=0;j<n;j++){
                cout<<'#';
            }cout<<'\n';
        }
            return;
        }
        if(p2==-1||p4==-1){
            cout<<"No\n";
            return;
        }cout<<"Yes\n";
        matr[2][p2]=matr[4][p4]='#';
        if(abs(p2-p4)<=1)matr[3][p2]='#';
        else for(int i=min(p2,p4)+1;i<=max(p2,p4)-1;i++){
            matr[3][i]='#';
        }
        for(int i=0;i<7;i++){
            for(int j=0;j<n;j++){
                cout<<matr[i][j];
            }cout<<'\n';
        }
    };

    int t;
    for(cin >> t; t--; )
    solve();
    return 0;
}
/*
3
4
#..#
.##.
5
##.#.
.#.##
6
######
.####.
*/