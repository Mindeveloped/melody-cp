#include<bits/stdc++.h>
#define F(i,x,y) for (int i=(x);i<=(y);i++)
#define ll long long
using namespace std;

namespace dinic {
    const int N=1e5+5,M=2e5+5;
    const ll inf=1e18;
    int n,m,head[N],nxt[2*M],cnt=1;
    struct edge {
        int to;
        ll wt;
    } e[2*M];
    void add_edge (int u,int v,ll w) {
        nxt[++cnt]=head[u]; head[u]=cnt;
        e[cnt].to=v; e[cnt].wt=w;
        nxt[++cnt]=head[v]; head[v]=cnt;
        e[cnt].to=u; e[cnt].wt=0;
    }
    int dep[N],cur[N];
    queue<int> q;
    bool bfs (int s,int t) {
        F(i,1,n) dep[i]=0,cur[i]=head[i];
        dep[s]=1;
        q.push (s);
        while (q.size ()) {
            int tp=q.front ();
            q.pop ();
            for (int i=head[tp];i;i=nxt[i]) {
                if (e[i].wt&&!dep[e[i].to]) {
                    dep[e[i].to]=dep[tp]+1;
                    q.push (e[i].to);
                }
            }
        }
        return dep[t];
    }
    ll dinic (int x,int t,ll flow) {
        if (x==t) return flow;
        ll res=0;
        while (cur[x]) {
            auto tp=e[cur[x]];
            if (dep[tp.to]==dep[x]+1) {
                ll inc=dinic (tp.to,t,min(flow,tp.wt));
                res+=inc; flow-=inc;
                e[cur[x]].wt-=inc; e[cur[x]^1].wt+=inc;
            }
            if (!flow) return;
            cur[x]=nxt[cur[x]];
        }
        return res;
    }
    ll launch (int s,int t) {
        ll res=0;
        while (bfs (s,t)) res+=dinic (s,t,inf);
        return res;
    }
}