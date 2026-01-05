//这里有各种编译时的设置
//调整以适配你的功能


//菜单必须的四个键值的设置
//依次对应四个功能
#define KEY_NULL_VALUE 0
#define KEY_UP_NUM_VALUE 1
#define KEY_OK_NUM_VALUE 2
#define KEY_DOWN_NUM_VALUE 3
#define KEY_BACK_NUM_VALUE 4


//中断扫描键盘的定时器选择
//可选 0 1 2 3 4     5  
//    ~~~~~~~~ ↑     ↑
//   硬件定时器 软件 不定时，你来操作
//
//默认用硬件定时器(2)
#define use_which_timer 2


//创建u8g2对象的SSD1306的IO接口
//只能选硬件IIC的接口
#define u8g2_SCL 9
#define u8g2_SDA 8