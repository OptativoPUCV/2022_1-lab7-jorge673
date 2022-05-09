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


void* heap_top(Heap* pq){
   if(pq->size==0)return NULL;
   return (void*)pq->heapArray[0].data;
}



void heap_push(Heap* pq, void* data, int priority){

   if(pq->size==0)return NULL;

   if(pq->size>=pq->capac){
      pq->capac=pq->capac*2;
      pq->heapArray=realloc(pq->heapArray,pq->capac);
   }

   for(int i=0;i<pq->size;i++){
      if(pq->heapArray[i].priority==priority){
         return NULL;
      }
   }

   int ubicacion=pq->capac;
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


void heap_pop(Heap* pq){

}

Heap* createHeap(){
   Heap* heap = (Heap*) malloc (sizeof(Heap));
   heap->heapArray = (heapElem*) calloc (3,sizeof(heapElem));
   heap->size=0;
   heap->capac=3;
   return heap;
}
