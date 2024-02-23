#include <stdio.h>
#include <stdlib.h>

#define SIZE(x) (sizeof(x) / sizeof(x[0]))

void insert(int *arr, int size, int index, int num);
void erase(int *arr, int size, int index, int num);
int* extend( int *arr, int size, int enlarge);

int main()
{
	int arr[10] = {1,2,3,4,5,6,7};
	printf("插入元素前: arr数组中的元素为: "); 
	 for(int i = 0;i< SIZE(arr); i++)
	 printf("%d ", arr[i]);
	 printf("\n");
	 insert(arr,SIZE(arr),6,666); 
	printf("在索引为%d插入%d元素后: arr数组中的元素为: ", 6,666); 
	 for(int i = 0; i < SIZE(arr); i++)
	 printf("%d ", arr[i]);
	 printf("\n");
	 printf("删除元素前: arr数组中的元素为: "); 
	 for(int i = 0;i< SIZE(arr); i++)
	 printf("%d ", arr[i]);
	 printf("\n");
	 erase(arr,SIZE(arr),6,666); 
	printf("在索引为%d删除%d元素后: arr数组中的元素为: ", 6,666); 
	for(int i = 0; i < SIZE(arr); i++)
	 printf("%d ", arr[i]);
	 printf("\n");  

    return 0;
 } 

 // 在索引为index处插入元素num
 void insert(int *arr, int size, int index, int num)
 {
    for (int i = size - 1; i > index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = num;
 }
 // 在索引为index处删除元素num
 void erase(int *arr, int size, int index, int num)
 {
    for (int i = index; i < size - 1; i++){
        arr[i] = arr[i+1];
    }
 }
 // 如果是要在数组的第几个元素插入和删除,则对应得index下标要减1

 int* extend( int *arr, int size, int enlarge){
	int newSize = size + enlarge;
	int *newArr = malloc(sizeof(arr) * newSize);
	if (newArr == NULL){
		printf("扩容数组失败\n");
		return arr;
	}
	// 将原数组拷贝过去
	for(int i = 0; i < size; i++){
		newArr[i] = arr[i];
	}
	// 将未初始化部分赋值为0
	for(int i = 0; i < newSize; i++){
		newArr[i] = 0;
	}
	return newArr;
 }