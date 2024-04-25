#include <bits/stdc++.h>
using namespace std;

int f(int a,int b){
	int k;
	int na= 0,nb = 0;
	while(cin>>k){
		if(k == 0){
			if(na>0&&nb>0)return 1;
			else return 0;
		}
		if(abs(k) == a){
			na += k/a;
		}
		else if(abs(k) == b){
			nb += k/b;
		}
	}
}
int main(){
	int a,b;
	cin>>a>>b;
	int ans = 0;
	int n;
	cin>>n;
	for(int i = 0;i<n;i++){
		ans += f(a,b);
	}
	cout<<ans;
}
