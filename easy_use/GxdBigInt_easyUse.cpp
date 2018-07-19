

/*
 * 高精度整型，此模版较慢，用于日常程序，大量vector赋值
 */


class GxdBigInt{

    static const int BASE = 100000000;
    static const int WIDTH = 8;

    std::vector<int> s;
    bool signbit;    // false为正数，true为负数

public:

    GxdBigInt(){s.clear();signbit = false;}                    //无参数构造
    GxdBigInt(long long num){*this = num;}         //长整型构造
    GxdBigInt operator = (long long num){                      //长整型赋值
        s.clear();
        signbit = false;
        if(num < 0){    //负数
            signbit = true;
            num = 0 - num;
        }
        do{
            s.push_back(num % BASE);
            num /= BASE;
        }while(num > 0);
        return *this;
    }
    GxdBigInt operator = (const std::string& str){            //字符串赋值
        std::string strcopy = str;
        signbit = false;
        if(str[0] == '-'){      //负数
            signbit = true;
            strcopy = strcopy.substr(1);
        }
        s.clear();
        int x;
        int len = (strcopy.length() - 1) / WIDTH + 1;
        for(int i = 0;i < len; i++) {
            int end = strcopy.length()- i * WIDTH;
            int start = std::max(0, end - WIDTH);
            sscanf(strcopy.substr(start, end - start).c_str(), "%d", &x);
            s.push_back(x);
        }
        return *this;
    }
    GxdBigInt operator = (const GxdBigInt& b) {                 //大整数赋值
        s = b.s;
        signbit = b.signbit;
        return *this;
    }
    bool lessthan(const std::vector<int> &x,const std::vector<int> &y) const {     // 单纯数组大小比较
        if(x.size() != y.size()) return x.size() < y.size();
        for(int i = (int)x.size()-1; i >= 0; i--)
            if (x[i] != y[i]) return x[i] < y[i];
        return false;
    }
    bool morethan(const std::vector<int> &x,const std::vector<int> &y) const {return lessthan(y,x);}
    bool operator < (const GxdBigInt& b) const {                     //大整数比较
        if(signbit && (!b.signbit)) return true;
        else if((!signbit) && b.signbit) return false;
        else if(signbit) return morethan(s,b.s);
        else return lessthan(s,b.s);
    }
    bool operator > (const GxdBigInt& b) const{ return b < *this; }
    bool operator <= (const GxdBigInt& b) const{ return !(b < *this); }
    bool operator >= (const GxdBigInt& b) const{ return !(*this < b); }
    bool operator != (const GxdBigInt& b) const{ return b < *this || *this < b; }
    bool operator == (const GxdBigInt& b) const{ return !(b < *this) && !(*this < b);}
    GxdBigInt operator << (const long long num) const {                 //左移变大
        GxdBigInt c;
        c = *this;
        c.s.insert(c.s.begin(), num, 0);
        return c;
    }
    std::vector<int> add(const std::vector<int> &x,const std::vector<int> &y) const {    // 无符号相加
        std::vector<int> z;
        for(int i = 0, g = 0; ; i++) {
            if(g == 0 && i >= x.size() && i >= y.size()) break;
            int t = g;
            if(i < x.size()) t += x[i];
            if(i < y.size()) t += y[i];
            z.push_back(t % BASE);
            g = t / BASE;
        }
        return z;
    }
    std::vector<int> minus(const std::vector<int> &x,const std::vector<int> &y) const {     // 无符号相减，保证x>y
        std::vector<int> z;
        for(int i = 0, g = 0; i < x.size(); i++){
            int t = x[i] - g;   // x不会超过BASE
            if(i < y.size()){
                if(t < y[i]){ g = 1;    z.push_back(BASE + t - y[i]); }
                else if(t >= y[i]) { g = 0;    z.push_back(t - y[i]); }
            }else z.push_back(t);
        }
        return z;
    }
    GxdBigInt operator + (const GxdBigInt& b) const {           //大整数相加
        GxdBigInt c;
        if((!signbit) && b.signbit && morethan(s,b.s)){ c.s = minus(s,b.s);}
        if((!signbit) && b.signbit && lessthan(s,b.s)){ c.signbit = true; c.s = minus(b.s,s);}
        if((!signbit) && (!b.signbit)){ c.s = add(s,b.s);}
        if(signbit && (!b.signbit) && morethan(s,b.s)){ c.signbit = true; c.s = minus(s,b.s);}
        if(signbit && (!b.signbit) && lessthan(s,b.s)){ c.s = minus(b.s,s);}
        if(signbit && b.signbit){ c.signbit = true; c.s = add(s,b.s);}
        return c;
    }
    GxdBigInt operator - (const GxdBigInt& b) const {                    //大整数减法
        GxdBigInt c;
        if((!signbit) && b.signbit){ c.s = add(s,b.s);}
        if((!signbit) && (!b.signbit) && morethan(s,b.s)){ c.s = minus(s,b.s);}
        if((!signbit) && (!b.signbit) && lessthan(s,b.s)){ c.signbit = true; c.s = minus(b.s,s);}
        if(signbit && (!b.signbit)){ c.signbit = true; c.s = add(b.s,s);}
        if(signbit && b.signbit && lessthan(s,b.s)){ c.s = minus(b.s,s);}
        if(signbit && b.signbit && morethan(s,b.s)){ c.signbit = true; c.s = minus(s,b.s);}
        return c;
    }
    GxdBigInt operator += (const GxdBigInt& b) {                   //大整数累加
        *this = *this + b;
        return *this;
    }
    GxdBigInt operator * (long long num) const {                    //大整数乘以长整型
        GxdBigInt c;
        for(int i = 0; i < s.size() ; i++){
            GxdBigInt d;
            d = s[i] * num;
            c += (d << i);
        }
        return c;
    }
    GxdBigInt operator * (const GxdBigInt& b) const {               //大整数间相乘
        GxdBigInt c;
        for(int i = 0; i < s.size(); i++){
            GxdBigInt d;
            d = (b * s[i]);
            c += (d << i);
        }
        if(signbit != b.signbit) c.signbit = true;
        return c;
    }
    GxdBigInt operator *= (long long num) {                         //自增乘以长整型
        *this = *this * num;
        return *this;
    }
    GxdBigInt operator *= (GxdBigInt& b) {                           //自增乘以大整数
        *this = *this * b;
        return *this;
    }
    void print(const char c) const {                                      //输出，参数c是指输出大整数后再输出一个字符
        int l = (*this).s.size();
        if(l != 0){
            printf("%s%d",signbit?"-":"",(*this).s[l-1]);
            for(int i=l-2;i>=0;i--) printf("%08d",(*this).s[i]);
        }
        printf("%c",c);
    }
};