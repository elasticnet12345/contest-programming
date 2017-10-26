#include <bits/stdc++.h>
using namespace std;

int rec(int i,int j)
{
  if(dp[i][j] >= 0){//既に調べたことがあるならばその結果を再利用
    return dp[i][j];
  }
  int res;
  if(i==n){//荷物をすべて調べ終えたら
    res = 0;
  }else if(j < w[i]){//i番目の荷物が許容量よりも大きい場合
    res = rec(i+1, j);//次の荷物へ
  }else{//許容量に収まる場合
    res = max(rec(i+1, j), rec(i+1, j-w[i])+v[i]);
  }
  //結果をテーブルに記録する
  return dp[i][j] = res;
}

void solve(){
  //まだ調べていないことを表す-1でメモ化テーブルを初期化
  memset(dp, -1, sizeof(dp));
  cout << rec(0,W) << endl;
  return 0;
}
    
    
