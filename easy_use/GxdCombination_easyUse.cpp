// 暴力法
// long long 最大可以表示20的阶乘
// 要求0<=m<=n<=20
// 平均计算时间为30ms
class GxdCombinationA{
public:
    long long combination(int n, int m){
        if(m < 0 || m > n || n > 20){
            printf("n or m illegal!\n");
            return -1;
        }
        long long ans = 1;
        for(int i = n; i > n - m; i--) ans *= i;
        for(int i = m; i > 1; i--) ans /= i;
        return ans;
    }
};



// 打表法
// 组合数其实是一个杨辉三角
// 由时间上限决定，一秒只能处理1000以内的组合数
class GxdCombinationB{

    static const int MAXN = 1000;
    long long C[MAXN+1][MAXN+1];
    int flag;

public:

    GxdCombinationB(int n=MAXN){                              // 动态规划生成杨辉三角
        memset(C,0,sizeof(C));
        flag = n;
        for(int i = 0; i < n + 1; i++){
            C[i][0] = C[i][i] = 1;
        }
        for(int i = 2; i < n + 1; i++){
            for(int j = 1; j < i; j++){
                C[i][j] = C[i-1][j-1] + C[i-1][j];
            }
        }
    }

    long long combination(int n, int m){
        if(m < 0 || m > n || n > flag){
            printf("n or m illegal!\n");
            return -1;
        }
        return C[n][m];
    }
};



// 质因数分解法
// 当n 超出70时，需要取模或者大整数
class GxdCombinationC{

    static const int MAXN = 1000000;                // 素数最大范围
    bool color[MAXN+1];                             // 筛法素数染色表

public:

    std::vector<int> prime(int n = MAXN){           // 筛法素数
        std::vector<int> ans;
        if(n > MAXN){
            printf("prime n illegal!\n");
            return ans;
        }
        memset(color,0,sizeof(color));
        ans.push_back(2);
        int i;
        for(i = 3; i * i < n + 1; i += 2){  // i退出时也一定是奇数
            if(!color[i]){
                ans.push_back(i);
                for(int j = i * i; j < n + 1; j += i) color[j] = true;
            }
        }
        while(i < n + 1){       // 这里的i也一定是奇数
            if(!color[i]) ans.push_back(i);
            i += 2;
        }
        return ans;
    }

    int factorial(int n, int p){                    // n!中p的指数，这个方法很快
        int ans = 0;
        long long rec = p;
        while(n >= rec){
            ans += n / rec;
            rec *= p;
        }
        return ans;
    }

    GxdBigInt bigpow(int d, int k){                     // 大整数快速幂
        GxdBigInt ans(1);
        GxdBigInt p(d);
        while(k){
            if(k & 1) ans *= p;
            p *= p;
            k >>= 1;
        }
        return ans;
    }

    long long pow(long long p, int k){                    // 快速幂，p的k次方
        long long ans = 1;
        while(k){
            if(k & 1) ans *= p;
            p *= p;
            k >>= 1;
        }
        return ans;
    }

    GxdBigInt bigcombination(int n, int m){
        std::vector<int> pm = prime(n);     // n以内的素数
        GxdBigInt ans(1);
        int num;
        for(int i = 0; i < pm.size(); i++){
            num = factorial(n, pm[i]) - factorial(m, pm[i]) - factorial(n-m, pm[i]);
            ans *= pow(pm[i], num);
        }
        return ans;
    }

    // 当n超出70时，考虑取模或者大整数
    long long combination(int n, int m){
        std::vector<int> pm = prime(n);     // n以内的素数
        long long ans = 1;
        int num;
        for(int i = 0; i < pm.size(); i++){
            num = factorial(n, pm[i]) - factorial(m, pm[i]) - factorial(n-m, pm[i]);
            ans *= pow(pm[i], num);
        }
        return ans;
    }

};
