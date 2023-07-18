#ifndef AVL_HPP
#define AVL_HPP

#include "Node.hpp"
#include "DosyaOku.hpp"
#include <iostream>
#include <cmath>
using namespace std;

class AVL{
	private:	
		Node *root;
		
		Node* SearchAndAdd(Node *subNode,const int& item, int *array, const int& size);
		Node* SwapWithLeftChild(Node *subNode); //sol cocuk ile cevirme
		Node* SwapWithRightChild(Node *subNode); //sag cocuk ile cevirme
		int Height(Node *subNode);	//girilen dugumun yuksekligini verir
		void preorder(Node *subNode); //preorder ile tum agacıekrana yazdırır
		void postorderlaMinDegeriSil(Node *subNode); //postordere ile gezip dugumlerdeki dizilerin min degerini siler
		void postorderlaMaxDegeriSil(Node *subNode); //postordere ile gezip dugumlerdeki dizilerin max degerini siler
		bool DeleteNode(Node *&subNode);
		bool Search(Node *subNode,const int& item);
	public:
		AVL();
		bool isEmpty()const; //agac bos mu kontrol eder
		void Add(const int& item,int *array, const int& size); //egaca dugum ekler
		void preorder(); //private olan preorder fonksiyonunu cagirir
		int Height(); //private olan Height fonksiyonunu cagirir
		void Clear(); //agactaki dugumleri siler
		void DeleteFirstElement(Node* subNode); //dizideki ilk elemani yani minimum degeri siler
		void DeleteLastElement(Node* subNode); //dizideki son elemani yani maximum degeri siler
		void SayilariAgacaEkle();
		~AVL();
};

#endif