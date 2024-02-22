#include <stdio.h>

// 对1~100求和
int main()
{
    int n = 100;
    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += i;
    }
    printf("%d\n", ans);
}