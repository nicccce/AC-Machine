#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 1000005;
const int MAXM = 2000005;
const long long INF = 1LL << 60;

struct Edge {
    int to, next;
    long long w;
};

int n, m, k, ecnt;
Edge e[MAXM];
int hd[MAXN];
long long d[MAXN];

struct Node {
    int v;
    long long d;
    bool operator<(const Node& o) const { return d < o.d; }
};

Node heap[MAXN];
int heap_size;
int heap_pos[MAXN];

void heap_swap(int i, int j) {
    swap(heap[i], heap[j]);
    heap_pos[heap[i].v] = i;
    heap_pos[heap[j].v] = j;
}

void heap_up(int i) {
    while (i > 1 && heap[i] < heap[i/2]) {
        heap_swap(i, i/2);
        i /= 2;
    }
}

void heap_down(int i) {
    while (true) {
        int l = i*2, r = i*2+1;
        int min = i;
        if (l <= heap_size && heap[l] < heap[min]) min = l;
        if (r <= heap_size && heap[r] < heap[min]) min = r;
        if (min != i) {
            heap_swap(i, min);
            i = min;
        } else break;
    }
}

void heap_push(Node x) {
    heap[++heap_size] = x;
    heap_pos[x.v] = heap_size;
    heap_up(heap_size);
}

Node heap_pop() {
    Node res = heap[1];
    heap_swap(1, heap_size--);
    heap_down(1);
    heap_pos[res.v] = 0;
    return res;
}

void heap_update(int v, long long new_d) {
    int pos = heap_pos[v];
    if (pos == 0) {
        heap_push(Node{v, new_d});
        return;
    }
    if (new_d < heap[pos].d) {
        heap[pos].d = new_d;
        heap_up(pos);
    }
}

void add(int u, int v, long long w) {
    e[ecnt] = {v, hd[u], w};
    hd[u] = ecnt++;
    e[ecnt] = {u, hd[v], w};
    hd[v] = ecnt++;
}

long long dij(int s, int t) {
    if (s == t) return 0;
    
    heap_size = 0;
    memset(heap_pos, 0, sizeof(heap_pos));
    
    d[s] = 0;
    heap_push(Node{s, 0});
    
    while (heap_size) {
        Node cur = heap_pop();
        int u = cur.v;
        if (cur.d != d[u]) continue;
        if (u == t) {
            long long ans = d[t];
            for (int i = 1; i <= n; i++) d[i] = INF;
            return ans;
        }
        for (int i = hd[u]; i != -1; i = e[i].next) {
            int v = e[i].to;
            long long w = e[i].w;
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                heap_update(v, d[v]);
            }
        }
    }
    
    long long ans = d[t];
    for (int i = 1; i <= n; i++) d[i] = INF;
    return ans;
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    
    memset(hd, -1, sizeof(hd));
    for (int i = 1; i <= n; i++) d[i] = INF;
    ecnt = 0;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        long long w;
        scanf("%d %d %lld", &u, &v, &w);
        add(u, v, w);
    }
    
    for (int i = 0; i < k; ++i) {
        int s, t;
        scanf("%d %d", &s, &t);
        printf("%lld\n", dij(s, t));
    }
    
    return 0;
}