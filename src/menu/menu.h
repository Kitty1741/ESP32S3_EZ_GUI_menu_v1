#ifndef __MENU_H__
#define __MENU_H__

#include <U8g2lib.h>
#include <Wire.h>
#include <global.h>

//声明u8g2类
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;

//定义菜单/显示所需要的结构

//函数参数共用体(还没搞)

//菜单选项结构体
typedef struct option_t{

    char name[40];
    void (*fun)();

}option;

//菜单结构体
typedef struct menu_t{

    const char *name;//菜单的名字
    int length;//菜单的列表长度
    unsigned char cursor;//菜单的光标位置
    option *list;//菜单对应的列表

}menu;

//声明主菜单，这个loop()要用
extern menu MAIN_MENU;

//对外声明函数
void menu_init();
display_info image_to_display_info( char *IMAGE[1024] );
bool set_cursor( menu *MENU );
//测试test
void test_loop();

#endif