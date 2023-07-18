/** 
* @file        : ArrayList.cpp
* @description : ArrayList veri yapisini olusturuyor.
* @course Dersi: Yaz Donemi 1. Ogretim B Grubu 
* @assignment  : 2. Odev
* @date        : 17.08.2022
* @author      : Yusuf Yesin
*/
#include "ArrayList.hpp"
#include <iostream>

using namespace std;

ArrayList::ArrayList(){
    this->length = 0;
    this->capacity = 100;
    this->items = new int[capacity];

}
int ArrayList::size() const // dizinin uzunlugunu veriyor.
{
    return this->length;
}
int ArrayList::getElement(int index) // girilen indexdeki sayiyi veriyor.
{
    if (index<0 || index>=length) throw "out of range";
    return items[index];
}
void ArrayList::reserve(int newCapacity) // dizinin kapasitesini iki katina çikariyor.
{
    int *tmp = new int[newCapacity];
    for(int i=0;i<length;i++) tmp[i] = items[i];
    delete [] items;
    items = tmp;
    capacity = newCapacity;
}
void ArrayList::insert(int index, const int item) // istenen indexe sayi ekliyor.
{
    if (length >= capacity-1) reserve(2*capacity);
    for(int i=length;i>=index;i--) this->items[i+1] = this->items[i];
    items[index] = item;
    length++;
}
void ArrayList::add(const int item) // en sona sayi ekliyor.
{
    insert(length, item);
}
void ArrayList::removeAt(int index) // girilen indexdeki sayiyi siliyor.
{
    if (index<0 || index>length) throw "out of range";
    for(int i=index;i<length-1;i++) items[i] = items[i+1];
    length--;
}
void ArrayList::changeElement(int index,int item)
{
    items[index] = item;
}
void ArrayList::clear() // listeyi sifirliyor.
{
    length = 0;
}
ArrayList::~ArrayList()
{
    delete [] items;
}
