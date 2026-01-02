#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <global.h>
#include <menu\menu.h>
#include <menu\u8g2_print.h>

extern menu MAIN_MENU;

//测试函数，检测这玩意能不能跑
void test_loop(){
    static display_info TEST = {
        DISPLAY_MODE_MENU,//输出内容的类型
        .data = { .menu_data = &MAIN_MENU },//内含一个和类型对应的数据的指针
        0,0,
        NULL,//链表结构，方便叠加图层
    };
    TEST.data.menu_data = &MAIN_MENU;
    set_cursor( TEST.data.menu_data );
    u8g2_print_display_info( &TEST );
}