#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int inf = 2e9+10;
const int mxn = 1e6+10;
bitset<mxn> done;
bitset<mxn> safe;
int n,m,g,r;
int ans[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>g>>r;
	fill(ans,ans+mxn,inf);
	for(int i = 0;i<m;i++){
		int k;
		cin>>k;
		safe[k] = true;
	}
	queue<int> q;
	q.push(0);
	done[0] = true;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
	}
}
