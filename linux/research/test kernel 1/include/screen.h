#ifndef SCREEN_H
#define SCREEN_H

#define VIDEO_ADDRESS 0xB8000
#define VGA_HEIGHT 25
#define VGA_WIDTH  80
#define WHITE_ON_BLACK 0x0f
#define RED_ON_WHITE 0xf4

#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

enum {
 COLOR_BLACK,
 COLOR_BLUE,
 COLOR_GREEN,
 COLOR_CYAN,
 COLOR_RED,
 COLOR_MAGENTA,
 COLOR_BROWN,
 COLOR_LIGHT_GREY,
 COLOR_DARK_GREY,
 COLOR_LIGHT_BLUE,
 COLOR_LIGHT_GREEN,
 COLOR_LIGHT_CYAN,
 COLOR_LIGHT_RED,
 COLOR_LIGHT_MAGENTA,
 COLOR_LIGHT_BROWN,
 COLOR_WHITE
};

void InitializeVideo(void);
int kprint(char * str);
int putc(char c);
int get_offset(int col, int row);
int get_offset_row(int offset);
int get_offset_col(int offset);
int get_cursor_offset();
void set_cursor_offset(int offset);
void clrscr();
char make_color(char fg, char bg);
short make_vgaentry(char c, char color);

#endif
