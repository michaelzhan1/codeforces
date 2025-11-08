// TODO: clean and clarify

#include<bits/stdc++.h>
#define pf printf
#define sc(x) scanf("%d", &x)
#define scs(x) scanf("%s", x)
#define scl(x) scanf("%lld", &x)
#define mst(a,x) memset(a, x, sizeof(a))
#define rep(i,s,e) for(int i=s; i<e; ++i)
#define dep(i,e,s) for(int i=e; i>=s; --i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 5e6 + 5;
char s[maxn],ma[2*maxn];
int che[2*maxn],ww[2*maxn];
void manacher(char* s,int len0){
    int len=0; ma[len++]='$'; ma[len++]='#';
    rep(i,0,len0) ma[len++]=s[i],ma[len++]='#';
    ma[len]=0; int maxx=0,num=0;
    rep(i,0,len){
        che[i]=maxx>i?min(che[2*num-i],maxx-i):1;
        while(ma[i+che[i]]==ma[i-che[i]]) che[i]++;
        if(i+che[i]>maxx) maxx=i+che[i],num=i;
    }
}
void solve(int len){
    ll ans(0); rep(i,1,len+1){
        int l=2,r=2*i,m=l+r>>1;
        if(che[m]*2>r-l+1) ww[r]=ww[m-1-(m-1)%2]+1;
        ans+=ww[r];
    } pf("%lld\n",ans);
}
int main(){
    scs(s); int len=strlen(s);
    manacher(s,len); solve(len);
}