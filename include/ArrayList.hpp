#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
class ArrayList
{
private:
    int* items;
    int length;
    int capacity;
    void reserve(int newCapacity);              // dizinin kapasitesini iki katina çikariyor.
public:
    
    ArrayList();
    int size()const;                            // dizinin uzunlugunu veriyor.
    int getElement(int index);                // girilen indexdeki sayiyi veriyor.
    void insert(int index,const int item);    // istenen indexe sayi ekliyor.
    void add(const int item);                 // istenen indexe sayi ekliyor.
    void removeAt(int index);                   // girilen indexdeki sayiyi siliyor.
    void changeElement(int index, int item);  //sayiyi girilen indexe atiyor.
    void clear();                               // listeyi sifirliyor.
    ~ArrayList();
};



#endif 