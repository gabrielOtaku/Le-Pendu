#include <iostream>
#include "declarationFonction.h"
#include "Constante.h"
#include <stdlib.h>

using namespace std;


void choixMots(char monMots[])
{

	srand(unsigned(time(NULL)));

	int choixDuMot = rand() % 25 + 1;

	switch (choixDuMot)
	{
	case 1:
		copyTab("ABATLAITNOIXRE", monMots);
		break;

	case 2:
		copyTab("RAPEME", monMots);
		break;

	case 3:
		copyTab("JAIMITLAIR", monMots);
		break;

	case 4:
		copyTab("LESNEZGROSPUE", monMots);
		break;

	case 5:
		copyTab("QUOIFEUR", monMots);
		break;

	case 6:
		copyTab("STEPHDUPUIS", monMots);
		break;

	case 7:
		copyTab("VIVITLAIR", monMots);
		break;

	case 8:
		copyTab("SUSMABEAT", monMots);
		break;

	case 9:
		copyTab("EDWINXCELIA", monMots);
		break;

	case 10:
		copyTab("BASKETBALL", monMots);
		break;

	case 11:
		copyTab("SPAGHETTI", monMots);
		break;

	case 12:
		copyTab("MUSIC", monMots);
		break;

	case 13:
		copyTab("ILOVEPROGRAMMATION", monMots);
		break;

	case 14:
		copyTab("SAINTFELICIEN", monMots);
		break;

	case 15:
		copyTab("MUSCULATION", monMots);
		break;

	case 16:
		copyTab("ALEXESTGAY", monMots);
		break;

	case 17:
		copyTab("JAPON", monMots);
		break;

	case 18:
		copyTab("EMMMAGROSSI", monMots);
		break;

	case 19:
		copyTab("EMMAREUS", monMots);
		break;

	case 20:
		copyTab("EMMATOM", monMots);
		break;

	case 21:
		copyTab("EMMAQUEUE", monMots);
		break;

	case 22:
		copyTab("ONEPIECEISLIFE", monMots);
		break;

	case 23:
		copyTab("JENEMPASLESNHOAHRE", monMots);
		break;

	case 24:
		copyTab("TUNESTPABLO", monMots);
		break;

	case 25:
		copyTab("BRAVO", monMots);
		break;

	}
}

void copyTab(const char ramdom[], char monMots[])
{
	for (int i = 0; i < MAX_TABLEAU; i++)
	{
		monMots[i] = ramdom[i];
	}
}