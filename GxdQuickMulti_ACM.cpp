/*
 * 快速幂
 * 
 */ 

// 快速幂，保证不超过long long
long long quickmulti_longlong(long long x,long long t){  
    // x 底数，t 指数
    long long ans;              // 结果
    for (ans=1;t;t>>=1,x=x*x) {
        if(t & 1) ans *= x;
    }
    return ans;
}

// 快速幂，含有边界判断
long long quickmulti_boundary(long long x,long long t,long long b){
    // x 底数，t 指数，d 边界
    long long ans;
    for(ans=1;t;t>>=1,x=x*x){
        if(t&1) ans *= x;
    }
}

// 快速幂，mod
long long quickmulti_mod(long long x,long long t,long long mod){
    
}