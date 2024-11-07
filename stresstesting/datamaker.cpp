#include<bits/stdc++.h>
#define F(i,x,y) for (int i=(x);i<=(y);i++)
#define R(i,x,y) for (int i=(x);i>=(y);i--)
#define p2i pair<int,int>
#define ll long long
#define fi first
#define se second
#define MT int testcases;cin>>testcases;while(testcases--)
#define pub push_back
#define ins insert
#define puf push_front
#define vec vector
#define umap unordered_map
#define uset unordered_set
#define popf pop_front
#define popb pop_back
#define NOI2024 GG
#define m1i modint<998244353>
#define m2i modint<1000000007>
#define iosoptim ios::sync_with_stdio(0);cin.tie(0);
using namespace std;
namespace melodyextras{

	namespace fastio{const int BUFSIZE=1048576;char ibuf[BUFSIZE],obuf[BUFSIZE];int itop=0,iptr=0,optr=0;
	char getchar(){while(iptr>=itop){itop=fread(ibuf,1,BUFSIZE,stdin);iptr=0;}return ibuf[iptr++];
	}void flush(){fwrite(obuf,1,optr,stdout);optr=0;}void putchar(char c){obuf[optr++]=c;if(optr==BUFSIZE)flush();}}
	namespace iowhl {
		int read () {
			int a = 0, x = 0;
			char c = fastio::getchar();
			while (!isdigit(c)) a = (c == '-' ? 1 : a), c = fastio::getchar();
			while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = fastio::getchar();
			return a ? -x : x;
		}
		void write (int x) {
			if (x < 0) x = -x, fastio::putchar('-');
			if (x > 9) write (x / 10);
			fastio::putchar (x % 10 + 48);
		}
	}

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
	template<typename T> T popc(int x){return __builtin_popcount(x);}
}
using namespace melodyextras;

int main(){
	freopen(".in","w",stdout);
	
	return 0;
}
