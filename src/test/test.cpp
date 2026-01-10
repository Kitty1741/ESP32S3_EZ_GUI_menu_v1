#include <menu_API.h>

#include "image.h"

display_info loading;

void test_init(){
    Serial.println("test");
    link_info( &MAIN_MENU_INFO , &image_info );
    link_info( &MAIN_MENU_INFO , &cat1_info );
    loading.mode = DISPLAY_MODE_LOADING;
}
INIT(test);