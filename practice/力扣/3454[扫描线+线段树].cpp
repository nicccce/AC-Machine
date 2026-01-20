#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
    int l, r;
    int min_cover_len = 0;
    int min_cover = 0;
    int todo = 0;
};

vector<Node> seg;
vector<int> xs_global;

void maintain(int o) {
    Node& lo = seg[o * 2];
    Node& ro = seg[o * 2 + 1];
    int mn = min(lo.min_cover, ro.min_cover);
    seg[o].min_cover = mn;
    seg[o].min_cover_len = (lo.min_cover == mn ? lo.min_cover_len : 0) +
                           (ro.min_cover == mn ? ro.min_cover_len : 0);
}

void do_(int o, int v) {
    seg[o].min_cover += v;
    seg[o].todo += v;
}

void spread(int o) {
    int& v = seg[o].todo;
    if (v != 0) {
        do_(o * 2, v);
        do_(o * 2 + 1, v);
        v = 0;
    }
}

void build(int o, int l, int r) {
    seg[o].l = l;
    seg[o].r = r;
    if (l == r) {
        seg[o].min_cover_len = xs_global[l + 1] - xs_global[l];
        return;
    }
    int m = (l + r) / 2;
    build(o * 2, l, m);
    build(o * 2 + 1, m + 1, r);
    maintain(o);
}

void update(int o, int l, int r, int v) {
    if (l <= seg[o].l && seg[o].r <= r) {
        do_(o, v);
        return;
    }
    spread(o);
    int m = (seg[o].l + seg[o].r) / 2;
    if (l <= m) {
        update(o * 2, l, r, v);
    }
    if (m < r) {
        update(o * 2 + 1, l, r, v);
    }
    maintain(o);
}

void init_segment_tree(vector<int>& xs) {
    xs_global = xs;
    unsigned n = xs.size() - 1;
    if (n == 0) {
        seg.assign(4, Node{});
        return;
    }
    seg.assign(4 * n, Node{});
    build(1, 0, n - 1);
}

void update_range(int l, int r, int v) {
    update(1, l, r, v);
}

int get_uncovered_length() {
    return seg[1].min_cover ? 0 : seg[1].min_cover_len;
}

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<int> xs;
        struct Event { int y, lx, rx, delta; };
        vector<Event> events;
        for (auto& sq : squares) {
            int lx = sq[0], y = sq[1], l = sq[2];
            int rx = lx + l;
            xs.push_back(lx);
            xs.push_back(rx);
            events.emplace_back(y, lx, rx, 1);
            events.emplace_back(y + l, lx, rx, -1);
        }

        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());

        init_segment_tree(xs);

        sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
            return a.y < b.y;
        });
        vector<pair<long long, int>> records;
        long long tot_area = 0;
        for (int i = 0; i + 1 < events.size(); i++) {
            auto& event = events[i];
            int y = event.y, lx = event.lx, rx = event.rx, delta = event.delta;
            int l = lower_bound(xs.begin(), xs.end(), lx) - xs.begin();
            int r = lower_bound(xs.begin(), xs.end(), rx) - xs.begin() - 1;
            update_range(l, r, delta);
            int sum_len = xs.back() - xs[0] - get_uncovered_length();
            records.push_back({tot_area, sum_len});
            tot_area += 1LL * sum_len * (events[i + 1].y - y);
        }

        if (records.empty()) {
            return 0.0;
        }
        
        int i = -1;
        int left = 0, right = records.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (records[mid].first * 2 < tot_area) {
                i = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (i == -1) {
            return events[0].y;
        }
        auto [area, sum_len] = records[i];
        return events[i].y + (tot_area - area * 2) / (sum_len * 2.0);
    }
};
