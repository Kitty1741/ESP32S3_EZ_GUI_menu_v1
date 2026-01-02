#ifndef __MENU_H__
#define __MENU_H__

//声明u8g2类
extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;
//声明主菜单，这个loop()要用
extern menu MAIN_MENU;
//定义菜单/显示所需要的结构

//函数参数共用体(还没搞)

//菜单选项结构体
typedef struct option_t{

    char name[40];
    void (*fun)();

}option;

//菜单结构体
typedef struct menu_t{

    char *name;//菜单的名字
    int length;//菜单的列表长度
    option *list;//菜单对应的列表

}menu;

//函数
void show_logo();

#endif