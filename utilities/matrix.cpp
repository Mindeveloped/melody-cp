template<int n,int m> struct matrix {
    int a[n+1][m+1];
    matrix() { memset(a,0,sizeof(a)); }
    matrix(const matrix<n,m> &obj) { memcpy(a,obj.a,sizeof(obj.a)); }
    matrix operator +(const matrix<n,m> &obj) const {
        matrix<n,m> res;
        F(i,1,n){
            F(j,1,m){
                res.a[i][j]=a[i][j]+obj.a[i][j];
            }
        }
        return res;
    }
    matrix operator -(const matrix<n,m> &obj) const {
        matrix<n,m> res;
        F(i,1,n){
            F(j,1,m){
                res.a[i][j]=a[i][j]-obj.a[i][j];
            }
        }
        return res;
    }
    template<int k>
    matrix<n,k> operator *(const matrix<m,k> &obj){
        matrix<n,m> res;
        F(i,1,n){
            F(j,1,m){
                F(p,1,k) {
                    res.a[i][p]+=a[i][j]*obj.a[j][p];
                }
            }
        }
        return res;
    }
};