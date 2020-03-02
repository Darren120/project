//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
    @file LinkedBag.cpp */

#include "LinkedBag.h"
#include "Node.h"
#include <cstddef>
#include <iostream>
#include <stdlib.h>
template<class ItemType>
LinkedBag<ItemType>::LinkedBag() : headPtr(nullptr), itemCount(0)
{
}  // end default constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(const LinkedBag<ItemType>& aBag)
{
	itemCount = aBag.itemCount;
   Node<ItemType>* origChainPtr = aBag.headPtr;  // Points to nodes in original chain
   
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
      
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
      
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
              
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
         
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
         
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();

         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
      
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor

template<class ItemType>
LinkedBag<ItemType>::LinkedBag(ItemType entries[], int entryCount){
   Node<ItemType> *temp = new Node<ItemType>;
    temp->setItem(entries[0]);
    temp->setNext(nullptr);
    headPtr = temp;
    itemCount = entryCount;
   for (int i = 1; i < entryCount; i++)
   {
      Node<ItemType> *temp2 = new Node<ItemType>;
      temp->setNext(temp2);
      temp2->setItem(entries[i]); 
      temp2->setNext(nullptr);
      temp=temp2;
     
   }
   
   
 
}


template<class ItemType>
LinkedBag<ItemType>::~LinkedBag()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedBag<ItemType>::isEmpty() const
{
	return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize() const
{
   Node<ItemType> *tempNode = new Node<ItemType>();
   tempNode = headPtr;
   int count = 0;
   if (tempNode != nullptr)
   {
      count ++;
      while(tempNode->getNext() != nullptr){
         tempNode = tempNode->getNext();
         count++;
      }
      return count;

   } else {
      return count;
   }

} 

template<class ItemType>
int LinkedBag<ItemType>::getCurrentSizeRecursive(){

   
 if (headPtr == nullptr)
 {
     std::cout << "a" << std::endl;
    return 0;
 }
   Node<ItemType> nextNode;
   nextNode.setItem(headPtr->getItem());
   nextNode.setNext(headPtr->getNext());
   
    if (nextNode->getNext() != nullptr){
        LinkedBag<ItemType> restOfList;
        restOfList.add(nextNode);
        return 1 + restOfList.getCurrentSizeRecursive();
    }
   // if (){
   //      LinkedBag<ItemType> restOfList;
   //      restOfList.;
   //      return 1 + restOfList.getCurrentSizeRecursive();
   //  }

   return 1;
}

template<class ItemType>
void LinkedBag<ItemType>::add2(Node<ItemType> *newEntry){
   headPtr ->setItem(newEntry->getItem());
   headPtr->setNext(newEntry); 

}


template<class ItemType>
ItemType LinkedBag<ItemType>::removeRandom() {
 ItemType p;
 srand(time(NULL));
 int v1 = rand() % itemCount +1;
 
//  v1 = rand() % itemCount + 1;
 // if first and if last;
   Node<ItemType> *newNode = new Node<ItemType>();
   Node<ItemType> *nodeToDelete = new Node<ItemType>();
   Node<ItemType> *v = new Node<ItemType>();
      //set first node to head pointer
   newNode = headPtr;
   v=headPtr;
   // if random picks first or last node
   if (v1 == 0 || v1 == 1)
   {
      p = v->getItem();
      nodeToDelete = v;
      headPtr = headPtr->getNext();
      delete nodeToDelete;
      nodeToDelete = nullptr;
      return p;
   } else if (v1 == itemCount )
   {
      for (int i = 0; i < v1; i++)
      {
         if (i==0)
         {
    
         } else {
          v = v->getNext();  
          if (i == itemCount - 1)
          {
             break;
          }
  
          if (i > 1 || (i != itemCount - 1))
          {
             newNode = newNode->getNext();
          }
          
         }
     }
      
      p = v->getItem();
      nodeToDelete = v;
      newNode->setNext(nullptr);
      delete nodeToDelete;
      nodeToDelete = nullptr;
      itemCount --;
      return p;
      
   }
   
   
// all other conditions
   for (int i = 0; i < v1; i++)
   {
      if (i==0)
      {  
      } else {
         v = v->getNext();    
         if (i > 1 && i != itemCount - 1)
         {
            newNode = newNode->getNext();
         }
      }   
   }
   p = v->getItem();
   nodeToDelete = v; // this is "B"
   newNode->setNext(nodeToDelete->getNext());
   delete nodeToDelete;
   nodeToDelete = nullptr;
   itemCount --;
   return p;

}

template<class ItemType>
bool LinkedBag<ItemType>::add(const ItemType& newEntry)
{
   // Add to beginning of chain: new node references rest of chain;
   // (headPtr is null if chain is empty)        
   Node<ItemType>* nextNodePtr = new Node<ItemType>();
   nextNodePtr->setItem(newEntry);

   nextNodePtr ->setNext(nullptr);
   if (headPtr == nullptr)
   {
      headPtr = nextNodePtr;
   } else {
      //head pointer still points to the first node. we use temp so when traversing it can point toward
      // the end. since its pointers, it affacts all.
       Node<ItemType>* temp = headPtr;
       while (temp->getNext() != nullptr)
       {
          temp = temp->getNext();
       }
       temp->setNext(nextNodePtr);
       
   }
   


   // nextNodePtr->setNext(headPtr);  // New node points to chain
//   Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, headPtr); // alternate code


   itemCount++;
   
   return true;
}  // end add

template<class ItemType>
std::vector<ItemType> LinkedBag<ItemType>::toVector() const
{
   std::vector<ItemType> bagContents;
   Node<ItemType>* curPtr = headPtr;
   int counter = 0;
	while ((curPtr != nullptr) && (counter < itemCount))
   {
		bagContents.push_back(curPtr->getItem());
      curPtr = curPtr->getNext();
      counter++;
   }  // end while
   
   return bagContents;
}  // end toVector

template<class ItemType>
bool LinkedBag<ItemType>::remove(const ItemType& anEntry)
{
   Node<ItemType>* entryNodePtr = getPointerTo(anEntry);
   bool canRemoveItem = !isEmpty() && (entryNodePtr != nullptr);
   if (canRemoveItem)
   {
      // Copy data from first node to located node
      entryNodePtr->setItem(headPtr->getItem());
      
      // Delete first node
      Node<ItemType>* nodeToDeletePtr = headPtr;
      headPtr = headPtr->getNext();
      
      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      nodeToDeletePtr = nullptr;
      
      itemCount--;
   } // end if
   
	return canRemoveItem;
}  // end remove

template<class ItemType>
void LinkedBag<ItemType>::deleteSecondNode() {
   if (headPtr!=nullptr) {
      Node<ItemType> *newNode = new Node<ItemType>();
      Node<ItemType> *nodeToDelete = new Node<ItemType>();
      //set first node to head pointer
      newNode = headPtr;
      if (headPtr->getNext() != nullptr)
      {
         nodeToDelete = headPtr->getNext();
         
         newNode->setNext(nodeToDelete->getNext());
         delete nodeToDelete;
         nodeToDelete = nullptr;
         itemCount --;
      }
   }
}

template<class ItemType>
void LinkedBag<ItemType>::clear()
{
   Node<ItemType>* nodeToDeletePtr = headPtr;
   while (headPtr != nullptr)
   {
      headPtr = headPtr->getNext();

      // Return node to the system
      nodeToDeletePtr->setNext(nullptr);
      delete nodeToDeletePtr;
      
      nodeToDeletePtr = headPtr;
   }  // end while
   // headPtr is nullptr; nodeToDeletePtr is nullptr
   
	itemCount = 0;
}  // end clear

template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const
{
	int frequency = 0;
   int counter = 0;
   Node<ItemType>* curPtr = headPtr;
   while ((curPtr != nullptr) && (counter < itemCount))
   {
      if (anEntry == curPtr->getItem())
      {
         frequency++;
      } // end if
      
      counter++;
      curPtr = curPtr->getNext();
   } // end while
   
	return frequency;
}  // end getFrequencyOf

template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
	return (getPointerTo(anEntry) != nullptr);
}  // end contains

/* ALTERNATE 1
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   return getFrequencyOf(anEntry) > 0;
} 
*/
/* ALTERNATE 2 
template<class ItemType>
bool LinkedBag<ItemType>::contains(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   int i = 0;
   while (!found && (curPtr != nullptr) && (i < itemCount))
   {
      if (anEntry == curPtr-<getItem())
      {
         found = true;
      }
      else
      {
         i++;
         curPtr = curPtr->getNext();
      }  // end if
   }  // end while

   return found;
}  // end contains
*/

// private
// Returns either a pointer to the node containing a given entry 
// or the null pointer if the entry is not in the bag.
template<class ItemType>
Node<ItemType>* LinkedBag<ItemType>::getPointerTo(const ItemType& anEntry) const
{
   bool found = false;
   Node<ItemType>* curPtr = headPtr;
   
   while (!found && (curPtr != nullptr))
   {
      if (anEntry == curPtr->getItem())
         found = true;
      else
         curPtr = curPtr->getNext();
   } // end while
   
   return curPtr;
} // end getPointerTo


