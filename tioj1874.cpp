#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1e7+10;
int lpf[mxn];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	for(int i = 2;i<mxn;i++){
		if(!lpf[i]){
			for(int j = i;j<mxn;j+=i)lpf[j] = i;
		}
	}
	int q;
	cin>>q;
	while(q--){
		int k;
		cin>>k;
		pii now = make_pair(1,0);
		int ans = 1;
		while(k != 1){
			if(now.fs == lpf[k])now.sc++;
			else ans *= now.sc+1,now = make_pair(lpf[k],1);
			k/=lpf[k];
		}
		ans = ans*(now.sc+1);
		cout<<ans<<'\n';
	}
}
