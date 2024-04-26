//
// Created by wpl on 2024/4/25.
//
#include "../inc/UiRun.h"
#include "../inc/PageManage.h"
#include "../inc/working_page_home.h"

void uiRun()
{
    PAGE home_page;
    PageManage manage(&home_page, working_page_home_init);
    manage.page_manage_switch_page(0);
}
