#include <Arduino.h>
#include <global.h>
#include <menu/menu.h>
#include <display/u8g2_print.h>
#include <API_function/API_function.h>

//这里专门用来放定义好的回调函数

/*
    函数名字：run_info
    函数功能：显示内容。如果内容为菜单/列表就顺便检测按键并更改菜单/列表
    返回值：
        类型：bool
        意义：是否退出循环回调
    参数：
        param
        类型：void*
        作用：指向一个display_info，
*///
bool run_info(void* param){

    display_info* INFO = (display_info*)param;

        switch( INFO->mode ){
        case DISPLAY_MODE_NONE   :{}break;// 不显示
        case DISPLAY_MODE_LOADING:{
            if(get_last_key() == KEY_BACK_NUM)return true;
        }break;// 加载中
        case DISPLAY_MODE_TEXT   :{
            if(get_last_key() == KEY_BACK_NUM)return true;
        }break;// 信息显示(简单提示)
        case DISPLAY_MODE_MENU   :{
            if(set_menu_cursor( INFO->data.menu_t ))return true;
        }break;// 菜单显示
        case DISPLAY_MODE_LIST   :{
            if(set_list_cursor( INFO->data.list_t ))return true;
        }break;// 文字列表
        case DISPLAY_MODE_IMAGE  :{
            if(get_last_key() == KEY_BACK_NUM)return true;
        }break;// 图片显示
        case DISPLAY_MODE_SETTING:{
            if(get_last_key() == KEY_BACK_NUM)return true;
        }break;//设置选项显示
    }

    set_display_info( INFO );
    return false;
}

/*
    函数名字：run_menu
    函数功能：简单地进入菜单
    返回值：
        类型：bool
        意义：是否退出循环回调
    参数：
        param
        类型：void*
        作用：指向一个 menu 结构体，用来确定进入哪个菜单
*///
bool run_menu(void* param){

    static display_info MENU_INFO;
    static menu* MENU;
    MENU = (menu*)param;
    
    if(set_menu_cursor( MENU ))return true;
    MENU_INFO = menu_to_display_info( MENU );
    set_display_info( &MENU_INFO );
    return false;
}

/*
    函数名字：run_list
    函数功能：简单地进入列表
    返回值：
        类型：bool
        意义：是否退出循环回调
    参数：
        param
        类型：void*
        作用：指向一个 list 结构体，用来确定进入哪个列表
*///
bool run_list(void* param){

    static display_info LIST_INFO;
    static list *LIST;
    LIST = (list*)param;
    
    if(set_list_cursor( LIST ))return true;
    LIST_INFO = list_to_display_info( LIST );
    set_display_info( &LIST_INFO );
    return false;
}

/*
    函数名字：do_nothing
    函数功能：菜单的回调函数,防止报空指针填的选项
    返回值：没有
    参数：没有
*///
bool do_nothing( void* do_nothing ){
    return true;
}
