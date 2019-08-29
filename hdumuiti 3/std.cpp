#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
int phi[maxn];
void getphi(){
    for(int i = 2; i < maxn; i++){
        phi[i] = i;
    }
    phi[1] = 1;
    for(int i = 2; i < maxn; i++){
        if(phi[i] == i){
            for(int j = i; j < maxn; j += i){
                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}
ll num[maxn];
void init(){
    getphi();
    memset(num,0,sizeof(num));
    num[2] = 1;
    for(int i = 3; i < maxn; i++){
        num[i] = num[i-1] + phi[i];
    }
}
int main(){
    init();
    int n;
    while(scanf("%d",&n) != EOF && n){
        printf("%lld\n",num[n]);
    }
    return 0;
}
//1000000