//
// Created by wpl on 2024/4/24.
//

#include "PageManage.h"
#include "working_page_home.h"

PageManage::PageManage(PAGE* home_page, void (*init)(lv_obj_t* page))
{
    home_page->page = lv_obj_create(NULL);
    home_page->pageID = 0;
    home_page->init = init;
    curr_page = NULL;
    pageList.push_back(home_page);
}
PageManage::~PageManage()
{

}

void PageManage::page_manage_add_page(PAGE* page, unsigned char id, lv_screen_load_anim_t anim, void (*init)(lv_obj_t* page))
{
    page->pageID = id;
    page->page = lv_obj_create(NULL);
    page->init = init;
    pageList.push_back(page);
}

void PageManage::page_manage_switch_page(unsigned char id)
{
    unsigned char i;
    for (i = 0; i < pageList.size(); i++)
    {
        PAGE* page = pageList[i];

        if (page->pageID == id)
        {

            page->init(page->page);
            if(curr_page != NULL)
                lv_obj_clean(curr_page->page);
            curr_page = page;
            break;
        }
    }
}