#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

string s,l,r;
int n;
vector<int> pos[10];

void solve(){
	cin>>s>>n>>l>>r;
	int pre = -1;
	for(int i = 0;i<s.size();i++)pos[s[i]-'0'].push_back(i);
	int pt[10] = {};
	bool flag = false;
	for(int i = 0;i<n;i++){
		int nxt = pre;
		for(int j = l[i]-'0';j<=r[i]-'0';j++){
			auto it = upper_bound(pos[j].begin(),pos[j].end(),pre);
			if(it == pos[j].end()){
				flag =true;
				break;
			}
			nxt = max(nxt,*it);
		}
		pre = nxt;
	}
	if(flag)cout<<"YES\n";
	else cout<<"NO\n";
	for(auto &i:pos)i.clear();
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
