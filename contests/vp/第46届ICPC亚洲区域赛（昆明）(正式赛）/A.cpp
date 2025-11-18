// https://ac.nowcoder.com/acm/contest/32708/A

#include <bits/stdc++.h>
using namespace std;

int mass[10] = {89, 133, 132, 121, 75, 105, 149, 119, 146, 147};
int height[10] = {7, 7, 9, 7, 5, 7, 13, 9, 11, 9};
map<string, int> mp;
string str[15][15];

int tranId(string x){
    if(x == "Ala") return 0;
    if(x == "Asp") return 1;
    if(x == "Asn") return 2;
    if(x == "Cys") return 3;
    if(x == "Gly") return 4;
    if(x == "Ser") return 5;
    if(x == "Met") return 6;
    if(x == "Thr") return 7;
    if(x == "Gln") return 8;
    if(x == "Glu") return 9;
    return 666;
}

void init() {
    str[0][0] = "  H H O    ";
    str[0][1] = "  | | ||   ";
    str[0][2] = "H-N-C-C-O-H";
    str[0][3] = "    |      ";
    str[0][4] = "  H-C-H    ";
    str[0][5] = "    |      ";
    str[0][6] = "    H      ";
    str[0][7] = "           ";
    str[0][8] = "           ";
    str[0][9] = "           ";
    str[0][10] = "           ";
    str[0][11] = "           ";
    str[0][12] = "           ";

    str[1][0] = "  H H O    ";
    str[1][1] = "  | | ||   ";
    str[1][2] = "H-N-C-C-O-H";
    str[1][3] = "    |      ";
    str[1][4] = "  H-C-H    ";
    str[1][5] = "    |      ";
    str[1][6] = "  O=C-O-H  ";
    str[1][7] = "           ";
    str[1][8] = "           ";
    str[1][9] = "           ";
    str[1][10] = "           ";
    str[1][11] = "           ";
    str[1][12] = "           ";

    str[2][0] = "  H H O    ";
    str[2][1] = "  | | ||   ";
    str[2][2] = "H-N-C-C-O-H";
    str[2][3] = "    |      ";
    str[2][4] = "  H-C-H    ";
    str[2][5] = "    |      ";
    str[2][6] = "  O=C-N-H  ";
    str[2][7] = "      |    ";
    str[2][8] = "      H    ";
    str[2][9] = "           ";
    str[2][10] = "           ";
    str[2][11] = "           ";
    str[2][12] = "           ";

    str[3][0] = "  H H O    ";
    str[3][1] = "  | | ||   ";
    str[3][2] = "H-N-C-C-O-H";
    str[3][3] = "    |      ";
    str[3][4] = "  H-C-S-H  ";
    str[3][5] = "    |      ";
    str[3][6] = "    H      ";
    str[3][7] = "           ";
    str[3][8] = "           ";
    str[3][9] = "           ";
    str[3][10] = "           ";
    str[3][11] = "           ";
    str[3][12] = "           ";

    str[4][0] = "  H H O    ";
    str[4][1] = "  | | ||   ";
    str[4][2] = "H-N-C-C-O-H";
    str[4][3] = "    |      ";
    str[4][4] = "    H      ";
    str[4][5] = "           ";
    str[4][6] = "           ";
    str[4][7] = "           ";
    str[4][8] = "           ";
    str[4][9] = "           ";
    str[4][10] = "           ";
    str[4][11] = "           ";
    str[4][12] = "           ";

    str[5][0] = "  H H O    ";
    str[5][1] = "  | | ||   ";
    str[5][2] = "H-N-C-C-O-H";
    str[5][3] = "    |      ";
    str[5][4] = "  H-C-O-H  ";
    str[5][5] = "    |      ";
    str[5][6] = "    H      ";
    str[5][7] = "           ";
    str[5][8] = "           ";
    str[5][9] = "           ";
    str[5][10] = "           ";
    str[5][11] = "           ";
    str[5][12] = "           ";

    str[6][0] = "  H H O    ";
    str[6][1] = "  | | ||   ";
    str[6][2] = "H-N-C-C-O-H";
    str[6][3] = "    |      ";
    str[6][4] = "  H-C-H    ";
    str[6][5] = "    |      ";
    str[6][6] = "  H-C-H    ";
    str[6][7] = "    |      ";
    str[6][8] = "    S      ";
    str[6][9] = "    |      ";
    str[6][10] = "  H-C-H    ";
    str[6][11] = "    |      ";
    str[6][12] = "    H      ";

    str[7][0] = "  H H O    ";
    str[7][1] = "  | | ||   ";
    str[7][2] = "H-N-C-C-O-H";
    str[7][3] = "    |      ";
    str[7][4] = "  H-C-O-H  ";
    str[7][5] = "    |      ";
    str[7][6] = "  H-C-H    ";
    str[7][7] = "    |      ";
    str[7][8] = "    H      ";
    str[7][9] = "           ";
    str[7][10] = "           ";
    str[7][11] = "           ";
    str[7][12] = "           ";

    str[8][0] = "  H H O    ";
    str[8][1] = "  | | ||   ";
    str[8][2] = "H-N-C-C-O-H";
    str[8][3] = "    |      ";
    str[8][4] = "  H-C-H    ";
    str[8][5] = "    |      ";
    str[8][6] = "  H-C-H    ";
    str[8][7] = "    |      ";
    str[8][8] = "  O=C-N-H  ";
    str[8][9] = "      |    ";
    str[8][10] = "      H    ";
    str[8][11] = "           ";
    str[8][12] = "           ";

    str[9][0] = "  H H O    ";
    str[9][1] = "  | | ||   ";
    str[9][2] = "H-N-C-C-O-H";
    str[9][3] = "    |      ";
    str[9][4] = "  H-C-H    ";
    str[9][5] = "    |      ";
    str[9][6] = "  H-C-H    ";
    str[9][7] = "    |      ";
    str[9][8] = "  O=C-O-H  ";
    str[9][9] = "           ";
    str[9][10] = "           ";
    str[9][11] = "           ";
    str[9][12] = "           ";
};

/*
Ala:           Asp:           Asn:           Cys:           Gly:                              
  H H O          H H O          H H O          H H O          H H O    
  | | ||         | | ||         | | ||         | | ||         | | ||   
H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H
    |              |              |              |              |      
  H-C-H          H-C-H          H-C-H          H-C-S-H          H      
    |              |              |              |                     
    H            O=C-O-H        O=C-N-H          H                     
                                    |                                  
                                    H                                                         
                                                                                              
Ser:           Met:           Thr:           Gln:           Glu:       
  H H O          H H O          H H O          H H O          H H O    
  | | ||         | | ||         | | ||         | | ||         | | ||   
H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H    H-N-C-C-O-H
    |              |              |              |              |                            
  H-C-O-H        H-C-H          H-C-O-H        H-C-H          H-C-H                          
    |              |              |              |              |                            
    H            H-C-H          H-C-H          H-C-H          H-C-H                          
                   |              |              |              |                            
                   S              H            O=C-N-H        O=C-O-H                        
                   |                               |                                         
                 H-C-H                             H                                         
                   |                                                                         
                   H                                                                                                                                
*/

void prt(vector<string> &vec){
    int mxH = 0;
    for(auto x: vec)
        mxH = max(mxH, height[tranId(x)]);
    
    for(int row=0; row<mxH; row++){
        for(int col=0; col<(int)vec.size(); col++){
            int nowid = tranId(vec[col]);
            if(col == 0) {
                if(row != 2)
                    for(int j = 0; j <= 9; j++) cout << str[nowid][row][j];
                else {
                    for(int j = 0; j <= 6; j++) cout << str[nowid][row][j];
                    cout << "---";
                }
            } else {
                if(col == int(vec.size()) - 1)
                    for(int j = 2; j <= 10; j++) cout << str[nowid][row][j];
                else if(row != 2)
                    for(int j = 2; j <= 9; j++) cout << str[nowid][row][j];
                else {
                    for(int j = 2; j <= 6; j++) cout << str[nowid][row][j];
                    cout << "---";
                }
            }
        }
        cout << "\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    init();

    auto solve = [&](){
        int n, m;
        cin >> n >> m;
        vector<string> aval(n+1);
        for(int i=0; i<n; i++)
            cin >> aval[i];

        sort(aval.begin(), aval.begin()+n);
        
        int now_M, id;
        vector<vector<string>> ans;
        vector<string> tmp;
        function<void(string)> dfs = [&](string now){
            // cout << now << " ";
            now_M = now_M + mass[tranId(now)] - 18;
            // cout << now_M << "\n";
            if(now_M > m){
                now_M = now_M - mass[tranId(now)] + 18;
                // cout << "haha\n";
                return;
            }
                
            
            tmp.push_back(now);
            
            if(tmp.size() > 1)
                ans.push_back(tmp);

            for(int i=0; i<n; i++)
                dfs(aval[i]);

            tmp.pop_back();
            now_M = now_M - mass[tranId(now)] + 18;
        };

        for(int i=0; i<n; i++){
            now_M = 18;
            dfs(aval[i]);
        }

        // for(int i=0; i<ans.size(); i++){
        //     for(auto x: ans[i])
        //         cout << x << " ";
        //     cout << "\n";
        // }

        cout << ans.size() << "\n";
        for(int i=0; i<(int)ans.size(); i++){
            prt(ans[i]);
            cout << "\n";
        }
    };

    solve();

    return 0;
}