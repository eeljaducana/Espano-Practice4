#include <stdio.h>
#include <string.h>
#include "Exercise1.h"
#include "CircularArrayQ.h"

int main(void) 
{
    Person p1 = createPerson("Mark", 'M', "Cebu");
    Person p2= createPerson("Gojo", 'M', "Tokyo");
    Person p3 = createPerson("Michelle",'F', "Alegria");
    Person p4 = createPerson("Karen",'F', "Moalboal");
    Person p5 = createPerson("Stephen",'M',"Moalboal");
    Person p6 = createPerson("Greggy", 'M', "Badian");

    // To do code logic here.
     
     //Static Array List

     PersonStaticArrayList L;
     init_SAL(&L);
    
     insert_first_SAL(&L,p1);
     insert_first_SAL(&L,p2);

     insert_last_SAL(&L,p3);
     insert_at_SAL(&L,p4,4);
     insert_first_SAL(&L,p5);
     insert_first_SAL(&L,p6);
     display_SAL(L);
     delete_first_SAL(&L);
     delete_last_SAL(&L);
     delete_by_sex_SAL(&L,'F'); // all ocurrences
     display_SAL(L);


    return 0;

}