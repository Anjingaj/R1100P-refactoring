//
// Created by wpl on 2024/4/25.
//
#include "UiRun.h"
#include "PageManage.h"
#include "working_page_home.h"

void uiRun()
{
    PAGE home_page;
    PageManage manage(&home_page, working_page_home_init);
    manage.page_manage_switch_page(0);
}
