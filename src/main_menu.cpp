#include <menu_API.h>
#include <WLAN/WLAN.h>

//这个文件专门用来定义主菜单


// 13x13 爱心图像数据（高位优先格式）
static uint8_t heart_data[26] = {
    0x18, 0xC0,0x3D, 0xE0,
    0x7F, 0xF0,0xFF, 0xF8,
    0xFF, 0xF8,0xFF, 0xF8,
    0x7F, 0xF0,0x3F, 0xE0,
    0x1F, 0xC0,0x0F, 0x80,
    0x07, 0x00,0x02, 0x00,
    0x00, 0x00
};
// 创建爱心图像结构
image heart_image = {
    .width = 13,
    .height = 13,
    .image_data = heart_data
};
display_info image_info = image_to_display_info(&heart_image,80,30);
/*菜单选项格式如下*/
/*选项名(数组)*///*回调函数*///*传入参数(没有可以不写)*/
//主菜单选项列表
option MAIN_MENU_LIST[] = {
    {"WLAN",run_menu,&WLAN_MENU},
    {"test",do_nothing},
    {"中文测试",do_nothing},
    {"回调函数-菜单测试",run_info_data,NULL},
    {"多行测试",do_nothing},
    {"多行测试",do_nothing},
};
//主菜单
menu MAIN_MENU = {
    /*标题*/.name = "主菜单",
    /*长度*/.length = sizeof(MAIN_MENU_LIST)/sizeof(MAIN_MENU_LIST[0]),
    /*选项列表*/.menu_list = MAIN_MENU_LIST,
};

//对应显示包
display_info MAIN_MENU_INFO = menu_to_display_info( &MAIN_MENU );

void test(){
    MAIN_MENU_INFO.next = &image_info;
}