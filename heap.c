#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

void verArreglo(Heap* h){
    int i;
    printf("\t[");
    for(i=0; i<h->size; i++){
        printf("%d ",h->heapArray[i].priority);
    }
    printf("]\n");
}

void* heap_top(Heap* pq){
   if(pq->size==0)return NULL;
   return (void*)pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

   if(pq->size==0)return;

   if(pq->size>=pq->capac){
      pq->capac=pq->capac*2+1;
      pq->heapArray=(heapElem*)realloc(pq->heapArray,pq->capac*sizeof(heapElem));
   }

   for(int i=0;i<pq->size;i++){
      if(pq->heapArray[i].priority==priority){
         return;
      }
   }

   int ubicacion=pq->size;
   pq->size++;


   pq->heapArray[ubicacion].priority=priority;
   pq->heapArray[ubicacion].data=data;

   heapElem auxEl;

   while (priority>pq->heapArray[(ubicacion-1)/2].priority)
   {
      auxEl=pq->heapArray[(ubicacion-1)/2];
      pq->heapArray[(ubicacion-1)/2]=pq->heapArray[ubicacion];
      pq->heapArray[ubicacion]=auxEl;
      ubicacion=(ubicacion-1)/2;

      if(ubicacion==0)break;
   }

}  
 
 int MayorI(int a,int b,int indexA,int indexB){
      if(a>b)return indexA;
      else if(b>a)return indexB;
      else return -1;
 }

void heap_pop(Heap* pq){
   if(pq->size==0)return;

   pq->heapArray[0]=pq->heapArray[pq->size];
   pq->size--;
   int ubicacion=0;
   int izq,der;
   heapElem auxEl;
   verArreglo(pq);
   while(pq->heapArray[(ubicacion*2)+1].priority > pq->heapArray[ubicacion].priority || pq->heapArray[(ubicacion*2)+2].priority > pq->heapArray[ubicacion].priority){
      izq=pq->heapArray[(ubicacion*2)+1].priority;
      der=pq->heapArray[(ubicacion*2)+2].priority;

      int mayor=MayorI(izq,der,(ubicacion*2)+1,(ubicacion*2)+2);

      auxEl=pq->heapArray[mayor];
      pq->heapArray[mayor]=pq->heapArray[ubicacion];
      pq->heapArray[ubicacion]=auxEl;

      ubicacion=mayor;
      if (mayor>=pq->size)break;
      verArreglo(pq);
   }

}

Heap* createHeap(){
   Heap* heap = (Heap*) malloc (sizeof(Heap));
   heap->heapArray = (heapElem*) calloc (3,sizeof(heapElem));
   heap->size=0;
   heap->capac=3;
   return heap;
}
