// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"

void testFile(T_File *fi);
void testPile(T_Pile *fi);

int menu()
{

int choix;
printf("\n\n\n SDA1 TP9");
printf("\n\n\n 1 : tester mon fichier Pile.c");
printf("\n 2 : tester mon fichier File.c");
printf("\n 3 : afficher et compter les permutations d'une chaine");
printf("\n 4 : afficher et compter les solutions pour un échiquier ");
printf("\n 0 :  QUITTER  ");
printf("\n votre choix ?  ");
scanf("%d",&choix);
return choix;
}

int main()
{
T_File mafile;
T_Pile mapile;
int chx;
// int taille;
//char chaine[20];

do
{
chx=menu();
switch (chx)
	{
	case 1 :  
		//testPile(&mapile); //TP9 partie 1 : à ecrire 
		testPile(&mapile);
		break;
	case 2 : //testez toutes vos fonctions par un jeu de test de votre choix
		testFile(&mafile); //TP9 partie 1 : à ecrire 
		break; 
	case 3 : 
		//scanf("%s",chaine); //une chaine de longueur <=MAX
		//permut(&mapile,chaine); //TP9 partie 2: ecrire permut
		break;
	case 4 : 
		//scanf("%d",&taille);//taille echiquier <=MAX
		//echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
		break;



	}
}while(chx!=0);

printf("\nau plaisir de vous revoir ...\n");
return 0;
}

void testFile(T_File *fi){
	T_Elt x;
	int i;
	initFile( fi);
	if (fileVide(fi))
		printf("file vide \n");
	for(i=0;i<10;i++)
	{
		saisirElt(&x);
		ajouter(fi,&x);
	}
	afficherFile(fi);
	if (filePleine(fi))
		printf(" \n file pleine");
	retirer(fi,&x);
	afficherElt(&x);
	if (filePleine(fi))
		printf(" \n file pleine \n");
	else
		printf("file non pleine \n");
}

void testPile(T_Pile *pile){
	T_Elt x;
	int i;

	initPile(pile);
	if (pilevide(pile)) printf("Pile vide \n");

	for(i=0;i<10;i++)
	{
		saisirElt(&x);
		empiler(pile,x);
	}
	printf("\nPile saisie:");
	afficherPile(pile);

	if (pilepleine(pile)) printf(" \nPile pleine");
	else printf("\nPile non pleine \n");

	printf("\nDernier élément dépilé:");
	depiler(pile,&x);
	afficherElt(&x);
	if (pilepleine(pile)) printf(" \nPile pleine \n");
	else printf("\nPile non pleine \n");

	printf("\nSommet de la pile:");
	x=sommet(pile);
	afficherElt(&x);
	printf("\nHauteur de la pile: %d", hauteur(pile));
}