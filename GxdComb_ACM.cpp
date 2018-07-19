
/*
 * 打表组合数
 */



// 打表组合数
long long C[40][40];        // 组合数

void Comb(){
    // 组合数
    for(int i = 1; i < 51; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}
