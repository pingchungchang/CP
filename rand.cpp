#include <bits/stdc++.h>
using namespace std;

const int a = 1;
const int inf = 1e9;

int main(){
	srand(time(NULL));
	int n = rand()%10+1,q = rand()%10+1;
	cout<<n<<' '<<q<<endl;
	for(int i = 1;i<=q;i++){
		int tp = rand()%2+1;
		if(tp == 1){
			cout<<tp<<' '<<rand()%n<<' '<<rand()%inf+1<<endl;
		}
		else{
			int l = rand()%n,r = rand()%n;
			if(l>r)swap(l,r);
			r++;
			cout<<tp<<' '<<l<<' '<<r<<' '<<rand()%inf+1<<endl;
		}
	}
	return 0;
}
