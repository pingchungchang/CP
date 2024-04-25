#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	map<int,int> st;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		arr[i] = k;
		st[k]++;
	}
	int mex;
	for(mex = 0;mex<=n&&st.find(mex)!= st.end();mex++);
	int l = n,r = 0;
	for(int i = 0;i<n;i++){
		if(arr[i] == mex+1)l = min(l,i),r = max(r,i);
	}
	for(int i = l;i<=r;i++)arr[i] = mex;
	if(l>r){
		bool flag = true;
		for(auto &i:arr){
			if(!flag)break;
			if(i>mex)i = mex,flag = false;
			else if(st[i]>1)i = mex,flag = false;
		}
	}
	st.clear();
	for(auto &i:arr)st[i]++;
	int mex2;
	for(mex2 = 0;mex2<=n&&st.find(mex2)!= st.end();mex2++);
	if(mex2 == mex+1)cout<<"YEs\n";
	else cout<<"NO\n";
	return;
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
}
