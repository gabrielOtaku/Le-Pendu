#include <iostream>
#include "declarationFonction.h"
#include "Constante.h"

using namespace std;
extern void ClearScreen();
extern void Tapping(const char data[], int speed);

char memoireMot[50]; // Max de lettre prise en memoire 


//Lance l'intro du jeu
void intro(char monMots[])
{
	Tapping("Ooooooooh mon reuf bien ou bien ? Ca fait grave longtemps que l'on ne sait pas vu. \n"
		"Bon la je t'explique en deux, deux, tu es dans le jeu du pendu. \n"
		"Les mots seront cache et affiche de facon aleatoire. \n"
		"Ton but ? trouver le mot mystere en un nombre limite d'essaye.\n"
		"Attention! Il peut y avoir plusieurs majuscule dans un meme mots\n"
		"Bonne chance mon reuf.\n\n", 5);

	system("pause");
	ClearScreen();

	startGame(monMots);

}

//Demande au joueur si il veut lancer la partie
void startGame(char monMots[])
{
	int monChoix(0);

	Tapping("Voulez-vous commmencer la partie ? :\n\n"
		"1/ oui vas-y grave chaud \n2/ non nique sa m*re je me casse, flemme de fou \n\n", 5);
	cin >> monChoix;

	system("pause");
	ClearScreen();

	while (monChoix != 1 && monChoix != 2)
	{
		Tapping("Voulez-vous commmencer la partie ? :\n\n"
			"1/ oui vas-y grave chaud \n2/ non nique sa m*re je me casse, flemme de fou \n\n", 5);
		cin >> monChoix;

		system("pause");
		ClearScreen();
	}
	switch (monChoix)
	{
	case 1:
		game();
	case 2:
		exit(0);

	default:
		startGame(monMots);
		break;
	}
}

//Corps du jeu 
void bodyGame(char monMots[])
{
	int life(MAX_PV);
	bool finPartie = false;
	int tailleEmma = 0; // Juste pour la tailler LOL
	char lettreUtiliser[MAX_TABLEAU] = { ' ' }; // Enregistre les lettres deja utilise
	char lettreJoueur[1]; // Enregistre les lettres fournis par le joueur
	int monErreur = 0; // Pour verifier les erreurs


	tailleEmma = strlen(monMots); // Calcul automatiquement la taille du mot 

	while (finPartie == false)
	{
		Tapping("Le mot mystere : \n\n", 5);
		for (int i = 0; i < tailleEmma; i++)
		{
			if (memoireMot[i] != monMots[i])
			{
				cout << CHARA_AFFICHAGE_NEUTRE;
			}
			else
			{
				cout << memoireMot[i];
			}
		}
		Tapping("\n\n", 5);
		Tapping("Il te reste :\t", 5);
		cout << life;
		Tapping("PV\n\n", 5);

		Tapping(" Voici les lettres que tu as deja utiliser : \t", 5);
		cout << lettreUtiliser << endl;

		Tapping("Quel lettre veux tu essayer : \t", 5);
		cin >> lettreJoueur;

		strncat_s(lettreUtiliser, lettreJoueur, 1); //Prend en compte les lettres inscrits  
		monErreur = 0; // Reviens a 0

		for (int i = 0; i < tailleEmma; i++)
		{
			if (*lettreJoueur == monMots[i])
			{
				memoireMot[i] = monMots[i];
			}
			else
			{
				monErreur++;
			}
		}
		if (monErreur == tailleEmma)
		{
			life--;
		}
		system("pause");
		ClearScreen();

		if (life <= 0)
		{
			endGame();
		}
		if (strcmp(monMots, memoireMot) == 0)
		{
			finPartie = true;

			Tapping("Bien jouer vous avez gagner \n\n", 5);

			endGame();
		}
	}
}

// Choix de relancer une partie 
void endGame()
{
	int finJeu(0);

	if (MAX_PV <= 0)
	{
		Tapping("Bon mon gars, t'as perdu donc DEEEEHHHOOOORRRS !!!", 5);

		system("pause");
		ClearScreen();

		Tapping("Bon je vois que tu as la mort d'avoir perdu.\nEst-ce que tu veux recommencer une partie?\n\n"
			"1/ ouais vas-y j'ai rien d'autre a faire \n2/ Non, flemme et je m'en caliss la rondelle.", 5);
		cin >> finJeu;

		system("pause");
		ClearScreen();
	}

	while (finJeu != 1 && finJeu != 2)
	{
		Tapping("CHOISI SINON JE TE DETRUIT !\n\n"
			"Bon je vois que tu as la mort d'avoir perdu.\nEst-ce que tu veux recommencer une partie?\n\n"
			"1/ ouais vas-y j'ai rien d'autre a faire \n2/ Non, flemme et je m'en caliss la rondelle.", 5);
		cin >> finJeu;
	}

	switch (finJeu)
	{
	case 1:
		game();
		break;

	case 2:
		exit(0);

	default:

		exit(0);
	}

}

void taGagner(char monMots[]) {
	Tapping("Felicitation, vous avez trouve le mot et sauve votre ami! Le mot etait bien : \t", 5);
	cout << monMots << endl;
	endGame();

	system("pause");
}
