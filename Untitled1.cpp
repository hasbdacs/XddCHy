#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
int n,m,s,d;
int g[505][505];
int dis[505];
int num[505],weight[505],path[505],w[505];
bool st[505];
void dijkstra(){
	dis[s]=0;
	num[s]=1;
	for(int i=0;i<n;i++){//先找未标记并标记 、 更新邻近点
		int u=-1,MIN=inf;
		for(int j=0;j<n;j++){
			if(!st[j]&&dis[j]<MIN){
				MIN=dis[j];
				u=j;
			}
		}
		st[u]=1;
		for(int v=0;v<n;v++){
			if(!st[v]&&g[u][v]!=inf&&dis[u]+g[u][v]<dis[v]){
				dis[v]=g[u][v]+dis[u];
				num[v]=num[u];
				path[v]=u;
				w[v]=weight[v]+w[u];
			}
			else if(!st[v]&&g[u][v]!=inf&&dis[u]+g[u][v]==dis[v]){
				num[v]+=num[u];
				if(w[u]+weight[v]>w[v]){
					w[v]=w[u]+weight[v];
					path[v]=u;
				}
			}
		}
	}
}
int fg;
void dayin(int x){
	if(x==s)return ;
	dayin(path[x]);
	if(!fg)fg=1;
	else cout<<" ";
	cout<<x;
}
int main(){
	cin>>n>>m>>s>>d;
	memset(g,inf,sizeof(g));
	memset(dis,inf,sizeof(g));
	for(int i=0;i<n;i++){
		cin>>weight[i];
	}
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		g[a][b]=g[b][a]=c;
	}
	dijkstra();
	cout<<num[d]<<" "<<w[d]<<endl;
	dayin(d);
}

