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

int a[11][11],b[11][11];
int h1,w1,h2,w2;
bool flag = false;
vector<int> rdel,cdel;

void check(){
//	for(auto i:rdel)cout<<i<<' ';cout<<',';for(auto i:cdel)cout<<i<<' ';cout<<endl;
	for(int i = 0;i<h2;i++)for(int j = 0;j<w2;j++)if(a[rdel[i]][cdel[j]] != b[i][j])return;
	flag = true;
}
void col(){
	if(cdel.size()>=w2){
		check();
		return;
	}
	for(int i = (cdel.empty()?0:cdel.back()+1);i<w1;i++){
		cdel.push_back(i);
		col();
		cdel.pop_back();
	}
	return;
}
void row(){
	if(rdel.size()>=h2){
		col();
		return;
	}
	for(int i = (rdel.empty()?0:rdel.back()+1);i<h1;i++){
		rdel.push_back(i);
		row();
		rdel.pop_back();
	}
	return;
}
int main(){
	io
	cin>>h1>>w1;
	for(int i = 0;i<h1;i++)for(int j = 0;j<w1;j++)cin>>a[i][j];
	cin>>h2>>w2;
	for(int i = 0;i<h2;i++)for(int j = 0;j<w2;j++)cin>>b[i][j];
	row();
	if(flag)cout<<"Yes";
	else cout<<"No";
}

