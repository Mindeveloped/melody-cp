// const int N=1e5+5;
struct segtree_mergable{
	int rt,ls[2*N],rs[2*N],cnt;
	struct data {
		int sum=0;
	} val[2*N];
	int tag[2*N];
	void simp (int p,int x) {
		val[p].sum+=x;
		tag[p]+=x;
	}
	data merge(data x,data y){
		data res;
		res.sum=x.sum+y.sum;
		return res;
	}
	void modify(int &p,int tl,int tr,int k,int x){
        if(!p) p=++cnt;
		if(tl==tr){
			simp(p,x);
			return;
		}
		int mid=(tl+tr)>>1;
		if(k<=mid)modify(ls[p],tl,mid,k,x);
		else modify(rs[p],mid+1,tr,k,x);
		val[p]=merge(val[ls[p]],val[rs[p]]);
	}
	data query(int p,int tl,int tr,int ql,int qr){
		if(ql<=tl&&tr<=qr)return val[p];
		int mid=(tl+tr)>>1;
		if(qr<=mid)return query(ls[p],tl,mid,ql,qr);
		if(ql>mid)return query(rs[p],mid+1,tr,ql,qr);
		return merge(query(ls[p],tl,mid,ql,qr),query(rs[p],mid+1,tr,ql,qr));
	}
    data madd(data x,data y){
        return merge(x,y);
    }
    void mergetree(int &x,int y){
        if(!y) return;
        if(!x) {
            x=y;
            return;
        } 
        val[x]=merge(val[x],val[y]);
        mergetree(ls[x],ls[y]);
        mergetree(rs[x],rs[y]);
    }
};
