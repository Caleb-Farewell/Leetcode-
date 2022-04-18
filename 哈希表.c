#include <stdio.h>
#include <string.h>
#include "uthash.h"

typedef struct HashTable
{
    int key;
    int value;
    UT_hash_handle hh;
}HashTable;

struct HashTable* hash;


//哈希表的查找
struct HashTable* Find(int key)
{
    struct HashTable* s = NULL;
    HASH_FIND_INT(hash,&key,s);
    return s;
}

//哈希表的增加
void add(int key,int value)
{
    //首先判断该值在哈希表中是否存在
    struct HashTable* tp = Find(key);
    if(tp == NULL)
    {
        struct HashTable* adhash =(struct HashTable*)malloc(sizeof(struct HashTable));
        adhash->key = key;
        adhash->value = value;
        HASH_ADD_INT(hash,key,adhash);
    }
}

//哈希表的删除
void Delete(struct HashTable* s)
{
    HASH_DEL(hash,s);
    free(s);
    s = NULL;
}

//哈希表的清空和计数
void clearALL()
{
    struct HashTable *s,*tmp = NULL;
    HASH_ITER(hh,hash,s,tmp);
    {
        delete(s);
    }

    //计数
    int count = HASH_COUNT(hash);
}