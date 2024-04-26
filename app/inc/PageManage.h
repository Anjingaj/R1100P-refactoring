//
// Created by wpl on 2024/4/24.
//

#ifndef LVGL_PAGEMANAGE_H
#define LVGL_PAGEMANAGE_H

#include "lvgl/lvgl.h"
#include <iostream>
#include <vector>

using namespace std;

typedef struct
{
    unsigned char     pageID;             //pageID 每个页面有唯一的ID
    lv_obj_t*         page;               //界面
    lv_screen_load_anim_t load_anim;
    void (*init)(lv_obj_t* page);         //页面初始化
    void (*exit)(lv_obj_t* page);         //退出动画

}PAGE;

class PageManage {
public:
    PageManage(PAGE* home_page, void (*init)(lv_obj_t* page));
    ~PageManage();

public:
    void page_manage_add_page(PAGE* page, unsigned char id, lv_screen_load_anim_t anim,void(*init)(lv_obj_t* page));
    void page_manage_switch_page(unsigned char id);

private:
    PAGE* curr_page;
    vector<PAGE *> pageList;
};

#endif //LVGL_PAGEMANAGE_H
