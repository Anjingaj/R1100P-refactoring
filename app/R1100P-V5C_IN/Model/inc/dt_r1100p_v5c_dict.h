//
// Created by wpl on 2024/4/24.
//

#ifndef LVGL_DATATYPEDICT_H
#define LVGL_DATATYPEDICT_H

#include "lvgl/lvgl.h"
#include <iostream>
#include <vector>

#define SIZE_OF_DICT 100

using namespace std;

typedef bool (*log_add_handler)( void * );

typedef struct
{
    int32_t min;
    int32_t max;
}dt_r1100p_data_limit_t;

typedef struct {
    uint32_t id;
    void *ptr;
    float factor;//单位之间的转换系数，默认公制是1。
    uint8_t acc;//精度，如果实际值为999.99，那么精度值就是100，因为目前精度最大的也就100，为了节省空间用的uint8_类型，后续可根据实际情况更改
    dt_r1100p_data_limit_t *limit;
}dt_r1100p_idict_t;

class DataTypeDict {
public:
    DataTypeDict();
    ~DataTypeDict();
public:
    bool set_int( uint32_t id, int32_t value, bool en);
    bool set_string(uint32_t id, const char *str, uint32_t len, bool en);
    int32_t get_value_int(uint32_t id);
    int32_t get_value_arr(uint32_t id, uint32_t idx);
    char get_string(uint32_t id);
private:
    dt_r1100p_idict_t idict[ SIZE_OF_DICT ];
    uint32_t size_cur;
    log_add_handler data_change_hook;//有数据发生变化的时候就调用这个函数，若该指针为NULL时则不会执行
    uint32_t (*get_uint)(void);//获取当前单位
};

#endif //LVGL_DATATYPEDICT_H
