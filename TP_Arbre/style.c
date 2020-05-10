#include "style.h"

void ChangeColor(int text,int bg)
//BUT : changer la couleur d'écriture dans la console.
//ENTREE : text : texte, bg : fond
/*0 : noir 1 : bleu foncé - 2 : vert - 3 : bleu-gris - 4 : marron - 5 : pourpre - 6 : kaki - 7 : gris clair
8 : gris - 9 : bleu - 10 : vert fluo - 11 : turquoise - 12 : rouge - 13 : rose fluo - 14 : jaune fluo - 15 : blanc*/
{
	HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(H, bg * 16 + text);
}