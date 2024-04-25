#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

int h,w;
pii pa,pb;

int mv(int r,int t,int dir){
	if(dir == 1)return min(r+t,w)-r;
	else return r-max(1,r-t);
}


void solve(){
	cin>>h>>w>>pa.fs>>pa.sc>>pb.fs>>pb.sc;
	if(pa.fs>=pb.fs){
		cout<<"Draw\n";
		return;
	}
	int dy = pb.fs-pa.fs;
	int t = abs(pa.fs-pb.fs);
	int ta = (t+1)>>1,tb = t>>1;
	/*
	if(pa.sc == pb.sc){
		cout<<(dy&1?"Alice\n":"Bob\n");
		return;
	}

   */
	int dx = abs(pa.sc-pb.sc);
	if(dy&1){
		int dir = (pb.sc>pa.sc?1:-1);
		//cout<<dir<<":"<<t<<"::"<<ta<<' '<<tb<<' '<<mv(pa.sc,ta,dir)<<','<<mv(pb.sc,tb,dir)<<','<<dx<<endl;
		if(mv(pb.sc,tb,dir)+dx<=mv(pa.sc,ta,dir))cout<<"Alice\n";
		else cout<<"Draw\n";
	}
	else{
		int dir = (pa.sc>pb.sc?1:-1);
		if(mv(pa.sc,ta,dir)+dx<=mv(pb.sc,tb,dir))cout<<"Bob\n";
		else cout<<"Draw\n";
	}
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
