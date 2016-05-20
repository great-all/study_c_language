#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>


#define HASH_TABLE_SIZE 100
typedef struct _Bucket{
    char *key;
    int value;
    struct _Bucket *next;

} Bucket;

typedef struct _HashTable{
    long int size;
    long int current_num;
    Bucket **buckets;
} HashTable;


bool initHashTable(HashTable *);

bool inserHashTable(HashTable *,char *,int);

Bucket*  searchHashTable(HashTable *,char *);

int hashIndex(char *);


int main(){
    bool init = false,insert = false;

    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));

    init = initHashTable(ht);

    Bucket *bucket = NULL;

    if(init == false){
        printf("初始化哈希表失败\n");
        return 0;
    }

    insert = inserHashTable(ht,"hello",123);
    if(insert == false)
    {
        printf("插入哈希表失败\n");
        return 0;
    }

    bucket = searchHashTable(ht,"a");

    if(bucket != NULL)
    {
        printf("key is %s and value is %d",bucket->key,bucket->value);
        return 0;
    }

    printf("没有找到\n");
    return 0;

}

bool initHashTable(HashTable *ht)
{
    //判断指针是否为空
    ht->size = HASH_TABLE_SIZE;
    ht->current_num = 0;
    ht->buckets = (Bucket **)calloc(ht->size,sizeof(Bucket *));

    if(ht->buckets == NULL) return false;

    return true;
}

bool inserHashTable(HashTable *tb,char *key,int value)
{
    //根据key 计算出hash值
    int index = hashIndex(key);

    Bucket *orgBucket = tb->buckets[index];
    Bucket *tmpBucket = orgBucket;

    while(tmpBucket)
    {
        if(strcmp(key,tmpBucket->key) == 0)
        {
            tmpBucket->value = value;
            return true;
        }
        tmpBucket = tmpBucket->next;
    }

    Bucket *bucket = (Bucket*)malloc(sizeof(Bucket));
    if(bucket == NULL) return false;

    bucket->key = key;
    bucket->value = value;
    bucket->next = NULL;

    tb->current_num += 1;

    if(orgBucket != NULL)
    {
        bucket->next = orgBucket;
    }

    tb->buckets[index] = bucket;

    return true;

}

int hashIndex(char *key)
{
    int sum = 0;
    char *cur = key;
    while(*cur != '\0')
    {
        sum += *cur;
        ++cur;
    }
    return sum % HASH_TABLE_SIZE;
}

Bucket *  searchHashTable(HashTable *tb,char *key)
{
    //根据key 计算出hash值
    int index = hashIndex(key);

    Bucket *bucket = tb->buckets[index];

    while(bucket)
    {
        if(strcmp(bucket->key,key) == 0)
            return bucket;

        bucket = bucket->next;
    }
}
