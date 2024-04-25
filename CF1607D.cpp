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
	vector<int> v(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	string s;
	cin>>s;
	priority_queue<int,vector<int>,greater<int>> r;
	priority_queue<int,vector<int>,greater<int>> b;
	for(int i = 0;i<n;i++){
		if(s[i] == 'B')b.push(v[i]);
		else r.push(v[i]);
	}
	for(int i = 1;i<=n;i++){
		if(!b.empty()&&b.top()>=i)b.pop();
		else{
			if(!b.empty()){
				cout<<"NO\n";
				return;
			}
			if(r.top()<=i)r.pop();
			else{
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
	return;
	
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}

