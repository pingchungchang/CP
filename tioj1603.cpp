#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	vector<unsigned int> v(n);
	for(unsigned int i =0;i<n;i++)cin>>v[i];
	vector<unsigned int> biggest(n,0);
	vector<unsigned int> smallest(n,UINT_MAX);
	int g = sqrt(n);
	for(int i =0;i<n;i++){
//		cout<<v[i]<<' ';
//		cout<<"C\n";
		biggest[i/g] = max(biggest[i/g],v[i]);
		smallest[i/g] = min(smallest[i/g],v[i]);
	}
//	for(unsigned int i =0;i<=(n-1)/g;i++)cout<<biggest[i]<<' ';
//	cout<<'\n';
//	for(unsigned int i =0;i<=(n-1)/g;i++)cout<<smallest[i]<<' ';
	for(unsigned int i =0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--,b--;
		if(a>b)swap(a,b);
		unsigned int bg = 0;
		unsigned int sm =  UINT_MAX;
		for(int j =0;j<=(n-1)/g;j++){
			int p1 = j*g;
			int p2 = min((j+1)*g-1,n-1);
//			cout<<p1<<' '<<p2<<"\n\n";
			if(p1>b)break;
			if(p2<a)continue;
			if(p1>=a&&p2<=b){
				bg = max(bg,biggest[j]);
				sm = min(sm,smallest[j]);
				continue;
			}
			for(int k = max(p1,a);k<=min(p2,b);k++){
				bg = max(bg,v[k]);
				sm = min(sm,v[k]);
			}
		}
		cout<<bg-sm<<'\n';
	}
}
