set(COMPONENT_SRCS
  chessengine.c
  u8g_arm.c
  u8g_bitmap.c
  u8g_circle.c
  u8g_circle.c
  u8g_clip.c
  u8g_com_api.c
  u8g_com_api_16gr.c
  u8g_com_i2c.c
  u8g_com_io.c
  u8g_com_msp430_hw_spi.c
  u8g_com_null.c
  u8g_com_raspberrypi_hw_spi.c
  u8g_com_raspberrypi_ssd_i2c.c
  u8g_com_std_sw_spi.c
  u8g_cursor.c
  u8g_delay.c
  u8g_dev_ssd1306_64x48.c
  u8g_dev_ssd1306_128x32.c
  u8g_dev_ssd1306_128x64.c
  u8g_ellipse.c
  u8g_font.c
  u8g_font_data.c
  u8g_line.c
  u8g_ll_api.c
  u8g_page.c
  u8g_pb.c
  u8g_pb14v1.c
  u8g_pb16h1.c
  u8g_pb16h2.c
  u8g_pb16v1.c
  u8g_pb16v2.c
  u8g_pb32h1.c
  u8g_pb8h1.c
  u8g_pb8h1f.c
  u8g_pb8h2.c
  u8g_pb8h8.c
  u8g_pb8v1.c
  u8g_pb8v2.c
  u8g_pbxh16.c
  u8g_pbxh24.c
  u8g_polygon.c
  u8g_rect.c
  u8g_rot.c
  u8g_scale.c
  u8g_state.c
  u8g_u16toa.c
  u8g_u8toa.c
  u8g_virtual_screen.c
  )

set(COMPONENT_ADD_INCLUDEDIRS
  .
#  driver/include
#  conversions/include
  )

#set(COMPONENT_PRIV_INCLUDEDIRS
#  driver/private_include
#  sensors/private_include
#  conversions/private_include
#  )

set(COMPONENT_REQUIRES driver freertos)
#set(COMPONENT_PRIV_REQUIRES freertos nvs_flash)

register_component()
