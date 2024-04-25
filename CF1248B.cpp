#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	deque<int> dq;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		dq.push_back(k);
	}
	sort(dq.begin(),dq.end());
	ll len[2] = {0,0};
	bool roll = 0;
	while(!dq.empty()){
		if(!roll)len[roll] += dq.back(),dq.pop_back();
		else len[roll] += dq.front(),dq.pop_front();
		roll ^= 1;
	}
	cout<<len[0]*len[0]+len[1]*len[1];
}
