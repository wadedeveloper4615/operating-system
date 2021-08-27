#include <stdint.h>
#include <screen.h>
#include <ports.h>
#include <mem.h>
#include <string.h>
#include <io.h>

uint16_t *video_memory;
uint8_t currentColor;
uint8_t currentX;
uint8_t currentY;


int get_offset(int col, int row) { 
    return 2 * (row * VGA_WIDTH + col); 
}

int get_cursor_offset() {
    port_byte_out(REG_SCREEN_CTRL, 14);
    int offset = port_byte_in(REG_SCREEN_DATA) << 8; /* High byte: << 8 */
    port_byte_out(REG_SCREEN_CTRL, 15);
    offset += port_byte_in(REG_SCREEN_DATA);
    return offset * 2; /* Position * size of character cell */
}

void set_cursor_offset(int offset) {
    offset /= 2;
    port_byte_out(REG_SCREEN_CTRL, 14);
    port_byte_out(REG_SCREEN_DATA, (uint8_t)(offset >> 8));
    port_byte_out(REG_SCREEN_CTRL, 15);
    port_byte_out(REG_SCREEN_DATA, (uint8_t)(offset & 0xff));
}

char make_color(char fg, char bg) {
  return fg | bg << 4;
}

short make_vgaentry(char c, char color) {
  short c16 = c;
  short color16 = color;
  return c16 | color16 << 8;
}

void InitializeVideo(){
  video_memory = (uint16_t *) VIDEO_ADDRESS;
  currentColor = make_color(COLOR_WHITE,COLOR_BLACK);
  currentX=0;
  currentY=0;
}

int putc(char c) {
    if (c =='\n'){
        currentX=0;
        currentY++;
    } else {
        const int index = currentY * VGA_WIDTH + currentX;
        video_memory[index] = make_vgaentry(c, currentColor);
        currentX++;
    }
    set_cursor_offset(get_offset(currentX, currentY));
}

int kprint(char * str){
    for(int i=0;i<strlen(str);i++){
       putc(str[i]);
    }
}

void clrscr() {
  for (int y = 0; y < VGA_HEIGHT; y++) {
    for (int x = 0; x < VGA_WIDTH; x++) {
      const int index = y * VGA_WIDTH + x;
      video_memory[index] = make_vgaentry(' ', currentColor);
    }
  }
  set_cursor_offset(get_offset(0, 0));
}
