#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second


void solve(){
	int qq,d;
	cin>>qq>>d;
	bitset<101> vis;
	vis.reset();
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(int i = 0;i<10;i++){
			int nxt = now+i*10+d;
			if(nxt>=100||vis[nxt])continue;
			else{
				vis[nxt] = true;
				q.push(nxt);
			}
		}
		for(int i = 0;i<10;i++){
			int nxt = now+i+d*10;
			if(nxt>=100||vis[nxt])continue;
			else{
				vis[nxt] = true;
				q.push(nxt);
			}
		}
	}
	while(qq--){
		int k;
		cin>>k;
		if(k>=100)cout<<"YES\n";
		else cout<<(vis[k]?"YES\n":"NO\n");
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
