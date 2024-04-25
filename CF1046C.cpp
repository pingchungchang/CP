#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<int> p;
int player;
int n,d;

bool f(int now){
	for(int i = now-1;i<n-1;i++){
		if(v[i]+p[n-2+(now-1)-i]>player)return false;
	}
	return true;
}
int main(){
	cin>>n>>d;
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(i == d-1){
			player = k;
		}
		else v.push_back(k);
	}
	for(int i = 0;i<n;i++){
		int k;
		cin>>k;
		if(i == 0)player += k;
		else p.push_back(k);
	}
	int l = 1,r = n;
	while(l != r){
		int mid = (l+r)/2;
		if(f(mid)){
			r = mid;
		}
		else l = mid+1;
	}
	cout<<l;
	return 0;
}
