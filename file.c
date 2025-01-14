#include "file.h" 


void initFile(T_File *ptrF) //mettre Tete et Queue à -1
{
    ptrF->Tete=-1;
    ptrF->Queue=-1;
}

int  retirer(T_File *ptrF,T_Elt *ptrE) //si pas vide, en tete de file
{
if (fileVide(ptrF))
    {
    return 0;
    }
    affecterElt(ptrE, &(ptrF->Elts[ptrF->Tete]));
        ptrF->Tete++;
    if (ptrF->Tete==MAX)
        ptrF->Tete=0;
return 1;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if (filePleine(ptrF)){
    return 0;
    }
        if (ptrF->Queue==-1)
        ptrF->Tete=0;

    ptrF->Queue++;
    if (ptrF->Queue==MAX)
        ptrF->Queue=0;
    ptrF->Elts[ptrF->Queue]=*ptrE;


return 1;
} 

int fileVide(const  T_File *prtF) // qd Tete == 0 
{
    if (prtF->Queue==prtF->Tete)  
    return 1;
return 0;
}

int filePleine(const  T_File *ptrF) // qd MAX elts dans la file 
{
    if (abs(ptrF->Queue+1)%MAX==ptrF->Tete)
            return 1;
    return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
return  ptrF->Elts[ptrF->Tete];
}

void afficherFile(T_File *ptrF)
{
    int i; 
    i= ptrF->Tete;
    while(i!= ptrF->Queue)
    {
        afficherElt(&(ptrF->Elts[i]));
        i=(i+1)%MAX;
        if (i==MAX )
            if(MAX!=ptrF->Queue+1) 
                i=0;
    }
    afficherElt(&(ptrF->Elts[i]));
}






