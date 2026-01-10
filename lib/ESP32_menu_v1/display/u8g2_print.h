#ifndef __U8G2_PRINT_H__
#define __U8G2_PRINT_H__

#include <U8g2lib.h>
#include <Wire.h>

//menu.h
typedef struct option_t option;
typedef struct menu_t menu;

//最常用的那个
void set_display_info( display_info *INFO );

//初始化函数
void menu_init_u8g2();

//模式设置函数
void set_black_image_background( display_info* INFO , bool if_black );
void set_black_image_background( image* IMAGE , bool if_black );
void rotate_image(image* IMAGE, uint8_t n);

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;

#endif