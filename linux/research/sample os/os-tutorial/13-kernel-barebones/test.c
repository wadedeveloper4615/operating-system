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
void make_putchar(short* video_memory, char c, char color, int x, int y);
void clrscr(short* video_memory);

int start(void)
{
    short* video_memory = (short*) 0xb8000;
	clrscr(video_memory);
	make_putchar(video_memory,'W',make_color(COLOR_GREEN,COLOR_BLUE),0,0);
/*	
	make_putchar(video_memory,'e',make_color(COLOR_GREEN,COLOR_BLUE),1,0);
	make_putchar(video_memory,'l',make_color(COLOR_GREEN,COLOR_BLUE),2,0);
	make_putchar(video_memory,'c',make_color(COLOR_GREEN,COLOR_BLUE),3,0);
	make_putchar(video_memory,'o',make_color(COLOR_GREEN,COLOR_BLUE),4,0);
	make_putchar(video_memory,'m',make_color(COLOR_GREEN,COLOR_BLUE),5,0);
	make_putchar(video_memory,'e',make_color(COLOR_GREEN,COLOR_BLUE),6,0);
	make_putchar(video_memory,'t',make_color(COLOR_GREEN,COLOR_BLUE),8,0);
	make_putchar(video_memory,'o',make_color(COLOR_GREEN,COLOR_BLUE),9,0);
	make_putchar(video_memory,'3',make_color(COLOR_GREEN,COLOR_BLUE),11,0);
	make_putchar(video_memory,'2',make_color(COLOR_GREEN,COLOR_BLUE),12,0);
*/	
    mylabel: goto mylabel;
}

void clrscr(short* video_memory)
{
	int x,y;
	for (y = 0; y < VGA_HEIGHT; y++ ){
		for (x = 0; x < VGA_WIDTH; x++ ){
			const int index = y * VGA_WIDTH + x;
			video_memory[index] = make_vgaentry(' ', make_color(COLOR_GREEN,COLOR_BLUE));
		}
	}
}

short make_vgaentry(char c, char color)
{
	char c16 = c;
	char color16 = color;
	return c16 | color16 << 8;
}

char make_color(char fg, char bg)
{
	return fg | bg << 4;
}

void make_putchar(short* video_memory, char c, char color, int x, int y)
{
	const int index = y * VGA_WIDTH + x;
	video_memory[index] = make_vgaentry(c, color);
} 
