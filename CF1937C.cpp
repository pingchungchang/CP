#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

inline int check(int a,int b,int c,int d){
	cout<<"? "<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	char re;
	cin>>re;
	return re == '<'?0:re=='>'?1:2;
}
inline void output(int a,int b){
	cout<<"! "<<a<<' '<<b<<endl;
	return;
}
int n;

inline int get_big(vector<int> v){
	int ans = v[0];
	for(int i = 1;i<v.size();i++){
		if(check(ans,ans,v[i],v[i]) != 1)ans = v[i];
	}
	return ans;
}
inline int get_small(vector<int> v){
	int ans = v[0];
	for(int i = 1;i<v.size();i++){
		if(check(ans,ans,v[i],v[i]) != 0)ans = v[i];
	}
	return ans;
}
inline vector<int> get_cand(vector<int> v,int b){
	vector<int> re = {v[0]};
	for(int i = 1;i<v.size();i++){
		int tmp = check(re.back(),b,v[i],b);
		if(tmp==2)re.push_back(v[i]);
		else if(tmp==0){
			re.clear();
			re.push_back(v[i]);
		}
	}
	return re;
}

void solve(){
	cin>>n;
	vector<int> v;
	for(int i = 0;i<n;i++)v.push_back(i);
	int b = get_big(v);
	v.clear();
	for(int i = 0;i<n;i++){
		if(i==b)continue;
		v.push_back(i);
	}
	v = get_cand(v,b);
	output(b,get_small(v));
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
