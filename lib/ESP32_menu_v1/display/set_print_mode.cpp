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

/*
    函数名字：rotate_image
    函数功能：顺时针旋转指向的图片90° n次
    返回值：没有
    参数：
        IMAGE
        类型：image*
        作用：传递要打印的图片信息
        n
        类型：uint8_t
        作用：设转动几次
*///
void rotate_image(image* IMAGE, uint8_t n) {
    n %= 4;  // 旋转4次等于原图
    if (n == 0) return;

    const uint8_t width = IMAGE->width;
    const uint8_t height = IMAGE->height;
    const uint8_t bytes_per_line = (width + 7) / 8;

    // 计算旋转后的尺寸
    uint8_t new_width = height;
    uint8_t new_height = width;
    uint8_t new_bytes_per_line = (new_width + 7) / 8;

    // 分配新图像数据
    uint8_t new_data[1024]; // 1024字节栈缓冲区（128*64/8=1024）

    // 旋转 n 次 (每次90度)
    for (uint8_t i = 0; i < n; i++) {
        // 逐像素旋转 (顺时针90度)
        for (uint8_t y = 0; y < new_height; y++) {  // 新图行
            for (uint8_t x = 0; x < new_width; x++) {  // 新图列
                // 计算原图对应位置 (原图行 = new_height - 1 - y, 原图列 = x)
                uint8_t orig_row = new_height - 1 - y;
                uint8_t orig_col = x;
                
                // 从原图获取位
                uint8_t byte_idx = orig_row * bytes_per_line + (orig_col / 8);
                uint8_t bit_pos = 7 - (orig_col % 8);  // 高位在左
                bool bit = (IMAGE->image_data[byte_idx] >> bit_pos) & 1;
                
                // 写入新图 (新图行 = y, 新图列 = x)
                byte_idx = y * new_bytes_per_line + (x / 8);
                bit_pos = 7 - (x % 8);
                if (bit) {
                    new_data[byte_idx] |= (1 << bit_pos);
                } else {
                    new_data[byte_idx] &= ~(1 << bit_pos);
                }
            }
        }

        // 更新尺寸和字节数 (为下一次旋转准备)
        uint8_t temp = new_width;
        new_width = new_height;
        new_height = temp;
        new_bytes_per_line = (new_width + 7) / 8;
    }

    // 释放原图像数据
    free(IMAGE->image_data);
    
    // 更新图像结构
    IMAGE->image_data = new_data;
    IMAGE->width = new_width;
    IMAGE->height = new_height;
}
