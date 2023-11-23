#ifndef DATACENTER_FILTER_H
#define DATACENTER_FILTER_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdint.h>


#define FILTER_USE_DEBUG        1

typedef uint32_t (*filter_get_func_t)(void);

typedef enum{
    filter_median,
    filter_none,
    FILTER_FUNC_MAX_NUM,
}filterFuncType_t;


typedef struct filter_struct{
    /* ���ù������ĳ�ʼ */
    uint32_t (*Filter)(struct filter_struct* pFilter);
    /* �ı�������ĳ��� */
    int (*ChangeLen)(struct filter_struct* pFilter,uint16_t len);
    /* �ı������������ */
    void (*ChangeFilter) (struct filter_struct* pFilter,filterFuncType_t type);
    /* ���û�ȡ���� ָ���ǻ�ȡ���ݵĺ��� */
    void (*SetGetFunc)(struct filter_struct* pFilter,filter_get_func_t func);

#if FILTER_USE_DEBUG
    unsigned int* (*GetInternalBuf)(struct filter_struct* pFilter);
#endif
}filter_t;

typedef struct {
    filter_t filter;
    unsigned int* buf;
    short bufLen;
    filter_get_func_t getFunc;
}filterInternal_t;



#ifdef __cplusplus
extern "C"{
#endif
filter_t* FilterNew(short len);
void FilterDelete(filter_t* pFilter);
#ifdef __cplusplus
}
#endif






#endif //DATACENTER_FILTER_H
