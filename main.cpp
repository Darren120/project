#include "LinkedBag.h"
#include "BagInterface.h"
#include "Node.h"
#include <iostream>
void displayBag(LinkedBag<std::string>& bag)
{
   std::cout << "The bag contains " << bag.getCurrentSize()
   << " items:" << std::endl;
   std::vector<std::string> bagItems = bag.toVector();
   
   int numberOfEntries = (int) bagItems.size();
   for (int i = 0; i < numberOfEntries; i++)
   {
      std::cout << bagItems[i] << " ";
   }  // end for
   std::cout << std::endl << std::endl;
}
int main()
{
  

    LinkedBag<std::string> bag;
    bag.add("A");
    bag.add("B");
    bag.add("C");
    bag.add("D");
     bag.add("E");
     std::cout << "TEST 1 ========================================"<< std::endl;
    displayBag(bag);
   //  bag.removeRandom();
   //  displayBag(bag);
   //    bag.removeRandom();
   //  displayBag(bag);
 
    std::cout << "itertive size: " << bag.getCurrentSize() << std::endl;
    std::cout << "recrusive size: " << bag.getCurrentSizeRecursive() << std::endl;


   std::cout << "TEST 2 ================================================"<< std::endl;
   bag.deleteSecondNode();
      displayBag(bag);
    std::cout << "itertive size: " << bag.getCurrentSize() << std::endl;
    std::cout << "recrusive size: " << bag.getCurrentSizeRecursive() << std::endl;
   displayBag(bag);
    // displayBag(bag);
    // std::cout << "itertive size: " << bag.getCurrentSize() << std::endl;
    // std::cout << "recrusive size: " << bag.getCurrentSizeRecursive() << std::endl;
    // bag.deleteSecondNode();
    // displayBag(bag);
    // std::cout << "itertive size: " << bag.getCurrentSize() << std::endl;
    // std::cout << "recrusive size: " << bag.getCurrentSizeRecursive() << std::endl;

    // std::string a[] = {"a", "b","c", "d"};
   
    // LinkedBag<std::string> b(a,4);

    // displayBag(b);
 


    
    
  
    return 0;
}
