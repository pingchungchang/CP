#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
int main(){
	ll s,n;
	cin>>s>>n;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	for(ll i = 0;i<n;i++){
		pll tmp;
		cin>>tmp.fs>>tmp.sc;
		pq.push(tmp);
	}
	while(!pq.empty()){
		pll now = pq.top();
		pq.pop();
		if(now.fs>=s){
			cout<<"NO";
			return 0;
		}
		s += now.sc;
	}
	cout<<"YES";
	return 0;
}

