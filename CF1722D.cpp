#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()
void solve(){
	priority_queue<pll,vector<pll>,less<pll>> pq;
	ll n;
	cin>>n;
	ll total = 0;
	string s;
	cin>>s;
	for(int i = 0;i<n;i++){
		if(s[i] == 'L'&&i<(n-i-1)){
			pq.push({n-i-1-i,i});
		}
		else if(s[i] == 'R'&&i>(n-i-1)){
			pq.push({i-(n-1-i),i});
		}
		if(s[i] == 'L')total += i;
		else total+= (n-1-i);
	}
	for(int i = 0;i<n;i++){
		if(!pq.empty()){
			total += pq.top().fs;
			pq.pop();
		}
		cout<<total<<' ';
	}
	cout<<'\n';
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

