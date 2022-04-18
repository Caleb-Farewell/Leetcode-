#include <stdio.h>
#include "uthash.h"
struct HashTable
{
    int key;           //存储值
    int value;         //存储下标
    UT_hash_handle hh; //必备
} HashTable;
struct HashTable *hash; //直接定义一个哈希表的头指针

//哈希表的查找
struct HashTable *find(int key)
{
    struct HashTable *s = NULL;
    HASH_FIND_INT(hash, &key, s); // uthash库的函数，哈希表的查找
    return s;
}

//哈希表的插入
void Insert(int key, int value)
{
    //插入之前首先查找一下是否有这个值
    struct HashTable *tmp = NULL;
    tmp = find(key);
    if (tmp == NULL) //不存在的时候插入
    {
        struct HashTable *tp = (struct HashTable *)malloc(sizeof(struct HashTable));
        tp->key = key;
        tp->value = value;
        HASH_ADD_INT(hash, key, tp); //库函数，哈希表的增加
    }
    else
    {
        tmp->value = value;
    }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *ret;
    hash = NULL;
    //哈希表算法
    Insert(nums[0], 0); //将数据插入到哈希表中
    int i = 0;
    for (i = 1; i < numsSize; i++)
    {
        struct HashTable *it = find(target - nums[i]); //在哈希表中查找两个数之和的另一个数是否在哈希表中
        if (it != NULL)                                //存在则找到
        {
            ret = (int *)malloc(sizeof(int) * 2);
            ret[0] = it->value;
            ret[1] = i;
            *returnSize = 2;
            return ret;
        }
        Insert(nums[i], i); //否则就将该值插入到哈希表中
    }
    *returnSize = 0;
    return ret;
}