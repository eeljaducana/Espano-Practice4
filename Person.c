#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"
#include "CircularArrayQ.h"

Person createPerson(String name, char sex, String city) {
    Person p;

    strcpy(p.name, name);
    p.sex = sex;
    strcpy(p.city, city);

    return p;
}

void displayPersonInfo(Person p) {
    printf("{%s | %c | %s}", p.name, p.sex, p.city);
} 

/* Static Array List*/
void init_SAL(PersonStaticArrayList *list){
 
 list -> count =0;

}


void insert_first_SAL(PersonStaticArrayList *list, Person p){
 
 if(list->count != MAX_LIST){
    
     if(list -> count !=0 ){
          int x;
          for(x=list->count; x>=1; x--){
              list->data[x]= list->data[x-1];
          }
          list ->count ++;
          list ->data[0]=p;
      }
          list->count++;
          list->data[0]=p; 
   }
}


void insert_last_SAL(PersonStaticArrayList *list, Person p){

    if(list->count != MAX_LIST){
         list->data[list->count]= p;
         list->count++;
    }
}


void insert_at_SAL(PersonStaticArrayList *list, Person p, int  index){

    if(list->count != MAX_LIST){
        int x;
        for(x=0; x< MAX_LIST && x!=index ; x++){}
        if(x != MAX_LIST){
            list->data[x]=p;
            list->count++;
        }   
    }
}

void delete_first_SAL(PersonStaticArrayList *list){
   
   if(list->count != 0){
       int x; 
       for(x=0; x < list->count; x++){
         list->data[x]= list->data[x+1];
       }
       list -> count--;
   }

}


void delete_last_SAL(PersonStaticArrayList *list){

   if(list->count != 0){
       list -> count --;
   }

}

void delete_by_sex_SAL(PersonStaticArrayList *list, char sex){

int x,y,ctr=0;

for(x=0; x< list->count ; x++){
    if(list->data[x].sex==sex){
        list->count--;
        for(y=x;y<list -> count ; y++){
            list -> data[y] = list->data[y+1];
        }
    }
}

} // all ocurrences


void display_SAL(PersonStaticArrayList list){

if(list.count != 0){
    printf("%15s | %15c | %15s \n", "Name", "Sex", "City");
    int x;
    for(x=0; x< list.count ; x++){
        printf("%15s | %15c | %15s \n", list.data[x].name,list.data[x].sex, list.data[x].city);
    }
    printf("Count= %d",list.count);
}

}

// *************************************************Dynamic Array List Version 1**********************************************************
void init_DAL(PersonDynamicArrayList *list){

 list->max = MAX_LIST;
 list->data= (Person*) malloc (sizeof(Person)* list->max);
 list->count=0;

}

void insert_first_DAL(PersonDynamicArrayList *list, Person p){
   if (list-> count != list->max){
       if(list -> count != 0){
           int x;
           for(x = list-> count ; x >= 1 ; x--){
               list-> data[x] = list -> data[x-1];
           }
           list ->count ++;
           list-> data[0]=p;
       }

       list->count ++;
       list ->data[0]=p;

   }
   else{
      list->data=realloc(list->data, sizeof(Person)*(list->max*2));
      list->max*=2; 
      int z;
      for(z=list->count;z >= 1; z++){
         list->data[z] = list -> data[z-1];
      }
      list->count++;
      list->data[0]=p;

   }
}

void insert_last_DAL(PersonDynamicArrayList *list, Person p){

   if(list -> count != list->max){
       list -> data[list -> count]=p;
       list -> count ++;
   }else {
   
       list->count=realloc(list->count,( list->max*2)*sizeof(Person));
       list->max*=2;
       list->data[list->count]=p;
       list->count++;

   }

}


void insert_at_DAL(PersonDynamicArrayList *list, Person p, int index){
if(list -> count != list->max){
    int x;
    for(x=0;x<list->count && x != index; x++){}
        if(x!=list->count-1){
            list->data[x]=p;
            list->count++;
        }
    
}
else{

   list->data= realloc(list->data,sizeof(Person)* (list->max*2));
   list->max*=2;

   int z;
   for(z=0; z<list->count && z!=index ; z++){}
   if(z != list->count-1){
      list->data[z]=p;
      list->count++;
   }

}
}

void delete_first_DAL(PersonDynamicArrayList *list){
      if(list -> count != 0){
          int x;
          for(x = 0; x < list->count ; x++){
              list->data[x]= list->data[x-1];
          }
          list->count--;
      }
}

void delete_last_DAL(PersonDynamicArrayList *list){
  if(list->count !=0 ){
      list -> count --;
  }
}

void delete_by_city_DAL(PersonDynamicArrayList *list, String city){

      if(list->count != 0){
          int x,y;
          for(x=0; x< list -> count && strcmp (list -> data[x].city , city) != 0 ; x++){}
          if(x < list->count){
              for(y=x ; y<list->count; y++){
                  list->data[y]= list->data[y+1];
              }
              list->count--;
          }
      }

}// first ocurrence

void display_DAL(PersonDynamicArrayList list){

     printf("%15s | %15c | %15s \n", "Name","Sex","City");
     int x;
     for(x=0; x < list.count ; x++){
         printf("%15s | %15c | %15s \n",list.data[x].name, list.data[x].sex, list.data[x].city);
     }
     printf("Count: %d", list.count);
}

/* Dynamic Array List - v2 
 * Doubles the maximum size of the array when full.
 * The Dynamic Array List must also be created in the heap.
 */
void init_DAL_2(PersonDynamicArrayList **list){
    (*list)->count=0;
    (*list)->max = MAX_LIST;
    (*list)->data=(Person*)malloc(sizeof(Person)*(*list)->max);

}

void insert_first_DAL_2(PersonDynamicArrayList *list, Person p){

     if(list->count != list->max){
          if(list->count !=0){
              int x;
              for(x= list->count; x >=1;x--){
                  list->data[x] = list->data[x-1];

              }
              list->data[0]=p;
              list->count++;
          }
          list->data[0]=p;
          list->count++;
     }else{
         list->data=realloc(list->data,sizeof(Person)*(list->max*2));
         list->max*=2;

         int z;
         for(z=list->max; z>=1 ; z--){
             list->data[z]= list->data[z-1];
         }
         list->count++;
         list->data[0]=p;
     }

}

void insert_last_DAL_2(PersonDynamicArrayList *list, Person p){

     if(list->count != list->max){
         list->data[list->count]=p;
         list->count++;
     }else{
         list->data = realloc(list->data, sizeof(Person)*(list->max*2));
         list->max*=2;
     }
}

void insert_at_DAL_2(PersonDynamicArrayList *list, Person p, int index){

     if(list->count != list->max){
         int x;
         for(x=0; x<list->count && x!=index;x++){}
          if(x<list->count){
              list->data[x]=p;
              list->count++;
          }
     }else{
         list->data=realloc(list->data, sizeof(Person)*(list->max*2));
         list->max*=2;
         int z;
         for(z=0; z<list->count && z!=index; z++){}
         if(z < list->count){
             list->data[z]=p;
             list->count++;
         }
     }

}

void delete_first_DAL_2(PersonDynamicArrayList *list){
        if(list->count != 0){
            int x;
            for(x=0; x<list->count; x++){
                list->data[x]= list->data[x+1];
            }
            list->count--;
        }
}

void delete_last_DAL_2(PersonDynamicArrayList *list){
          if(list->count !=0){
              list->count--;
          }
}

void delete_by_name_DAL_2(PersonDynamicArrayList *list, String name){

            if(list->count !=0 ){
                int x;
                for(x=list->count-1; x>=0 && strcmp( list->data[x].name, name)!=0;x--){}
                if(x!=list->count-1){
                int z;
                for(z=x; z<list->count ; z++){
                    list->data[z]= list->data[z+1];
                }
                list->count--;
                }
                else {
                    list->count--;
                }

            }

} // last ocurrence
void display_DAL_2(PersonDynamicArrayList list){

       printf("Dynamic Array List (version 2)\n");
       printf("%15s | %15s | %15s \n ","Name","Sex","City");

       int x;
       for(x=0;x<list.count;x++){
       printf("%15s | %15c | %15s /n",list.data[x].name, list.data[x].sex, list.data[x].city);
       }

       printf("Count: %d\n Max: %d", list.count,list.max);

}

/* Singly Linked List */
void insert_first_LL(PersonLinkedList *list, Person p){

       PersonLinkedList temp=(PersonLinkedList)malloc(sizeof(PersonNode));
       if(temp != NULL){
           temp->next=*list;
           *list=temp;
           temp->elem=p;
       }

}

void insert_last_LL(PersonLinkedList *list, Person p){

   PersonLinkedList temp=(PersonLinkedList)malloc(sizeof(PersonNode));
   if(temp!=0){
       for(;*list != NULL && (*list)->next != NULL ; list= &(*list)->next){}
       temp->next=NULL;
       temp->elem=p;
       if(*list == NULL){
           *list=temp;
       }else{
           (*list)->next = temp;
       }
   }

}

void insert_after_LL(PersonLinkedList *list, Person p, String name){
    PersonLinkedList temp;
    temp = (PersonLinkedList)malloc(sizeof(PersonNode));
    if(temp != NULL){
        for(;*list != NULL && strcmp((*list)->elem.name,name)!=0; list= &(*list)->next){}
        if(*list!= NULL){
            temp -> next =(*list)->next;
            temp -> elem = p;
            *list =temp;
        }
    }
}

void delete_first_LL(PersonLinkedList *list){
    PersonLinkedList temp;
    if(*list != NULL){
        temp=*list;
        *list= (*list)->next;
        free(temp);
    }
}

void delete_last_LL(PersonLinkedList *list){

    PersonLinkedList temp;
    if(*list != NULL){
    for(;(*list)->next != NULL; list=&(*list)->next){}
    temp=*list;
    *list=temp->next;
    free(temp);
    }

}

void delete_by_city_LL(PersonLinkedList *list, String city){

    PersonLinkedList temp;
    if(*list != NULL){
        for(;*list!=NULL && (*list)->next != NULL; list= &(*list)->next){
          temp=*list;
          *list = temp->next;
          free(temp);
        }
    }


} // all ocurrences
void display_LL(PersonLinkedList list){
     printf("%15s | %15s | %15s \n", "Name", "Sex", "City");
    for(;list != NULL ; list = list->next){
        peintf("%15s | %15c | %15s\n", list->elem.name,list->elem.sex,list->elem.city);
    }


}


/* Implement all VSpace conncept and Cusor Based List*/

void init_vspace(VSpace *vs){
int x;
for(x=MAX_VSPACE-1; x>=0; x--){
    vs->data[x].next= x-1;
     }
   vs->avail = MAX_VSPACE-1;
}

Position alloc_space(VSpace *vs){
Position avail;
avail = vs-> avail;
if( avail != NULL ){
    vs->avail = vs->data[avail].next;
}

return avail;

}


void free_space(VSpace *vs, Position index){
   
    if(index != -1 && index <MAX_VSPACE){
        vs->data[index].next = vs->avail;
        vs->avail= index;
    }
}

void insert_first_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){
    
    Position temp = allocSpace(vs);

    if(temp != -1) {
        vs->data[temp].elem = p;
        vs->data[temp].next = *list;
        *list = temp;
    }
}

void insert_last_CBL(VSpace *vs, PersonCusorBasedList *list, Person p){

      Position temp = allocSpace(vs);
      Position ctr;

      for(ctr=*list; vs->data[ctr].next != -1; ctr= vs->data[ctr].next){}
      vs->data[temp].elem=p;
      vs->data[temp].next=-1;
      vs->data[ctr].next=temp;

}

void insert_at_CBL(VSpace *vs, PersonCusorBasedList *list, Person p, int index){
        Position x;
        if(*list != -1){
            for( x = *list ; x!=-1 && x != index; x= vs->data[x].next){}
            if(x != -1){
                vs->data[index].elem=p;
                vs->data[x].next= vs->data[index].next;
            }
        }

}

void delete_first_CBL(VSpace *vs, PersonCusorBasedList *list){

     if(*list != -1){
          Position z=*list;
          
          vs->data[*list].next = vs->avail;
          vs->avail= *list;
          *list = vs->data[z].next;

     }

}

void delete_last_CBL(VSpace *vs, PersonCusorBasedList *list){

       if(*list != -1){

       int ctr=*list;
       Position z,y;

       for(;vs->data[ctr].next != -1 ; ctr = vs->data[ctr].next){}
           
           z= ctr;
           
           vs->data[ctr].next=vs->avail;
           vs->avail = ctr;
           y=*list;
           for(;vs->data[y].next != z; y=vs->data[y].next){}
           if(vs->data[y].next == z ){
                
                vs->data[y].next=-1;
           }
       }
}


void delete_by_sex_CBL(VSpace *vs, PersonCusorBasedList *list, char sex){
       Position ctr, z=*list;
       if(*list != -1){
           for(ctr=*list ; ctr != -1; ctr = vs-> data[ctr].next){
               if(vs->data[ctr].elem.sex == sex){
                   for(;vs->data[z].next != ctr; z= vs->data[z].next){}
                   vs->data[z].next= vs->data[ctr].next;
                   vs->data[ctr].next=vs->avail;
                   vs->avail = ctr;
               }
           }
       }
}


void display_CBL(VSpace vs, PersonCusorBasedList list){

      printf(" %15s | %15s | %15s \n","Name", "Sex", "City");
      for(; list != -1; list = vs.data[list].next){
         printf(" %15s | %15c | %15s \n", vs.data[list].elem.name,vs.data[list].elem.sex,vs.data[list].elem.city);
      } 
      printf("{Avail= %d\n List = %d}", vs.avail, list);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/** \fn CircularArrayQueue create_array_queue();
 *  \brief Create an empty circular array queue.
*/
CircularArrayQueue create_array_queue(){

 CircularArrayQueue carray;

    int x;
    for(x= 0; x<MAX ; x++){

        carray.data[x];

    }
    carray.front= 0;
    carray.rear= MAX -1;

     return carray;
}



/** \fn void init_array_queue(CircularArrayQueue *list);
 *  \brief Initialize as an empty circular array queue.
 *  \param list The queue that needs to be initialize.
*/
void init_array_queue(CircularArrayQueue *list){


          int x;
          for(x=0;x<MAX;x++){
              list->data[x];
          }

          list->front =0;
          list->rear=MAX-1;
}

/** \fn bool enqueue(CircularArrayQueue *list, Type p);
 *  \brief Adds a new person element into the last element available in the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
 *  \param p The person to be added in the queue.
*/
bool enqueue(CircularArrayQueue *list, Type p){
       if(!is_full(*list)){
           list->rear=(list->rear+1)%MAX;
           list->data[list->rear]=p;
           return true;
       }
       else{
           return false;
       }
}

/** \fn bool dequeue(CircularArrayQueue *list);
 *  \brief Remove the first inserted element from the current queue. Returns true for a successful operation otherwise false.
 *  \param list The current queue.
*/
bool dequeue(CircularArrayQueue *list){

     if(!is_empty(*list)){
         list->front=(list->front+1)%MAX;
         return true;
     }else{
         return false;
     }


}

/** \fn bool is_empty(CircularArrayQueue list);
 *  \brief Return true if the current list is empty otherwise false.
 *  \param list The current queue.
*/
bool is_empty(CircularArrayQueue list){


    if(list.rear+1)%MAX == list.front){
         return true;
    }else{
        return false;
    }
}

/** \fn bool is_full(CircularArrayQueue list);
 *  \brief Return true if the current list is full otherwise false.
 *  \param list The current queue.
*/
bool is_full(CircularArrayQueue list){

        if(list.rear+2)%MAX == ;list.front){
            return true;
        }else{
            return false;
        }
}

/** \fn Type front(CircularArrayQueue list);
 *  \brief Return the person in the front without removing them.
 *  \param list The current queue.
*/
Type front(CircularArrayQueue list){

    
    if(!is_empty(list)){

       return list.data[list.front];
    }
}


/** \fn int get_queue_length(CircularArrayQueue list);
 *  \brief Get the number of elements in the current queue.
 *  \param list The current queue.
*/
int get_queue_length(CircularArrayQueue list){
         int x = 0;
         int ctr=list.front;

         for(;ctr != list.rear; ctr= ( ctr+1 )%MAX){
             x++;
         }

         return x+1;
}

/** \fn PersonLinkedList get_all_females(CircularArrayQueue list);
 *  \brief Returns all females as a linked list using the current list without removing them in the current list.
 *  \param list The current queue.
 *  Note: Use the queue basic operations (enqueue, dequeue, front)
*/
PersonLinkedList get_all_females(CircularArrayQueue list){

PersonLinkedList retval =NULL,temp;
bool check;

if(!is_empty(list)){
    while(list.front != list.rear)
    {
        temp=(PersonLinkedList)malloc(sizeof(PersonNode));
        if(temp != NULL){
            if(list.data[list.front].sex == 'F' || list.data[list.front].sex == 'f'){
              
              temp->elem= list.data[list.front];
              temp->next=retval;
              retval = temp;
              check=dequeue(&list);
              if(check == true ){
                  continue;
              }

            }
        }
    }
    
}

          

 }

/** \fn PersonDynamicArrayList remove_all_males(CircularArrayQueue *list);
 *  \brief Remove all males in the current list and returns the removed males as a dynamic array list.
 *  \param list The current queue.
 *  Note: Use the concept of queue with out using the basic operations.
*/
PersonDynamicArrayList remove_all_males(CircularArrayQueue *list){

      PersonDynamicArrayList retval;
      init_DAL(retval);
      bool check;
      
      if(!is_empty(list)){

        while(list->front != list.rear){
           
            if(list->data[list->front].sex == 'M' || list->data[list->front].sex == 'f'){
              int x=0;
              retval.data[x]= list->data[list->front];
              retval.count++;
              x++;



              list->front=(list->front+1 % MAX);
              
            }

        }

        return retval;


      }





}
