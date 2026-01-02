#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <global.h>
#include <menu\menu.h>
#include <keybord\keybord.h>

static bool if_first_setup = false;

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE ,/*SCL*/9,/*SDA*/8);

void setup() {

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

    //keybord_init
    keybord_setup();
  }

  //重置u8g2设置
  u8g2.setFont(u8g2_font_ncenB08_tr);  // 设置字体:cite[5]
  u8g2.setFont(u8g2_font_wqy12_t_gb2312); // 设置文泉驿点阵宋体12px:cite[2]
}

void loop() {

  

}
