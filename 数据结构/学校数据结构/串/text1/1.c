#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define maxn 1005
int next[maxn];

typedef struct {
    char ch[maxn];
    int len;
}SString;

int BF(SString s, SString t) {
    if (s.len < 1 || t.len<1 || t.len>s.len) {
        return -1;
    }
    int i = 0, j = 0;
    while (i < s.len && j < t.len) {
        if (s.ch[i] == t.ch[j]) {
            i++; j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
        if (j >= t.len)
            return i - t.len + 1;
    }
    return -1;
}

void fnext(SString t) {
    int j = 0, k = -1;
    next[0] = -1;
    while (j < t.len - 1) {
        if (k == -1 || t.ch[j] == t.ch[k]) {
            j++; k++;
            next[j] = k;
        }
        else
            k = next[k];
    }
}

int KMP(SString s, SString t) {
    fnext(t);
    int i = 0, j = 0;
    while (i < s.len && j < t.len) {
        if (j == -1 || s.ch[i] == t.ch[j]) {
            i++; j++;
        }
        else j = next[j];
    }
    if (j >= t.len)
        return i - t.len + 1;
    else
        return -1;
}

//T2
void zcggzc(SString s, SString t) {
    int a[maxn][maxn];
    int m = 0, mi = 0;
    for (int i = 0; i < s.len; i++) {
        for (int j = 0; j < t.len; j++) {
            a[i][j] = 0;
            if (s.ch[i] == t.ch[j]) {
                a[i][j]++;
                if (i > 0 && j > 0) {
                    a[i][j] += a[i - 1][j - 1];
                }
            }
            if (a[i][j] > m) {
                m = a[i][j];
                mi = i;
            }
        }
    }
    if (m == 0) {
        printf("None\n");
        return;
    }
    for (int i = mi - m + 1; i <= mi; i++) {
        printf("%c", s.ch[i]);
    }
}

int main() {
    SString str1, str2;
    printf("H\n");
    scanf("%d", &str1.len);
    scanf("%s", str1.ch);
    scanf("%d", &str2.len);
    scanf("%s", str2.ch);
    int m = BF(str1, str2);
    int n = KMP(str1, str2);
    printf("%d %d\n", m, n);
    zcggzc(str1, str2);
    return 0;
}