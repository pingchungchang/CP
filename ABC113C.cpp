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

struct node{
	int y,id,c;
	node(){}
	bool operator<(node& b)const{
		return y<b.y;
	}
};

const int mxn = 1e5+10;
int cnt[mxn];
string ans[mxn];
int main(){
	int n,m;
	cin>>m>>n;
	node arr[n];
	for(int i = 0;i<n;i++){
		arr[i].id = i;
		cin>>arr[i].c>>arr[i].y;
	}
	sort(arr,arr+n);
	for(auto &i:arr){
		string a = to_string(i.c);
		while(a.size() != 6)a = "0"+a;
		string b = to_string(++cnt[i.c]);
		while(b.size() != 6)b = "0"+b;
		ans[i.id] = a+b;
	}
	for(int i= 0;i<n;i++)cout<<ans[i]<<'\n';
}

