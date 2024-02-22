#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* nextFor(int n);

int main()
{
    int n;
    scanf("%d", &n);
    char *s = nextFor(n);
    printf("%s\n", s);
   free(s);
    s = NULL;

    return 0;
}

/* int 一般32字节 最大值21亿多 */ 
char* nextFor(int n)
{
    /*字符串最多有 6+2*10位,加上'\0'*/ 
    int size = n*n*26+1;
    char *ret = (char*)malloc(size * sizeof(char));
    if(ret == NULL){
        printf("Fail malloc !\n");
        exit(1); //退出进程
    }
    memset(ret, 0, sizeof(ret));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
        {
            char tmp[26];
            snprintf(tmp, sizeof(tmp), "(%d, %d), ", i ,j);
            strncat(ret, tmp, size - strlen(ret) - 1);
        }
    }
    return ret;
}