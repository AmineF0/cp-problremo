int count_paths(int a, int b, int c){
  if(a==0 && b==0 && c==0) return 1;
  int cnt = 0;
  if(a>0) cnt += count_paths(a-1, b, c);
  if(b>0) cnt += count_paths(a, b-1, c);
  if(c>0) cnt += count_paths(a, b, c-1);
  return cnt;
}

void solve(){
  long long a, b, c, n;
  cin >> a >> b >> c >> n;
  vector<long long> v = {a, b, c};
  vector<vector<long long>> dp(3, vector<long long>(3, 0));
  for(int i=0; i<n; i++){
    ans *= dp;
  }

  cout << (a+b+c)%MOD << endl;
}