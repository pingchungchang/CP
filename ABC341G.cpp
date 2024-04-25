#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>
#define ld long double

const int mxn = 2e5+10;
ll pref[mxn];
ld ans[mxn];
int N;
vector<int> st;

bool check(int a,int b,int c){
	return 1ll*(a-b)*(pref[c]-pref[b])-1ll*(c-b)*(pref[a]-pref[b])<=0;
}

ld calc(int s,int e){
	//cout<<s<<' '<<e<<":"<<(pref[e]-pref[s-1])/(ld)(e-s+1)<<endl;
	return (pref[e]-pref[s-1])/(ld)(e-s+1);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>N;
	for(int i = 1;i<=N;i++){
		cin>>pref[i];
		pref[i] += pref[i-1];
	}
	st.push_back(N);
	for(int i = N-1;i>=0;i--){
		while(st.size()>1&&check(i,st.end()[-1],st.end()[-2]))st.pop_back();
		ans[i+1] = calc(i+1,st.back());
		st.push_back(i);
	}
	for(int i = 1;i<=N;i++)cout<<fixed<<setprecision(10)<<ans[i]<<'\n';
	return 0;
}
