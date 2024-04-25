#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int n;
	cin>>n;
	deque<ll> dq;
	for(int i = 0;i<n;i++){
		ll tmp;
		cin>>tmp;
		dq.push_back(tmp);
	}
	pll ans = {0,0};
	int turn = 0;
	pll pre ={0,0};
	while(!dq.empty()){
		turn++;
		if(turn&1){
			ll tmp = 0;
			while(!dq.empty()&&tmp<=pre.sc){
				tmp += dq.front();
				dq.pop_front();
			}
			ans.fs += tmp;
			pre.fs = tmp;
		}
		else{
			ll tmp = 0;
			while(!dq.empty()&&tmp<=pre.fs){
				tmp += dq.back();
				dq.pop_back();
			}
			ans.sc += tmp;
			pre.sc = tmp;
		}
	}
	cout<<turn<<' '<<ans.fs<<' '<<ans.sc<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
