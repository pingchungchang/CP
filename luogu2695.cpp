#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	int arr[n];
	for(auto &i:arr)cin>>i;
	sort(arr,arr+n);
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		pq.push(k);
	}
	ll ans = 0;
	for(int i = 0;i<n;i++){
		while(!pq.empty()&&pq.top()<arr[i])pq.pop();
		if(pq.empty()){
			cout<<"you died!\n";
			return 0;
		}
		ans += pq.top();
		pq.pop();
	}
	cout<<ans;
}
