// const int N=1e5+5;
struct segt{
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
	void pushdown(int p,int tl,int tr){
		if(tag[p]){
			simp(ls[p],tag[p]);
			simp(rs[p],tag[p]);
			tag[p]=0;
		}
	}
	void modify(int p,int tl,int tr,int ml,int mr,int x){
		if(ml<=tl&&tr<=mr){
			simp(p,x);
			return;
		}
		pushdown(p,tl,tr);
		int mid=(tl+tr)>>1;
		if(ml<=mid)modify(ls[p],tl,mid,ml,mr,x);
		if(mr>mid)modify(rs[p],mid+1,tr,ml,mr,x);
		val[p]=merge(val[ls[p]],val[rs[p]]);
	}
	data query(int p,int tl,int tr,int ql,int qr){
		if(ql<=tl&&tr<=qr)return val[p];
		pushdown(p,tl,tr);
		int mid=(tl+tr)>>1;
		if(qr<=mid)return query(ls[p],tl,mid,ql,qr);
		if(ql>mid)return query(rs[p],mid+1,tr,ql,qr);
		return merge(query(ls[p],tl,mid,ql,qr),query(rs[p],mid+1,tr,ql,qr));
	}
	int build(int tl,int tr){
		int p=++cnt;
		if(tl!=tr){
			int mid=(tl+tr)>>1;
			ls[p]=build(tl,mid);
			rs[p]=build(mid+1,tr);
		}
		return p;
	}
};
