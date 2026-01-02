#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <global.h>
#include <menu\menu.h>
#include <setting.h>

//这个文件专门用来写一些杂项函数
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE , u8g2_SCL , u8g2_SDA );

/*
    函数名字：menu_init
    函数功能：初始化所有和u8g2有关的东西
    返回值：没有
    参数：没有
*///
void menu_init(){

    static bool if_first_setup = false;

    //如果是第一次初始化
    if( if_first_setup == false ){
        if_first_setup =  true;
        //u8g2执行初始化
        u8g2.begin();

        //u8g2初始设置
        u8g2.enableUTF8Print();    // 启用UTF-8支持，用于显示中文:cite[2]
        u8g2.setFont(u8g2_font_ncenB08_tr);  // 设置字体:cite[5]
        u8g2.setFont(u8g2_font_wqy12_t_gb2312); // 设置文泉驿点阵宋体12px:cite[2]
        u8g2.setFontPosTop();      // 设置字体绘制基准为顶部（默认为基线）

    }

    //重置u8g2设置
    u8g2.setFont(u8g2_font_ncenB08_tr);  // 设置字体:cite[5]
    u8g2.setFont(u8g2_font_wqy12_t_gb2312); // 设置文泉驿点阵宋体12px:cite[2]s
    u8g2.setDrawColor(2); //设置颜色,0透显,1实显,2XOR (drawCircle,drawDisc,drawEllipse和drawFilledEllipse不支持XOR模式) 

}

/*
    函数名字：image_to_display_info
    函数功能：把128x64的char图片数组塞进一个display_info类型的结构里
    返回值：
        类型：display_info
        意义：返回需要渲染的图片
    参数：
        IMAGE
        类型：char[1024]
        作用：传输需要打印的图片
*///
display_info image_to_display_info( char *IMAGE[1024] ){

    display_info image_info;
    image_info.mode = DISPLAY_MODE_IMAGE;//图片打印模式
    strcpy(image_info.data.img->image_data , *IMAGE );//给display_info赋值
    return image_info;
}