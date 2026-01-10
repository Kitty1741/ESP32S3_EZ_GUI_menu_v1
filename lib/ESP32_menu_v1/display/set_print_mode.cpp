#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <global.h>
#include <menu/internal.h>//内部模块
#include <display/internal.h>//内部模块
#include <display/u8g2_print.h>

//本文件装不直接参与打印的函数

/*
    函数名字：set_black_image_background
    函数功能：设置叠加处理方式（是否涂黑背景/异或显示）
    返回值：没有
    参数：
        INFO
        类型：display_info*
        作用：传递要打印的图片信息
        if_black
        类型：bool
        作用：设置是否黑色背景
    或者：
        IMAGE
        类型：image*
        作用：传递传递要打印的图片信息
        if_black
        类型：bool
        作用：设置是否黑色背景
*/
void set_black_image_background( display_info* INFO , bool if_black ){

    //涂黑背景
    INFO->data.img->if_black_background = if_black;
}
void set_black_image_background( image* IMAGE , bool if_black ){

    //涂黑背景
    IMAGE->if_black_background = if_black;
}