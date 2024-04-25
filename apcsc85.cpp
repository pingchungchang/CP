#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double

priority_queue<ll,vector<ll>,less<ll>> pq;
bool isempty(){
	if(pq.empty()){
		cout<<"QQ\n";
		return true;
	}
	return false;
}
int main(){
	io
	int q;
	cin>>q;
	while(q--){
		int t;
		cin>>t;
		if(t == 1){
			ll k;
			cin>>k;
			pq.push(k);
		}
		else if(t == 2){
			if(!isempty())pq.pop();
		}
		else if(t == 3){
			if(!isempty())cout<<pq.top()<<'\n';
		}
		else{
			cout<<pq.size()<<'\n';
		}
	}
}

