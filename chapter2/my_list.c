#include "../utils/common.h"
typedef struct MyList{
    int *arr;
    int size; // 列表个数
    int capacity; // 列表容量
    int extendRatio; // 扩容增长倍率
}MyList;
void extendCapacity(MyList *nums);
/* 构造函数 */
MyList *newMyList(){
    MyList * list = malloc(sizeof(MyList));
    if(list == NULL){
        printf("list 分配失败\n");
        return NULL;
    }
    list->capacity = 10;
    list->size = 0;
    list->extendRatio = 2;
    list->arr = malloc(sizeof(int) * list->capacity);
}

/* 析构函数 */
void delMyList(MyList *nums){
    free(nums -> arr);
    free(nums);
}

/* 获取列表长度 */
int size(MyList *nums){
    return nums->size;
}

/* 获取列表容量 */
int capacity(MyList *nums){
    return nums->capacity;
}

/* 访问元素 */
int get(MyList *nums, int index){
    assert(index >= 0 && index < nums->size);
    return nums->arr[index];
}

/* 更新元素 */
void set(MyList *nums, int index, int num){
    assert(index >= 0 && index < nums->size);
    nums->arr[index] = num;
}

/* 在尾部添加元素 */
void add(MyList *nums, int num){
    if(nums->size == nums->capacity){
        extendCapacity(nums);
    }
    nums->arr[nums->size] = num;
    nums->size++;
}

/* 在中间插入元素 */
void insert(MyList *nums, int index, int num){
    assert(index >= 0 && index < nums->size);
    if(nums->size == nums->capacity){
        extendCapacity(nums);
    }
    /*
    易错点:注意这里得从size开始,如果此时数组元素刚好等于数组容量,
    从size-1开始会导致原来数组最后一个元素没有被拷贝
    for(int i = nums->size - 1; i > index; i--) error
    */
    for(int i = nums->size; i > index; i--)
        nums->arr[i] = nums->arr[i-1];
    nums->arr[index] = num;
    nums->size++;
}

/* 删除元素 */
// 注意：stdio.h 占用了 remove 关键词
int removeItem(MyList *nums, int index){
    assert(index >= 0 && index < nums->size);
    int num = nums->arr[index];
    for(int i = index; i < nums->size - 1; i++)
        nums->arr[i] = nums->arr[i+1];
    nums->size--;
    return num;
}
/* 列表扩容 */
void extendCapacity(MyList *nums){
    /*注意realloc分配的是字节数
    error:  字节数缺少*sizeof(int)
    int * newArr = (int *)realloc(nums->arr,nums->capacity*nums->extendRatio)
    */
    int * newArr = (int *)realloc(nums->arr,sizeof(int)*nums->capacity*nums->extendRatio);
    if(newArr == NULL){
        printf("扩容失败\n");
        exit(1);
    }
    nums->capacity = nums->capacity*nums->extendRatio;
    //注意扩容后要指向新数组
    nums->arr = newArr;
}
/* 将列表转换为 Array 用于打印 */
int *toArray(MyList *nums){
    return nums->arr;
}

int main() {
    /* 初始化列表 */
    MyList *nums = newMyList();
    /* 在尾部添加元素 */
    add(nums, 1);
    add(nums, 3);
    add(nums, 2);
    add(nums, 5);
    add(nums, 4);
    printf("列表 nums = ");
    printArray(toArray(nums), size(nums));
    printf("容量 = %d ，长度 = %d\n", capacity(nums), size(nums));

    /* 在中间插入元素 */
    insert(nums, 3, 6);
    printf("在索引 3 处插入数字 6 ，得到 nums = ");
    printArray(toArray(nums), size(nums));

    /* 删除元素 */
    removeItem(nums, 3);
    printf("删除索引 3 处的元素，得到 nums = ");
    printArray(toArray(nums), size(nums));

    /* 访问元素 */
    int num = get(nums, 1);
    printf("访问索引 1 处的元素，得到 num = %d\n", num);

    /* 更新元素 */
    set(nums, 1, 0);
    printf("将索引 1 处的元素更新为 0 ，得到 nums = ");
    printArray(toArray(nums), size(nums));

    /* 测试扩容机制 */
    for (int i = 0; i < 10; i++) {
        // 在 i = 5 时，列表长度将超出列表容量，此时触发扩容机制
        add(nums, i);
    }

    printf("扩容后的列表 nums = ");
    printArray(toArray(nums), size(nums));
    printf("容量 = %d ，长度 = %d\n", capacity(nums), size(nums));

    /* 释放分配内存 */
    delMyList(nums);

    return 0;
}