#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

const int mxn = 5050;
int ldp[mxn],rdp[mxn];
int N,M;
string a,b;
int pi[mxn*2];

void KMP(string &s){
	pi[0] = 0;
	if(s[0] == s[1])pi[1] = 1;
	else pi[1] = 0;
	for(int i = 2;i<s.size();i++){
		pi[i] = 0;
		int pt = pi[i-1];
		while(pt&&s[pt]!=s[i])pt = pi[pt-1];
		if(!pt){
			if(s[0] == s[i])pi[i] = 1;
			else pi[i] = 0;
		}
		else pi[i] = pt+1;
	}
	return;
}

bool check(int pa,int pb,bool dir){
	if(pb<0||pb>=M)return true;
	if(!dir){//check if a[0:pa] has b[0:pb]
		return ldp[pa+1]>=pb+1;
	}
	else{//check if a[pa:N-1] has b[pb:M-1]
		int need = M-pb;
		return rdp[pa+1]>=need;
	}
}

void solve(){
	cin>>N>>M>>a>>b;
	for(int i = 1;i<=N;i++){
		ldp[i] = ldp[i-1];
		if(a[i-1] == b[ldp[i]])ldp[i]++;
	}
	for(int i = N;i>=1;i--){
		rdp[i] = rdp[i+1];
		if(a[i-1] == b[M-1-rdp[i]])rdp[i]++;
	}
	/*
	for(int i = 1;i<=N;i++)cout<<ldp[i]<<' ';cout<<endl;
	for(int i = 1;i<=N;i++)cout<<rdp[i]<<' ';cout<<endl;

   */
	int ans = mxn<<3;

	for(int i = 0;i<N;i++){
		string tmp = a.substr(i,N-i)+"#"+b;
		KMP(tmp);
		int L = N-i+1;
		for(int j = 0;j<M;j++){
			if(pi[L+j] == 0)continue;
			int len = pi[L+j];
			int lp = i,rp = i+len-1;
			int pre = j-len+1,nxt = j;
			int ldel = 0,rdel = 0;
			if(check(lp-1,pre-1,0)){
				if(lp)ldel = lp+1+(lp-pre);
			}
			else continue;
			if(check(rp+1,nxt+1,1))rdel = (N-rp-1);
			else continue;
			//cout<<i<<' '<<j<<":"<<lp<<' '<<rp<<','<<pre<<' '<<nxt<<endl;
			int tans = ldel+rdel;
			tans = min(tans,N);
			//cout<<i<<' '<<j<<":"<<tans<<endl;
			ans = min(ans,tans);
		}
	}
	cout<<(ans>mxn*3?-1:ans)<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
