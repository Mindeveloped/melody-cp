namespace fastio{const int BUFSIZE=1048576;char ibuf[BUFSIZE],obuf[BUFSIZE];int itop=0,iptr=0,optr=0;
char getchar(){while(iptr>=itop){itop=fread(ibuf,1,BUFSIZE,stdin);iptr=0;}return ibuf[iptr++];
}void flush(){fwrite(obuf,1,optr,stdout);optr=0;}void putchar(char c){obuf[optr++]=c;if(optr==BUFSIZE)flush();}}
namespace iowhl{template<typename T> void read(T &x){int a=0;x=0;char c=fastio::getchar();while(!isdigit(c))a=(c
=='-'?1:a),c=fastio::getchar();while(isdigit(c))x=(x<<3)+(x<<1)+(c^48),c=fastio::getchar();if(a)x=-x;}template<typename
T>void write(T x){if(x<0)x=-x,fastio::putchar('-');if(x>9)write(x/10);fastio::putchar(x%10+48);}}
