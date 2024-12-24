#define m1i modint<998244353>
#define m2i modint<1000000007>
#define cjsm modint<998442353>
template<int m> struct modint{
	int val;
	modint(){val=0;}
	modint(int x) {val=x;}
	modint(const modint &obj) {val=obj.val;}
	modint operator +(modint b) const {return {(val+b.val)%m};}
	modint operator -(modint b) const {return {(val+m-b.val)%m};}
	modint operator -() const {return {val?m-val:0};}
	modint operator *(modint b) const {return {1ll*val*b.val%m};}
	modint inversion() const {
		int a=1,u=val,k=m-2;
		while(k){
			if(k&1)a=1ll*a*u%m;
			u=1ll*u*u%m;
			k>>=1;
		}
		return {a};
	}
	modint operator /(modint b) const {return operator *(b.inversion());}
	modint operator +=(modint b) {return (*this)=(*this)+b;}
	modint operator -=(modint b) {return (*this)=(*this)-b;}
	modint operator *=(modint b) {return (*this)=(*this)*b;}
	modint operator /=(modint b) {return (*this)=(*this)/b;}
};
template<int m> istream& operator >>(istream &in,modint<m> &x) {
	return in>>x.val;
}
template<int m> ostream& operator <<(ostream &out,modint<m> x) {
	return out<<x.val;
}
template<int m> modint<m> qpow(modint<m> x,int k){
	modint<m> a=1,u=x;
	while(k){
		if(k&1)a=a*u;
		u=u*u;
		k>>=1;
	}
	return a;
}
