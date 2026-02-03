#include<bits/stdc++.h>
using namespace std;
#define int long long
int N;
vector<vector<int>> adj;
vector<pair<int, int>> edges;
vector<int> match_with;
vector<bool> in_matching;
vector<int> component;
vector<vector<int>> comp_adj;
vector<int> comp_color;
void get_max_matching(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        get_max_matching(v, u);
        if (!in_matching[u] && !in_matching[v]) {
            in_matching[u] = true;
            in_matching[v] = true;
            match_with[u] = v;
            match_with[v] = u;
        }
    }
}
void prepare() {
    if (!(cin >> N)) return;
    
    adj.assign(N + 1, vector<int>());
    edges.clear();
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    in_matching.assign(N + 1, false);
    match_with.assign(N + 1, 0);
    get_max_matching(1, 0);

    component.assign(N + 1, 0);
    int comp_count = 0;
    for (int i = 1; i <= N; ++i) {
        if (component[i] == 0) {
            comp_count++;
            component[i] = comp_count;
            if (in_matching[i]) {
                component[match_with[i]] = comp_count;
            }
        }
    }

    comp_adj.assign(comp_count + 1, vector<int>());
    for (auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        int cu = component[u];
        int cv = component[v];
        if (cu != cv) {
            comp_adj[cu].push_back(cv);
            comp_adj[cv].push_back(cu);
        }
    }

    comp_color.assign(comp_count + 1, -1);
    for (int i = 1; i <= comp_count; ++i) {
        if (comp_color[i] == -1) {
            // BFS染色
            vector<int> q;
            q.push_back(i);
            comp_color[i] = 0;
            size_t head = 0;
            while(head < q.size()){
                int u = q[head++];
                for(int v : comp_adj[u]){
                    if(comp_color[v] == -1){
                        comp_color[v] = 1 - comp_color[u];
                        q.push_back(v);
                    }
                }
            }
        }
    }

    vector<int> label(N + 1);
    for (int i = 1; i <= N; ++i) {
        label[i] = comp_color[component[i]];
    }

    if (label[1] == 1) {
        for (int i = 1; i <= N; ++i) label[i] = 1 - label[i];
    }

    string s = "";
    for (int i = 2; i <= N; ++i) {
        s += to_string(label[i]);
    }
    cout << s << endl;
}

void play() {
    if (!(cin >> N)) return;
    string s;
    cin >> s;

    vector<int> label(N + 1);
    label[1] = 0;
    for (int i = 0; i < N - 1; ++i) {
        label[i + 2] = s[i] - '0';
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        if (label[u] == label[v]) {
            cout << "take" << endl;
        } else {
            cout << "ignore" << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string mode;
    if (cin >> mode) {
        if (mode == "prepare") {
            prepare();
        } else {
            play();
        }
    }
    return 0;
}