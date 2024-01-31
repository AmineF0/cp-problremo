#include <bits/stdc++.h>

using namespace std;


struct SqrtDecomposition{
  // input data
  int n, len;
  vector<int> a, b;
  SqrtDecomposition(vector<int>& a) : a(a) {
      n = (int) a.size();

      // preprocessing
      len = (int) sqrt (n + .0) + 1; // size of the block and the number of blocks
      b.resize (len);
      for (int i=0; i<n; ++i)
          b[i / len] += a[i];
  }


  void query(int l, int r) {
      int sum = 0;
      for (int i=l; i<=r; )
          if (i % len == 0 && i + len - 1 <= r) {
              // if the whole block starting at i belongs to [l, r]
              sum += b[i / len];
              i += len;
          }
          else {
              sum += a[i];
              ++i;
          }
  }
};


// Mo's algorithm


void remove(int idx);  // TODO: remove value at idx from data structure
void add(int idx);     // TODO: add value at idx from data structure
int get_answer();  // TODO: extract the current answer of the data structure

// give it a const value
int block_size;

struct Query {
    int l, r, idx;
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

vector<int> mo_s_algorithm(vector<Query> queries) {
    vector<int> answers(queries.size());
    sort(queries.begin(), queries.end());

    // TODO: initialize data structure

    int cur_l = 0;
    int cur_r = -1;
    // invariant: data structure will always reflect the range [cur_l, cur_r]
    for (Query q : queries) {
        while (cur_l > q.l) {
            cur_l--;
            add(cur_l);
        }
        while (cur_r < q.r) {
            cur_r++;
            add(cur_r);
        }
        while (cur_l < q.l) {
            remove(cur_l);
            cur_l++;
        }
        while (cur_r > q.r) {
            remove(cur_r);
            cur_r--;
        }
        answers[q.idx] = get_answer();
    }
    return answers;
}