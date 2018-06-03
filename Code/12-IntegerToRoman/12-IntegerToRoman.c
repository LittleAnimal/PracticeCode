char* intToRoman(int num) {

    int i, j, remainder = num, totals, tmp;
    int table[7] = {1000, 500, 100, 50, 10, 5, 1};
    char chs[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    char *ans;
    int count[7];
    
    memset(count, 0, sizeof(count));
    
    for (i=0; i<7; i = i + 2) {
        count[i] = remainder / table[i];
        remainder = remainder % table[i];
    }
  
    for (i=0, totals=0; i<7; i++) {
        tmp = count[i];
        if (tmp == 4 || tmp == 9) {
            tmp = 2;
        } else if (tmp > 5) {
            tmp = 1 + (tmp - 5);
        }
        totals += tmp;
    }
    
    ans = (char *)malloc((totals+1)*sizeof(char));
    
    for (i=0, totals=0; i<7; i++) {
        tmp = count[i];
        if (tmp == 9 || tmp == 4) {
            ans[totals++] = chs[i];
            ans[totals++] = tmp == 9 ? chs[i-2] : chs[i-1];
        } else if (tmp >= 5) {
            ans[totals++] = chs[i-1];
            for (j=0; j<tmp-5; j++) {
                ans[totals++] = chs[i];
            }
        } else if (tmp >0) {
            for (j=0; j<tmp; j++) {
                ans[totals++] = chs[i];
            }
        }
    }
    ans[totals++] = '\0';
    ans = (char *)realloc(ans, totals*sizeof(char));
    
    return ans;
}