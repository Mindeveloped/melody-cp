struct mat {
    static const int DIM=2;
    int a[DIM][DIM];
    mat () {
        memset(a,0,sizeof(a));
    }
    mat (const mat &b) {
        memcpy(a,b.a,sizeof(b.a));
    }
    mat operator + (const mat&b) const {
        mat c;
        F(i,0,DIM-1){
            F(j,0,DIM-1){
                c.a[i][j]=a[i][j]+b.a[i][j];
            }
        }
        return c;
    }
    mat operator * (const mat&b) const {
        mat c;
        F(i,0,DIM-1){
            F(j,0,DIM-1){
                c.a[i][j]=0;
                F(k,0,DIM-1){
                    c.a[i][j]+=a[i][k]*b.a[k][j];
                }
            }
        }
        return c;
    }
};