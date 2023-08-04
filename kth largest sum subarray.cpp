#include<algorithm>
int getKthLargest(vector<int> &arr, int k)
{
	//	Write your code here.
    // priority_queue <int, vector<int>, greater<int>> q;
	// int n = arr.size();

	// for(int i =0;i<n;i++){
	// 	int sum = 0;
	// 	for(int j = i;j<n;j++){
	// 		sum+=arr[i];
	// 	}
	// 	q.push(sum);
	// }
	// while(k){
	// 	q.pop();
	// }
	// int ans = q.top();
	// return ans;
	vector<int> q;
	int n = arr.size();

	for(int i =0;i<n;i++){
		int sum = 0;
		for(int j = i;j<n;j++){
			sum+=arr[j];
			q.push_back(sum);
		}
		
	}
	sort(q.begin(),q.end());

	
	return q[q.size()-k];





	
}
