#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n,a,b;
bool f(int k){
	int na = 0;
	int nb = 0;
	for(int i = k;i>=0;i--){
		if(v[i] == 0){
			if(nb<b)nb++;
			else na++;
		}
		else{
			if(nb>0&&na<a){
				nb--;
				na++;
			}
			else{
				nb++;
			}
		}
		if(na>a||nb>b)return false;
	}
	return true;
}
int main(){
	cin>>n>>a>>b;
	v = vector<int>(n);
	for(int i = 0;i<n;i++)cin>>v[i];
	int l = 0;
	int r = n-1;
	while(l != r){
		int mid = (l+r+1)/2;
		if(f(mid) == true){
			l = mid;
		}
		else r = mid-1;
	}
	cout<<r+1;
}
