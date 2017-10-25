//愚直な方法
#include <bits/stdc++.h>
using namespace std;

//入力
static const int MAX_N = 100;
int n,W;
int w[MAX_N],v[MAX_N];

//i番目以降の品物から重さの総和がj以下となるように選ぶ
//i番目の品物の重さをw[i],価値をv[i]
//現在のリュックの許容負荷がj

int rec(int i,int j){
  int res;
  if(i==n){//もう品物は残っていない
    res = 0;
  }else if(j < w[i]){//この品物は入らない
    res = rec(i+1, j);
  }else{//入れない場合と入れる場合を両方試す
    res = max(rec(i+1,j), rec(i+1,j-w[i])+v[i]);
  }
  return res;
}
    

int main()
{
  //入力
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> w[i] >> v[i];
  }
  cin >> W;
  printf("%d\n",rec(0,W));
  return 0;
}
  
