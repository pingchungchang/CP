#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 2e6+10;
pii arr[mxn];
int rt = 0;
int n,m;
vector<int> ans;


void solve(){
	ans.clear();
	for(int i = 0;i<=n+1;i++)arr[i] = {0,0};
	cin>>n>>m>>rt;
	ll rest = 0;
	while(m--){
		int t,a,b,c;
		cin>>t>>a>>b>>c;
		if(t == 1){
			if(c == 1){
				int pre = arr[b].fs;
				arr[b].fs = a;
				arr[a].sc = b;
				arr[a].fs = pre;
				arr[pre].sc = a;
			}
			else{
				int nxt = arr[b].sc;
				arr[b].sc = a;
				arr[a].fs = b;
				arr[a].sc = nxt;
				arr[nxt].fs = a;
			}
		}
		else if(t == 2){
			int pre = arr[a].fs,nxt = arr[b].sc;
			arr[pre].sc = nxt;
			arr[nxt].fs = pre;
			pre = arr[c].fs;
			arr[pre].sc = a;
			arr[a].fs = pre;
			arr[c].fs = b;
			arr[b].sc = c;
		}
		else if(t == 3){
			if(c == 1){
				int now = a;
				while(b&&now){
					b--;
					ans.push_back(now);
					int pre = arr[now].fs,nxt = arr[now].sc;
					arr[pre].sc = nxt;
					arr[nxt].fs = pre;
					now = pre;
				}
				rest += b;
			}
			else if(c == 2){
				int now = a;
				while(b&&now){
					b--;
					ans.push_back(now);
					int pre = arr[now].fs,nxt = arr[now].sc;
					arr[pre].sc = nxt;
					arr[nxt].fs = pre;
					now = nxt;
				}
				rest += b;
			}
		}
	}
	cout<<rest<<'\n';
	for(auto &i:ans)cout<<i<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
