#include <stdio.h>
#include <stdlib.h>

int fun1(void);
void fun2(int n);
int recus(int n,int sum);
int fun3(int n);
void recur2(int n); //递归实现
int main(void)
{
    fun2(5);
    fun3(10);
    recur2(5);
    return 0;
}

// 1.常数阶空间复杂度 O(1)
// 常见于与输入数据n无关的变量,函数等
int fun1()
{
    // 常量,变量,对象都为O(1)
    const int a = 0 ;
    int b =20,c[1000];
    // 在循环中开辟的量也是O(1)
    for(int i = 1; i <= 10; i++)
    {
        int a = i;
    }
}

// 2.线性阶空间复杂度 O(n)
void fun2(int n)
{
    int a[n];
}
// 函数调用O(n)次,消耗栈帧空间O(n)
int recus(int n,int sum)
{
    if(n <= 0)
        return 0;
    return recus(n - 1, n + sum);
}

// 3.平方阶空间复杂度O(n^2)
int fun3(int n)
{
    int ** matrix = malloc(sizeof(int *) * n);
    for(int i = 0; i < n; i++){
        int *tmp = malloc(sizeof(int) * n);
        for(int i = 0; i < n; i++)
            tmp[i] = 0;
        matrix[i] = tmp; 
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            printf("%d", matrix[i][j]);
        printf("\n");
    }
    for(int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}

void recur2(int n) //递归实现
{
    if(n <= 0)
        return 0;
    int* num = malloc(sizeof(int) * n);
    printf("递归深度为: %d, 数组长度为%d\n", n , n);
    recur2(n-1);
    free(num);
}

// 4.指数阶:O(2 ^ n)
//指数阶常见于二叉树.深度为n的满二叉树节点数目为2^n

// 5.对数阶O(log n)
//常见于分治的思想,如归并排序等

