#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    int n,k,m,l;
    cin >> l;
    for (int i = 0; i < l;i++){
        cin >> n >> k;
        m = 0;
        for (int s = 0; s < n;s++){
            int j;
            cin >> j;
            if(j<=0) m +=1;
        }
        if(m>=k) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }

}