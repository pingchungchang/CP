#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 3e5+10;
tlll mv[mxn];

ll row,col;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ll n,m,C,q;
	cin>>n>>m>>C>>q;
	map<ll,ll> ans,mr,mc;
	for(int i = 0;i<q;i++){
		cin>>get<0>(mv[i])>>get<1>(mv[i])>>get<2>(mv[i]);
	}
	for(int i = q-1;i>=0;i--){
		int tp = get<0>(mv[i]);
		int p = get<1>(mv[i]);
		int c = get<2>(mv[i]);
		if(tp == 1&&mr.find(p) == mr.end()){
			mr[p] = c;
			ans[c] += m-col;
			row++;
		}
		else if(tp == 2&&mc.find(p) == mc.end()){
			mc[p] = c;
			ans[c] += n-row;
			col++;
		}
	}
	for(int i = 1;i<=C;i++)cout<<ans[i]<<' ';
}
