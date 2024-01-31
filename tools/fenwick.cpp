#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

// range update point query
//1-indexed
struct FenwickTree2 {
  vector<int> bit;
  int n;

  FenwickTree2(int n) {
    this->n = n + 1;
    bit.assign(n + 1, 0);
  }

  FenwickTree2(vector<int> a)
    : FenwickTree2(a.size()) {
      for (size_t i = 0; i < a.size(); i++)
      add(i, a[i]);
  }


  void add(int idx, int val) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += val;
  }

  void range_add(int l, int r, int val) {
    add(l, val);
    add(r + 1, -val);
  }

  int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
  }
};