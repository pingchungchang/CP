#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define fs first
#define sc second
#define pii pair<int,int>

const int mxn = 3e5+10;
int n,m;

int mv(int &pos,int &dir,int t){
	pos += dir*t;
	if(pos<=0)pos = abs(pos),dir = -dir;
	else if(pos>=m)pos = m*2-pos,dir = -dir;
	return pos;
}

int calc(int p1,int d1,int p2,int d2){
	int t = 0;
	if(d1 == -1){
		t+=p1;
		mv(p1,d1,t);
		mv(p2,d2,t);
	}
	if(d2 == 1){
		t += m-p2;
		mv(p1,d1,m-p2);
		mv(p2,d2,m-p2);
	}
	//cout<<p1<<' '<<d1<<' '<<p2<<' '<<d2<<' '<<t<<',';
	return (p2-p1)/2+t;
}

void solve(){
	cin>>n>>m;
	tuple<int,int,int> arr[n];
	pll val[n];
	int ans[n] = {};
	memset(ans,-1,sizeof(ans));
	for(int i = 0;i<n;i++){
		cin>>(get<0>(arr[i]));
		val[i].fs = get<0>(arr[i]);
		get<2>(arr[i]) = i;
	}
	for(int i = 0;i<n;i++){
		char c;
		cin>>c;
		if(c == 'L')get<1>(arr[i]) = -1;
		else get<1>(arr[i]) = 1;
		val[i].sc = get<1>(arr[i]);
	}
	sort(arr,arr+n);
	deque<int> dq[2];
	for(auto &i:arr){
		int roll = get<0>(i)&1;
		//cout<<(get<2>(i))<<' '<<roll<<',';
		if(get<1>(i) == -1&&!dq[roll].empty()){
			auto nxt = dq[roll].back();dq[roll].pop_back();
			ans[nxt] = ans[get<2>(i)] = calc(val[nxt].fs,val[nxt].sc,get<0>(i),get<1>(i));
		}
		else dq[roll].push_back(get<2>(i));
	}
	for(int i= 0;i<2;i++){
		while(dq[i].size()>=2){
			int b = dq[i].back();dq[i].pop_back();
			int a = dq[i].back();dq[i].pop_back();
			ans[a] = ans[b] = calc(val[a].fs,val[a].sc,val[b].fs,val[b].sc);
			//cout<<a<<','<<b<<'\n';
		}
	}
	for(int i = 0;i<n;i++)cout<<ans[i]<<' ';cout<<'\n';
	return;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
