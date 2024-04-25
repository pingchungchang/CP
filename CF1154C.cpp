#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int weeks = min(a/3,min(b/2,c/2));
	a -= weeks*3;
	b -= weeks*2;
	c -= weeks*2;
	vector<int> w = {0,1,2,0,2,1,0,0,1,2,0,2,1,0};
	int d = 0;
	for(int i = 0;i<7;i++){
		vector<int> v = {a,b,c};
		for(int j = 0;j<7;j++){
			if(v[w[i+j]] == 0){
//				cout<<i<<' '<<j<<endl<<endl;
				d = max(d,j);
				break;
			}
			v[w[i+j]]--;
		}
	}
	cout<<weeks*7+d;
}
