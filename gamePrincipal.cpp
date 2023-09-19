#include <iostream>
#include "declarationFonction.h"
#include "Constante.h"

using namespace std;


// Execute le jeu
void game()
{
	char monMots[MAX_TABLEAU]; // Incremente le mot dans mon tableau
	choixMots(monMots);
	bodyGame(monMots);
}