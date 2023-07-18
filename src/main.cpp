/** 
* @file        : main.cpp
* @course Dersi: Yaz Donemi 1. Ogretim B Grubu 
* @assignment  : 2. Odev
* @date        : 17.08.2022
* @author      : Yusuf Yesin
*/
#include <iostream>
#include "DosyaOku.hpp"
#include "AVL.hpp"

using namespace std;


int main() {
  DosyaOku *dosya = new DosyaOku();
  delete dosya;

  AVL *avl = new AVL();

  avl->SayilariAgacaEkle();
	cout<<"\nPreorder Yazim Sekli: \n";
  avl->preorder();
  delete avl;
}