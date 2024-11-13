// const int N=1e5+5;
struct dsunion {
    int fa[N],sz[N];
    void init(int n){
        F(i,1,n) fa[i]=i,sz[i]=1;
    }
    int find(int x){ // this function is non-const
        return fa[x]==x?x:fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        x=find(x),y=find(y);
        if(x==y)return;
        if(sz[x]<sz[y])swap(x,y);
        sz[x]+=sz[y];
        fa[y]=x;
    }
}