//
// Created by wpl on 2024/4/25.
//
#include "../inc/UiRun.h"
#include "../inc/PageManage.h"
#include "../inc/working_page_home.h"
#include "../../app/R1100P-V5C_IN/Model/inc/dt_r1100p_v5c_dict.h"

void uiRun()
{
    PAGE home_page;
    PageManage manage(&home_page, working_page_home_init);
    manage.page_manage_switch_page(0);
}

void uiHandleInit()
{
    DataTypeDict hdle;
}
