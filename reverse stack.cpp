//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
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
void insertAtBottom(stack<int>& myStack, int x) 
{
    solve(myStack, x);
    return;
}
    void Reverse(stack<int> &stack){
        if(stack.empty()){
            return;
        }
        int num = stack.top();
        stack.pop();
        Reverse(stack);
        insertAtBottom(stack, num);
        
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends
