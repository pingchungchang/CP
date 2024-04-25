#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ld long double
#define _all(T) T.begin(),T.end()


int n;
const int mxn = 1e5+10;
int rnk[mxn];
vector<pair<pii,int>> v[mxn];
pair<pii,int> buf[mxn];
int h[mxn];
int pos[mxn];
void bucket_sort(int d){
	for(auto &i:v)i.clear();
	for(int i = 0;i<n;i++){
		if(i+d<n){
			buf[i] = {{rnk[i],rnk[i+d]},i};
		}
		else buf[i] = {{rnk[i],0},i};	
		v[buf[i].fs.sc].push_back(buf[i]);
	}
	int cnt = 0;
	for(auto &i:v){
		for(auto &j:i){
			buf[cnt++] = j;
		}
		i.clear();
	}
	for(int i = 0;i<n;i++){
		v[buf[i].fs.fs].push_back(buf[i]);
	}
	cnt = 0;
	pair<pii,int> pre = {{-1,-1},-1};
	for(auto &i:v){
		for(auto &j:i){
			if(pre.fs.fs != j.fs.fs||pre.fs.sc != j.fs.sc)cnt++;
			rnk[j.sc] = cnt;
			pre = j;
		}
	}
	return;
	
}
int main(){
	string s;
	cin>>s;
	n = s.size();
	for(int i = 0;i<n;i++){
		rnk[i] = s[i]-'a'+1;
	}
	for(int i = 1;i<n;i<<=1){
//		for(int i = 0;i<n;i++)cout<<rnk[i]<<' ';cout<<endl;
		bucket_sort(i);
	}
	for(int i = 0;i<n;i++){
		pos[rnk[i]] = i;
	}
	int k = 0;
	for(int i = 0;i<n;i++){
		int pi = rnk[i];
		if(pi == 1){
			k = max(k-1,0);
			continue;
		}
		int pre = pos[pi-1];
//		cout<<i<<' '<<pre<<endl;
		while(i+k<n&&pre+k<n&&s[i+k] == s[pre+k])k++;
		h[pi] = k;
		k = max(k-1,0);
	}
	
//	for(int i = 1;i<=n;i++)cout<<pos[i]<<' ';cout<<endl;
//	for(int i = 2;i<=n;i++)cout<<h[i]<<' ';cout<<endl;
	ll ans = n-pos[1];
	for(int i = 2;i<=n;i++){
		ans += n-pos[i]-h[i];
		if(n-pos[i]-h[i]<0){
			cout<<"ERROR\n";
			return 0;
		}
//		cout<<n-pos[i]-h[i]<<' ';
	}
	cout<<ans;
}


