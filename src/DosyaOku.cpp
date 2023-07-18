/** 
* @file        : DosyaOku.cpp
* @description : Sayilar.txt dosyasini okur.
* @course Dersi: Yaz Donemi 1. Ogretim B Grubu 
* @assignment  : 2. Odev
* @date        : 17.08.2022
* @author      : Yusuf Yesin
*/
#include "DosyaOku.hpp"
#include "ArrayList.hpp"
#include "Radix.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

DosyaOku::DosyaOku() {
    string satir = "";
    string sayi = "";
    char c = ' ';
    satirSayisi = 0;
    satirdakiElemanSayisi = new ArrayList();

    ifstream dosyaoku("./doc/Sayilar.txt");
    if ( dosyaoku.is_open() ){
        int boslukSayisi = 0;

        // bu dongude satir sayisi ve her satirdaki sayi adedini buluyorum
        while (getline(dosyaoku, satir) ){
            int k = 0;
            while (true)
            {
                if (satir[k] == ' ' && k != satir.length()-1) {
                    boslukSayisi++;
                    k++;
                    continue;
                }
                c = satir[k];
                k++;
                if (c=='\0') {
                    break;
                }
            }
            satirdakiElemanSayisi->add((boslukSayisi+1));
            boslukSayisi = 0;
            satirSayisi++;
        }
        dosyaoku.close();
    }

    sayilar        = new int*[satirSayisi]; //dosyadaki sayilari tutacak matrisi tanimlar
    sayilarToplami = new int[satirSayisi];  //her satirin toplamini tutacak diziyi tanımlar

    for (size_t i = 0; i < satirSayisi; i++)
    {
        sayilar[i] = new int[satirdakiElemanSayisi->getElement(i)];
    }
    
    ifstream dosyaOku("./doc/Sayilar.txt");
    if ( dosyaOku.is_open() ){

        int index = 0; //index sayaci
        int j     = 0; //satir sayaci
        while (getline(dosyaOku, satir) ){
            int i = 0; //karakter sayaci
            sayilarToplami[j] = 0; 
            while (true)
            {
                if (satir[i] == ' ' && i != satir.length()-1) {
                    sayilar[j][index] = stoi(sayi);
                    sayilarToplami[j] +=  stoi(sayi);
                    
                    
                    i++;
                    index++;
                    sayi = "";
                    continue;
                }
                c = satir[i];
                sayi += c;
                i++;
                if (c=='\0') {
                    sayilar[j][index] = stoi(sayi);
                    sayilarToplami[j] +=  stoi(sayi);
                    
                    index = 0;
                    sayi = "";
                    break;
                }
            }
            
            j++;
        }
        dosyaOku.close();
    }

}
void DosyaOku::sayilariSirala(){
    Radix *radix  = new Radix();
    for (size_t i = 0; i < satirSayisi; i++)
    {
        radix->radixsort(sayilar[i], satirdakiElemanSayisi->getElement(i));
    }
    delete radix;
}
DosyaOku::~DosyaOku(){
    delete satirdakiElemanSayisi;
    delete []sayilarToplami;
    delete []sayilar;
}
