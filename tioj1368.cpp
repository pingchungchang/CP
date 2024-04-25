#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>



const int mxn = 1e5+10;
ll pref[mxn];
deque<int> dq;
int n;
pii range[mxn];
int arr[mxn];

struct Q{
	int l,r,mn;
	Q(int s,int e,int v){
		l = s,r = e,mn = v;
	}
	Q(){}
	const bool operator<(Q b)const{
		return (pref[r]-pref[l-1])*mn==(pref[b.r]-pref[b.l-1])*b.mn?l==b.l?r>b.r:l>b.l:(pref[r]-pref[l-1])*mn<(pref[b.r]-pref[b.l-1])*b.mn;
	}
};

void solve(){
	for(int i = 1;i<=n;i++)cin>>arr[i];
	arr[0] = arr[n+1] = 0;
	for(int i = 1;i<=n;i++)pref[i] = pref[i-1]+arr[i];
	dq = {0};
	for(int i = 1;i<=n;i++){
		while(!dq.empty()&&arr[dq.back()]>=arr[i])dq.pop_back();
		range[i].fs = i-dq.back();
		dq.push_back(i);
	}
	dq = {n+1};
	for(int i = n;i>=1;i--){
		while(!dq.empty()&&arr[dq.back()]>=arr[i])dq.pop_back();
		range[i].sc = dq.back()-i;
		dq.push_back(i);
	}
	Q ans(0,0,0);
	for(int i = 1;i<=n;i++){
		Q tmp(i-range[i].fs+1,i+range[i].sc-1,arr[i]);
		ans = max(ans,tmp);
	}
	if(ans.l == 0&&ans.r == 0)exit(0);
	dq.clear();
	cout<<(pref[ans.r]-pref[ans.l-1])*ans.mn<<'\n'<<ans.l<<' '<<ans.r<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	while(cin>>n)solve();
}
