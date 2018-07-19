
/*
 * 支持，高精度整型，此模版很快，用于ACM
 */


// 输出print(vector)
void print(const std::vector<long long> &x) {
    int l = x.size();
    if( l == 0) printf("0\n");
    else{
        printf("%lld",x[l-1]);
        for(int i = l - 2; i >= 0; i--){
            printf("%08lld",x[i]);
        }
        printf("\n");
    }
}

// 赋值assignment(vector,long long)
void assignment(std::vector<long long> &x,long long y){
    x.clear();
    while(y > 0){
        x.push_back(y % BASE);
        y /= BASE;
    }
}

// 加法add(vector,vector,vector) 特别注意，结果放在第一个v，用时会清空，所以不应该出现add(z,z,x)这种情况
void addv(std::vector<long long> &z,const std::vector<long long> &x,const std::vector<long long> &y){
    z.clear();
    for(long long i = 0, g = 0; ; i++){
        if( g == 0 && i >= x.size() && i >= y.size()) break;
        long long t = g;
        if( i < x.size()) t += x[i];
        if( i < y.size()) t += y[i];
        z.push_back(t % BASE);
        g = t / BASE;
    }
}

// 减法minusv(vector,vector,vector) 特别注意，必须保证，相减是合法的，即，y>x
void minusv(std::vector<long long> &z,const std::vector<long long> &x,const std::vector<long long> &y){
    z.clear();
    long long g = 0;
    for(int i = 0; i < x.size() ; i++){
        long long t = 0;
        if(i < y.size()) t += y[i];
        if(x[i] - g < t){ z.push_back(BASE - t + x[i] - g); g = 1;}
        else{ z.push_back(x[i] - g - t); g = 0;}
    }
    int loc = (int)z.size() - 1;
    while(loc>=0&&loc<z.size()){
        if(z[loc--] == 0) z.pop_back();
        else break;
    }
}

// 乘法multilong(vector,long long,vector)
void multilong(std::vector<long long> &z, long long x,const std::vector<long long> &y){
    z.clear();
    long long t = 0;
    for(int i = 0; i < y.size(); i++){
        t += y[i] * x;
        z.push_back( t % BASE );
        t /= BASE;
    }
    if(t!=0) z.push_back(t);
}

// 乘法multiv(vector,vector,vector) 特别注意，结果放在第一个v，用时会清空，所以不应该出现multiv(z,z,x)这种情况
void multiv(std::vector<long long> &z,const std::vector<long long> &x,const std::vector<long long> &y){
    z.clear();
    std::vector<long long> t;
    std::vector<long long> zt;
    for(int i = 0; i < x.size(); i++){
        multilong(t,x[i],y);
        t.insert(t.begin(),i,0);
        addv(zt,t,z);
        z = zt;
    }
}