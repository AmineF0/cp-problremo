#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct segTreeRangeAssign {
    vector<int> t;
    vector<bool> marked;
    segTreeRangeAssign(int n) {
        t.assign(4*n, 0);
        marked.assign(4*n, false);
    }
    void push(int v) {
        if (marked[v]) {
            t[v*2] = t[v*2+1] = t[v];
            marked[v*2] = marked[v*2+1] = true;
            marked[v] = false;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int new_val) {
        if (l > r) 
            return;
        if (l == tl && tr == r) {
            t[v] = new_val;
            marked[v] = true;
        } else {
            push(v);
            int tm = (tl + tr) / 2;
            update(v*2, tl, tm, l, min(r, tm), new_val);
            update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
        }
    }

    int get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return t[v];
        }
        push(v);
        int tm = (tl + tr) / 2;
        if (pos <= tm) 
            return get(v*2, tl, tm, pos);
        else
            return get(v*2+1, tm+1, tr, pos);
    }
};

struct SegTree{
    vector<int> st;
    SegTree(int n) {
        st.assign(4*n, 0);   
    }

    SegTree(vi& a) {
        st.assign(4*a.size(), 0);
        build(a, 1, 0, a.size()-1);
    }

    void build(vi& a, int v, int tl, int tr) {
        if (tl == tr) {
            st[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            st[v] = st[v*2] + st[v*2+1];
        }
    }

    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return st[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))
            + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            st[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            st[v] = st[v*2] + st[v*2+1];
        }
    }
};

