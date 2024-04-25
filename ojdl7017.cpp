#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 2e6+10;
vector<pair<int,pii>> edges;
int ans[mxn];
int n,m;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i =0;i<m;i++){
		pair<int,pii> tmp;
		cin>>tmp.sc.fs>>tmp.sc.sc>>tmp.fs;
		edges.push_back(tmp);
	}
	sort(edges.begin(),edges.end());
	for(auto &i:edges){
		int ta = max(ans[i.sc.fs],ans[i.sc.sc]+1);
		int tb = max(ans[i.sc.sc],ans[i.sc.fs]+1);
		ans[i.sc.fs] = max(ans[i.sc.fs],ta);
		ans[i.sc.sc] = max(ans[i.sc.sc],tb);
	}
	cout<<*max_element(ans+1,ans+n+1);
}
