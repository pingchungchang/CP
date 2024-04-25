#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    while(cin>>n){
        if(n == 0) return 0;
        string s;
        int k = 0;
        while(n != 0){
            if(n%2 == 1){
                s = "1"+s;
                k++;
            }
            else s = "0"+s;
            n /= 2;
        }
        cout<<"The parity of "<<s<<" is "<<k<<" (mod 2).\n";
    }
}
