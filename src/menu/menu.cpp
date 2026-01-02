#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <global.h>
#include <menu\menu.h>

/*
    函数名字：set_menu
    函数功能：根据接口里的keybord_status值，设置菜单显示
    返回值：没有
    参数：
        MENU
        类型：menu
        作用：告诉函数应该打印哪个菜单
*///
void set_menu(  ){

}




/*
    函数名字：print_menu
    函数功能：打印给定菜单到u8g2上
    返回值：没有
    参数：
        MENU
        类型：menu
        作用：告诉函数应该打印哪个菜单
*///
void print_menu( menu MENU ){

    static unsigned char cursor_line = 0;//光标所在位置
    unsigned char view_line = 0;//显示的第一行

    //通过光标计算屏幕所在行
    if( MENU.length < 4 ){
      view_line = 0;
    }else{
      cursor_line == 0                ? view_line = 0 :
      cursor_line == MENU.length -2   ? view_line = cursor_line -2 :
      cursor_line == MENU.length -1   ? view_line = cursor_line -3 :
      /*default*/view_line = cursor_line -1;
    }

    //显示到U8G2
    u8g2.clearBuffer();

    u8g2.drawUTF8(3 ,3 , MENU.name );//画菜单名字
    u8g2.drawFrame(0, 1, 128, 16); //画空心矩形

    for(int i=0; i<4; i++){
      if( i <= MENU.length -1 ){
        u8g2.drawUTF8(4 ,18+12*i , MENU.list[ i + view_line ].name );//打印选项名字
    }} 
    
    u8g2.drawBox( 0 , ( cursor_line - view_line )*12 +17 , 80 , 12 ); //打印光标
    u8g2.drawBox( 126 , ( cursor_line / 1.0 / MENU.length )*47+17 , 2 , 8 ); //打印位置指示器

    u8g2.sendBuffer();

    return;
}