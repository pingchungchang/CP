#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

void solve(){
	int n;
	cin>>n;
	int arr[n];
	set<int> st;
	priority_queue<int,vector<int>,greater<int>> pq;
	for(int i = 1;i<=n;i++)st.insert(i);
	for(int i = 0;i<n;i++){
		cin>>arr[i];
		if(st.find(arr[i]) != st.end())st.erase(arr[i]);
		else{
			pq.push((arr[i]+1)/2-1);
		}
	}
	bool flag = false;
	for(auto it:st){
		if(it>pq.top()){
			flag = true;
			break;
		}
		pq.pop();
	}
	if(flag)cout<<"-1\n";
	else{
		cout<<st.size()<<'\n';
	}
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

