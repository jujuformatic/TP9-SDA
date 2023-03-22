// SDA1 TP 9 PILE de TAD (PILE d'ELEMENT)

#include "pile.h"
#include "file.h"

#define passerAuPremierFils(adrP, E) empiler(adrP, E)
#define remonterAuPere(adrP, trash) depiler(adrP, trash)
#define passerAuFrereSuivant(adrP, adrE) depiler(adrP, adrE), empiler(adrP, 1 + (*adrE))
#define naPlusDeFrere(adrP, TailleChaine) sommet(adrP) == TailleChaine
#define noeudTerminal(adrP, TailleChaine) hauteur(adrP) == TailleChaine
#define rechercheTerminee(adrP) !pilevide(adrP)

void testFile(T_File *fi);
void testPile(T_Pile *fi);

int permut(T_Pile* adrP, char* string);
int pileValide(T_Pile *adrP);
int chaineValide(char* string);

int menu();

int main()
{
	T_File mafile;
	T_Pile mapile;
	int chx;
	// int taille;
	char chaine[10];

	do
	{
		chx = menu();
		switch (chx)
		{
		case 1:
			testPile(&mapile);
			break;
		case 2:				   
			testFile(&mafile);
			break;
		case 3:
			printf("Rentrez une chaine de départ: ");
			scanf("%s",chaine); //une chaine de longueur <=MAX
			printf("%d Solutions trouvées\n", permut(&mapile,chaine));
			break;
		case 4:
			// scanf("%d",&taille);//taille echiquier <=MAX
			// echiquier(&mapile,taille); //TP9 partie 3: ecrire echiquier
			break;
		}
	} while (chx != 0);

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
	printf("affichage file ");
	afficherFile(fi);
	if (filePleine(fi))
		printf(" \n file pleine");
	printf("  \n défiler");
	retirer(fi,&x);
	afficherElt(&x);
	if (filePleine(fi))
		printf(" \n file pleine \n");
	if (fileVide(fi))
		printf(" \n file non pleine \n");
	printf(" \n défiler");
	retirer(fi,&x);
	afficherElt(&x);
	printf("\najout\n");
	saisirElt(&x);
	ajouter(fi,&x);
	printf("\najout\n");
	saisirElt(&x);
	ajouter(fi,&x);
	printf("affichage");
	afficherFile(fi);
	if (filePleine(fi))
		printf(" \n file pleine \n");
}

void testPile(T_Pile *pile)
{
	T_Elt x;
	int i;

	initPile(pile);
	if (pilevide(pile))
		printf("Pile vide \n");

	for (i = 0; i < 10; i++)
	{
		saisirElt(&x);
		empiler(pile, x);
	}
	printf("\nPile saisie:");
	afficherPile(pile);
	if (pilepleine(pile))
		printf(" \nPile pleine");
	else
		printf("\nPile non pleine \n");

	printf("\nDernier élément dépilé:");
	depiler(pile, &x);
	afficherElt(&x);
	if (pilepleine(pile))
		printf(" \nPile pleine \n");
	else
		printf("\nPile non pleine \n");

	printf("\nSommet de la pile:");
	x = sommet(pile);
	afficherElt(&x);
	printf("\nHauteur de la pile: %d", hauteur(pile));
}

int permut(T_Pile *adrP, char* chaine){
	int i=0;
	int tailleChaine;
	int permutations=0;
	char premiereLettre;
	T_Elt trash;

	//T_Elt eltTab[MAX];

	if(strcmp("", chaine)==0) return 0;

	premiereLettre=chaine[0];

	while(chaine[i]!='\0'){
		//elt=chaine[i];
		//eltTab[i]=elt;
		i++;
	}
	tailleChaine=i;

	initPile(adrP);

	do{
		while (pileValide(adrP))
		{
			if(noeudTerminal(adrP, tailleChaine)){
				permutations++;
				for(i=0; i<adrP->nbElts; i++){
					printf("%c",adrP->Elts[i]+premiereLettre-1);
				}
				printf("\n");
				break;
			} else{
				passerAuPremierFils(adrP, 1);
			}
		}
		while (rechercheTerminee(adrP) && naPlusDeFrere(adrP, tailleChaine))
		{
			remonterAuPere(adrP, &trash);
		}
		if(rechercheTerminee(adrP)){
			passerAuFrereSuivant(adrP, &trash);
		}
	} while (rechercheTerminee(adrP));
	return permutations;
}

int pileValide(T_Pile *adrP)
{
	int i,j;
	T_Elt elt;

	if (pilevide(adrP))
		return 1;

	for (i = 0; i < adrP->nbElts-1; i++)
	{
		for (j = i+1; j < adrP->nbElts; j++)
		{
			if(adrP->Elts[i]==adrP->Elts[j])return 0;
		}
	}
	return 1;
}

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
	scanf("%d", &choix);
	return choix;
}
