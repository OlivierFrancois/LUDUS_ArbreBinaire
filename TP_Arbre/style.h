#ifndef STYLE_H_INCLUDED
#define STYLE_H_INCLUDED

#include <windows.h>

enum Color
{
	color_Black = 0,
	color_DarkBlue = 1,
	color_DarkGreen = 2,
	color_DarkCyan = 3,
	color_DarkRed = 4,
	color_DarkMagenta = 5,
	color_DarkYellow = 6,
	color_Gray = 7,
	color_DarkGray = 8,
	color_Blue = 9,
	color_Green = 10,
	color_Cyan = 11,
	color_Red = 12,
	color_Magenta = 13,
	color_Yellow = 14,
	color_White = 15
};

extern void ChangeColor(int text,int bg);

#endif // STYLE_H_INCLUDED
