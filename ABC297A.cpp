#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int d;
	cin>>d;
	int pre;
	cin>>pre;
	for(int i = 1;i<n;i++){
		int k;
		cin>>k;
		if(k-pre<=d){
			cout<<k;
			return 0;
		}
		pre = k;
	}
	cout<<-1;
	return 0;
}
