#include <bits/stdc++.h>
using namespace std;
int n,m,s;
const int M = 500100;
int head[M*2],nxt[M*2],to[M*2],depth[M*2],cnt;
int f[M*2][26];

void add(int f,int t){
    to[++cnt] = t;
    nxt[cnt] = head[f];
    head[f] = cnt;
}

void init(int now=s, int fa=0){    //now表示当前节点，fa表示其父亲节点
	f[now][0] = fa; depth[now]=depth[fa]+1;
	for(int i=1;(1<<i)<=depth[now];i++){
		f[now][i] = f[f[now][i-1]][i-1];
	}
	for(int i=head[now];i!=-1;i=nxt[i]){
		if(to[i]!=fa)init(to[i],now);
	}
}

// void init(int u=s,int fa=0)
// {
//     depth[u]=depth[fa]+1;
//     f[u][0]=fa;
//     for(int i=1;(1<<i)<=depth[u];i++)
//         f[u][i]=f[f[u][i-1]][i-1];
//     for(int i=head[u];i;i=nxt[i])
//     {
//         int v=to[i];
//         if(v!=fa)
//             init(v,u);
//     }
// }    

int lca(int a,int b){
	if(depth[a]<depth[b])swap(a,b);
	for(int i=20;i>=0;i--)
		if(depth[f[a][i]]>=depth[b])a = f[a][i]; //还没到就上跳
	if(a==b)return a;
	for(int k=20;k>=0;k--){
		if(f[a][k]!=f[b][k]){
			a= f[a][k];
			b= f[b][k];
		}
	}
	return f[a][0];
}

// int lca(int a,int b)                                          //非常标准的lca查找
// {
//     if(depth[a]>depth[b])
//         swap(a,b);           //保证a是在b结点上方，即a的深度小于b的深度
//     for(int i=20;i>=0;i--)
//         if(depth[a]<=depth[b]-(1<<i))
//             b=f[b][i];             //先把b移到和a同一个深度
//     if(a==b)
//         return a;                 //特判，如果b上来和就和a一样了，那就可以直接返回答案了
//     for(int i=20;i>=0;i--)
//     {
//         if(f[a][i]==f[b][i])
//             continue;
//         else
//             a=f[a][i],b=f[b][i];           //A和B一起上移
//     }
//     return f[a][0];               //找出最后a值的数字
// }

int main(){
    memset(head,-1,sizeof(head));
    cin>>n>>m>>s;
    for(int i=1;i<=n-1;i++){
        int f,t;
        cin>>f>>t;
        add(f,t);
        add(t,f);
    }
    init();
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        cout<<lca(a,b)<<endl;
    }
}