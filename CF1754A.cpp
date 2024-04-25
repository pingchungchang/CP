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
	int n;
	cin>>n;
	string s;
	cin>>s;
	int q = 0,a = 0;
	stack<int> q1;
	for(auto &i:s){
		if(i == 'Q')q1.push(1);
		else{
			if(!q1.empty()){
				q1.pop();
			}
		}
	}
	if(!q1.empty())cout<<"NO\n";
	else cout<<"Yes\n";
	return;
}
int main(){
	io
	int t;
	cin>>t;
	while(t--)solve();
}
//2 5 3 1 3
