#include <bits/stdc++.h>
using namespace std;

struct node{
	int l;
	int r;
	node(){
		l = -1;
		r = -1;
	}
};
int main(){
	int n;
	cin>>n;
	vector<node> v(n+1,node());
	int root = 0;
	for(int i = 1;i<=n;i++){
		char c;
		cin>>c;
		if(c == 'L'){
			int form = v[i-1].l;
			if(form == -1){
				root = i;
				v[i-1].l = i;
				v[i].r = i-1;
			}
			else{
				v[form].r = i;
				v[i-1].l = i;
				v[i].r = i-1;
				v[i].l = form;
			}
		}
		else{
			int lat = v[i-1].r;
			if(lat == -1){
				v[i-1].r = i;
				v[i].l = i-1;
			}
			else{
				v[i-1].r = i;
				v[lat].l = i;
				v[i].l = i-1;
				v[i].r = lat;
			}
		}
	}
	while(root != -1){
		cout<<root<<' ';
		root = v[root].r;
	}
}
