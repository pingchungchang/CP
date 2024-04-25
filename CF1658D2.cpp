#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>


const int mxn = 1<<18;
int l,r;
vector<int> st,tar;

inline bool check(vector<int> &a,int sh){
	vector<int> tmp = tar;
	for(auto &i:tmp)i>>=sh;
	for(auto &i:a)i>>=sh;
	sort(a.begin(),a.end());
	sort(tmp.begin(),tmp.end());
	for(int i = 0;i<a.size();i++){
		if(a[i] != tmp[i])return false;
	}
	return true;
}

void solve(){
	cin>>l>>r;
	st.clear();tar.clear();
	for(int i = l;i<=r;i++){
		st.push_back(i);
	}
	for(int i = l;i<=r;i++){
		int k;
		cin>>k;
		tar.push_back(k);
	}
	int ans = 0;
	for(int i = 18;i>=0;i--){
		vector<int> v;
		for(auto &j:st){
			v.push_back(j^ans);
		}
		if(!check(v,i))ans ^= 1<<i;
	}
	cout<<ans<<'\n';
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
