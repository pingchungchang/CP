#include <bits/stdc++.h>
using namespace std;

bool notprime[(int)1e7+1] = {};
int total[(int)1e7+1] = {};
void filter(int n){
	for(int i = 2*n;i<=1e7;i+=n){
		notprime[i]=true;
	}
	return;
}
int main(){
	for(int i =2;i<=1e7;i++){
		total[i] = total[i-1];
		if(notprime[i] == false){
			total[i] +=1;
			filter(i);
		}
	}
	int k;
	cin>>k;
	for(int asd=0;asd<k;asd++){
		int x;
		cin>>x;
		cout<<total[x]<<'\n';
	}
}
