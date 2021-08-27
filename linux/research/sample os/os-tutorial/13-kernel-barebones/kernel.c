static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 24;
static const char COLOR_BLACK = 0;
static const char COLOR_BLUE = 1;
static const char COLOR_GREEN = 2;
static const char COLOR_CYAN = 3;
static const char COLOR_RED = 4;
static const char COLOR_MAGENTA = 5;
static const char COLOR_BROWN = 6;
static const char COLOR_LIGHT_GREY = 7;
static const char COLOR_DARK_GREY = 8;
static const char COLOR_LIGHT_BLUE = 9;
static const char COLOR_LIGHT_GREEN = 10;
static const char COLOR_LIGHT_CYAN = 11;
static const char COLOR_LIGHT_RED = 12;
static const char COLOR_LIGHT_MAGENTA = 13;
static const char COLOR_LIGHT_BROWN = 14;
static const char COLOR_WHITE = 15;

char make_color(char fg, char bg);
short make_vgaentry(char c, char color);
void putchar(short* video_memory, char c, char color, int x, int y);
void clrscr(short* video_memory);

void main() {
    short* video_memory = (short*) 0xb8000;
	clrscr(video_memory);
	char *str="Welcome to 32-bit protected mode";
	putchar(video_memory,'W',make_color(COLOR_GREEN,COLOR_BLUE),0,0);
	putchar(video_memory,'e',make_color(COLOR_GREEN,COLOR_BLUE),1,0);
}

void clrscr(short* video_memory)
{
	int x,y;
	for (y = 0; y < VGA_HEIGHT; y++ ){
		for (x = 0; x < VGA_WIDTH; x++ ){
			const int index = y * VGA_WIDTH + x;
			video_memory[index] = make_vgaentry(' ', make_color(COLOR_WHITE,COLOR_BLACK));
		}
	}
}

char make_color(char fg, char bg)
{
	return fg | bg << 4;
}

short make_vgaentry(char c, char color)
{
	short c16 = c;
	short color16 = color;
	return c16 | color16 << 8;
}

void putchar(short* video_memory, char c, char color, int x, int y)
{
	const int index = y * VGA_WIDTH + x;
	video_memory[index] = make_vgaentry(c, color);
} 
