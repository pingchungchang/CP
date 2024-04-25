#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define tlll tuple<ll,ll,ll>

string a,b;
vector<int> ans;
pii r1,r2;
int one = 0;
int n;

inline void shift(int x){
	ans.push_back(x);
	string tmp = string(n,'0')+a+string(n,'0');
	for(int i = 0;i<n;i++){
		if(a[i] == tmp[n+i+x])a[i] = '0';
		else a[i] = '1';
	}
	r1 = {-1,-1};
	for(int i = 0;i<n;i++){
		if(a[i] == '1'){
			if(r1.fs == -1)r1.fs = i;
			r1.sc = i;
		}
	}
	return;
}

void RGO(){
	for(int i = 0;i<n;i++){
		if(a[i] != b[i])shift(r1.fs-i);
	}
}
void LGO(){
	for(int i = n-1;i>=0;i--){
		if(a[i] != b[i])shift(r1.sc-i);
	}
}

void solve(){
	one = 0;
	ans.clear();
	cin>>n;
	cin>>a>>b;
	n = a.size();
	for(auto &i:a)if(i == '1')one|=1;
	for(auto &i:b)if(i == '1')one|=2;
	if(one != 0&&one != 3){
		cout<<"-1\n";
		return;
	}
	if(one == 0){
		cout<<"0\n";
		return;
	}
	r1 = r2 = {-1,-1};
	for(int i = 0;i<n;i++){
		if(b[i] == '1'){
			if(r2.fs == -1)r2.fs = i;
			r2.sc = i;
		}
		if(a[i] == '1'){
			if(r1.fs == -1)r1.fs = i;
			r1.sc = i;
		}
	}
	//cout<<r1.fs<<' '<<r1.sc<<' '<<r2.fs<<' '<<r2.sc<<endl;
	if(r1.fs>=r2.fs){
		if(r1.fs !=r2.fs)shift(r1.fs-r2.fs);
		RGO();
	}
	else if(r1.sc<=r2.sc){
		if(r1.sc != r2.sc)shift(r1.sc-r2.sc);
		LGO();
	}
	else{
		for(int i = r2.fs;i>=0;i--){
			if(a[i] != b[i]&&i != r1.sc)shift(r1.sc-i);
		}
		RGO();
	}
	cout<<ans.size()<<'\n';
	for(auto &i:ans)cout<<i<<' ';cout<<'\n';
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	while(t--)solve();
}
