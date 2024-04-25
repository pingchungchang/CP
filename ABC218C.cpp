#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second

const int mxn = 202;
string s[mxn],t[mxn];
vector<pii> va,vb;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>s[i];
	}
	for(int i = 0;i<n;i++)cin>>t[i];
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(s[i][j] == '#')va.push_back({i,j});
		}
	}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<n;j++){
			if(t[i][j] == '#')vb.push_back({i,j});
		}
	}
	bool flag = true;
	if(va.size() != vb.size()){
		cout<<"No";
		return 0;
	}
	pii d = {va[0].fs-vb[0].fs,va[0].sc-vb[0].sc};
	for(int i = 0;i<va.size();i++){
		if(va[i].fs-vb[i].fs != d.fs||va[i].sc-vb[i].sc != d.sc)flag = false;
	}
	if(flag){
		cout<<"Yes\n";
		return 0;
	}
	auto rotate = [&](){
		for(int i = 0;i<n;i++){
			for(int j = i+1;j<n;j++)swap(t[i][j],t[j][i]);
		}
		for(int i = 0;i+i<n;i++){
			for(int j = 0;j<n;j++){
				swap(t[i][j],t[n-1-i][j]);
			}
		}
		/*
		cout<<endl;
		for(int i = 0;i<n;i++)cout<<t[i]<<endl;
		cout<<endl;

	   */
		vb.clear();
		for(int i = 0;i<n;i++)for(int j = 0;j<n;j++)if(t[i][j] == '#')vb.push_back({i,j});
		return;
	};
	for(int i = 0;i<=4;i++){
		flag = true;
		rotate();
		pii d = {va[0].fs-vb[0].fs,va[0].sc-vb[0].sc};
		for(int i = 0;i<va.size();i++){
			if(va[i].fs-vb[i].fs != d.fs||va[i].sc-vb[i].sc != d.sc)flag = false;
		}
		if(flag){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
