#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

priority_queue<int,vector<int>,less<int>> lpq,rpq;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;
	cin>>q;
	lpq.push(-1);rpq.push(-1e9);
	while(q--){
		int t;
		cin>>t;
		if(t == 2){
			cout<<lpq.top()<<'\n';
		}
		else{
			int k;
			cin>>k;
			if(lpq.top()>k)lpq.push(k);
			else rpq.push(-k);
			while(lpq.size()>rpq.size()){
				rpq.push(-lpq.top());
				lpq.pop();
			}
			while(rpq.size()>lpq.size()){
				lpq.push(-rpq.top());
				rpq.pop();
			}
		}
	}
	return 0;
}
