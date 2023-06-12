#include <bits/stdc++.h> 
void solve(stack<int>&s, int N, int count){
   if( count == N/2){
      s.pop();
      return;
   }
   int num= s.top();
   s.pop();
   solve(s,N, count+1);
   s.push(num);
}
void deleteMiddle(stack<int>&s, int N){
   int count  = 0;
   solve(s, N, count);
}
