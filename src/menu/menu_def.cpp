#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <global.h>
#include <menu\menu.h>
//这个文件专门用来定义菜单
//主菜单选项列表
static option MAIN_MENU_LIST[] = {

    {"测试01",setup},
    {"测试02",setup},
    {"测试03",setup},
    {"测试04",setup},
    {"测试05",setup},
    {"测试06",setup},

};
//主菜单
static menu MAIN_MENU = {

    "主菜单",
    sizeof(MAIN_MENU_LIST)/sizeof(MAIN_MENU_LIST[0]),
    MAIN_MENU_LIST,

};