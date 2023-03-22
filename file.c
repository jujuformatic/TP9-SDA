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
    if (ptrF->Tete==MAX-1)
        ptrF->Tete=-1;
    ptrF->Tete++;
    affecterElt(ptrE, &(ptrF->Elts[ptrF->Tete]));
return 1;
}

int ajouter(T_File *ptrF,T_Elt *ptrE) // si espace libre, ajout en queue
{
    if (filePleine(ptrF)){
    return 0;
    }
    if (ptrF->Queue==MAX-1)
        ptrF->Queue=-1;
    ptrF->Queue++;
    affecterElt(&(ptrF->Elts[ptrF->Queue]),ptrE);
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
    if (ptrF->Queue>ptrF->Tete)
    {
        if (ptrF->Queue+ptrF->Tete==8)
            return 1;
        return 0;
    }
    else
    {
        if (ptrF->Tete-ptrF->Queue==1)
        return 1;
    }
    return 0;
}

T_Elt  premier(T_File *ptrF) //valeur en tete de file
{
    if (ptrF->Tete==-1){
        return  ptrF->Elts[ptrF->Tete+1];
    }
return  ptrF->Elts[ptrF->Tete];
}

void afficherFile(T_File *ptrF)
{
    int i; 
    i= ptrF->Tete;
    while(i!= ptrF->Queue)
    {
        i++;
        afficherElt(&(ptrF->Elts[i]));
        if ((i==MAX-1) && (MAX-1 != ptrF->Queue))
            i=-1;

    }

}






