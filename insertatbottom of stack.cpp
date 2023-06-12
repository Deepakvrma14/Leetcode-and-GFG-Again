#include <bits/stdc++.h> 
void solve(stack<int>& stack, int x){
    if(stack.empty()){
        stack.push(x);
        return;
    }
    int num = stack.top();
    stack.pop();
    solve(stack, x);
    stack.push(num);
    return;
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return myStack;
}
