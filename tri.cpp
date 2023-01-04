#include <iostream>
#include <algorithm>
#include "algorithme.cpp"
#include <chrono>

//baldo jerome - BALJ1758609
//METHODOLOGIE EXPLIQUEE POUR TRIS CROISSANT/DECROISSANT/NON TRIES
	// cette m�thode se r�p�te pour les trois boucles r�alisant tris croissant/decroissant/non tries
	// les trois FOR sont calibr�s selon le nombre de cases du tableau tabTaille
	// Pour chaque tour de boucles le programme parcourt le tabTaille pour donner la tailles des tableaux
	// Pour chaque tour de boucles, le programme r�alise les estimations de temps pour tous les tris
	//01 - creation et remplissage du tableau selon ordonnancement
	//02 - demarrage du temps
	//03 - methode de tris appel�e
	//04 - fin du temps
	//05 - calcul et affichage du temps en ns
	//06 - suppression de l'allocation m�moire avec delete
using namespace std;

//methode permettant de generer un nombre al�atoire compris entre 1 et max
//en entree il prend le max
//en sortie il retourne le int al�atoire 
int Proba(int max)
{
	int chiffreAlea = 0;
	chiffreAlea = 1 + rand() % (max + 1 - 1);
	return chiffreAlea;
}

//methode permettant de generer un tableau de taille n avec un ordonnancement non tri�
// les nombres sont g�n�r�s al�atoirement et il peut y avoir une redondance des chiffres 
//il prend en entr�e la taille du tableau et en sortie il retourne un tableau 
int* TabNonTri�(int taille)
{
	int* tab = new int[taille]; //creation du tableau avec la taille voulu / allocation avec new
	for (int i = 0; i < taille; i++) //boucle pour remplir le tableau
	{
		tab[i] = Proba(taille);// appel de la methode Proba() pour g�n�rer un nombre al�atoire
	}

	return tab;
}

//methode permettant de generer un tableau de taille n avec un ordonnancement tri� croissant
//il prend en entr�e la taille du tableau et en sortie il retourne un tableau 
int* TabCroissant(int taille)
{
	int* tab = new int[taille]; //creation du tableau avec la taille voulu / allocation avec new
	for (int i = 0; i < taille; i++)//boucle pour remplir le tableau
	{
		tab[i] = i+1;// indice vont de 1 � N compris
	}

	return tab;
}

//methode permettant de generer un tableau de taille n avec un ordonnancement tri� d�croissant
//il prend en entr�e la taille du tableau et en sortie il retourne un tableau 
int* TabDecroissant(int taille)
{
	int* tab = new int[taille];//creation du tableau avec la taille voulu / allocation avec new
	for (int i = 0; i < taille; i++)//boucle pour remplir le tableau
	{
		tab[i] = taille-i;//decrementation de N jusqu� 1
	}

	return tab;
}

//methode permettant d'afficher le tableau 
// il prend en entr�e le tableau et la taille du tableau
void AffichTab(int* tab, int taille)
{
	for (int i = 0; i < taille; i++)
	{
		cout << tab[i] << " - ";
	}
	cout << endl;
}

int main()
{
	int tabTaille[] = { 5,10,15,20,25,30,50,100,1000};//tableau de toutes les tailles 
	//METHODOLOGIE EXPLIQUEE POUR TRIS CROISSANT/DECROISSANT/NON TRIES
	// cette m�thode se r�p�te pour les trois boucles r�alisant tris croissant/decroissant/non tries
	// les trois FOR sont calibr�s selon le nombre de cases du tableau tabTaille
	// Pour chaque tour de boucles le programme parcourt le tabTaille pour donner la tailles des tableaux
	// Pour chaque tour de boucles, le programme r�alise les estimations de temps pour tous les tris
	//01 - creation et remplissage du tableau selon ordonnancement
	//02 - demarrage du temps
	//03 - methode de tris appel�e
	//04 - fin du temps
	//05 - calcul et affichage du temps en ns
	//06 - suppression de l'allocation m�moire avec delete
	cout << "------- TRIS SUR TABLEAU TRIE CROISSANT -------" << endl;
	for (int i = 0; i < sizeof(tabTaille) / sizeof(tabTaille[0]); i++)
	{
		cout << "TAILLE : " << tabTaille[i] << " -----" << "  mesure en ns" << endl;
		//methode tri bulle
		int* tabTri = TabCroissant(tabTaille[i]);//creation et remplissage du tableau selon ordonnancement
		auto start = chrono::steady_clock::now();//demarrage du temps 
		triBulles(tabTri, tabTaille[i]);//methode de tris appel�e
		auto end = chrono::steady_clock::now();//fin du temps
		cout << "Tri bulle : "//calcul et affichage du temps en ns
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;
				
		//methode tri selection
		tabTri = TabCroissant(tabTaille[i]);//creation et remplissage du tableau selon ordonnancement
		start = chrono::steady_clock::now();
		triSelection(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri selection : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;
		
		//methode tri insertion
		tabTri = TabCroissant(tabTaille[i]);//creation et remplissage du tableau selon ordonnancement
		start = chrono::steady_clock::now();
		triInsertion(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri insertion : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;
				 
		//methode tri fusion
		tabTri = TabCroissant(tabTaille[i]);
		start = chrono::steady_clock::now();
		triFusion(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri fusion : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;
			
		//methode segmentation
		tabTri = TabCroissant(tabTaille[i]);
		start = chrono::steady_clock::now();
		triSegmentation(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri Segmentation : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;
				
		//methode tri sort
		tabTri = TabCroissant(tabTaille[i]);
		start = chrono::steady_clock::now();
		sort(tabTri, tabTri + tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri STL/sort : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;
	}
	
	cout << endl << endl;
	cout << "------- TRIS SUR TABLEAU TRIE DECROISSANT -------" << endl << endl;
	//METHODOLOGIE EXPLIQUEE POUR TRIS CROISSANT/DECROISSANT/NON TRIES
	// cette m�thode se r�p�te pour les trois boucles r�alisant tris croissant/decroissant/non tries
	// les trois FOR sont calibr�s selon le nombre de cases du tableau tabTaille
	// Pour chaque tour de boucles le programme parcourt le tabTaille pour donner la tailles des tableaux
	// Pour chaque tour de boucles, le programme r�alise les estimations de temps pour tous les tris
	//01 - creation et remplissage du tableau selon ordonnancement
	//02 - demarrage du temps
	//03 - methode de tris appel�e
	//04 - fin du temps
	//05 - calcul et affichage du temps en ns
	//06 - suppression de l'allocation m�moire avec delete
	for (int i = 0; i < sizeof(tabTaille) / sizeof(tabTaille[0]); i++)
	{
		cout << "TAILLE : " << tabTaille[i] << " -----" << "  mesure en ns" << endl;
		//methode tri bulle
		int* tabTri = TabDecroissant(tabTaille[i]);
		auto start = chrono::steady_clock::now();
		triBulles(tabTri, tabTaille[i]);
		auto end = chrono::steady_clock::now();
		cout << "Tri bulle : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode tri selection
		tabTri = TabDecroissant(tabTaille[i]);
		start = chrono::steady_clock::now();
		triSelection(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri selection : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode tri insertion
		tabTri = TabDecroissant(tabTaille[i]);
		start = chrono::steady_clock::now();
		triInsertion(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri insertion : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode tri fusion
		tabTri = TabDecroissant(tabTaille[i]);
		start = chrono::steady_clock::now();
		triFusion(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri fusion : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode segmentation
		tabTri = TabDecroissant(tabTaille[i]);
		start = chrono::steady_clock::now();
		triSegmentation(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri Segmentation : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode tri sort
		tabTri = TabDecroissant(tabTaille[i]);
		start = chrono::steady_clock::now();
		sort(tabTri, tabTri + tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri STL/sort : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;
	}

	cout << endl << endl;
	cout << "------- TRIS SUR TABLEAU NON TRIE  -------" << endl << endl;
	//METHODOLOGIE EXPLIQUEE POUR TRIS CROISSANT/DECROISSANT/NON TRIES
	// cette m�thode se r�p�te pour les trois boucles r�alisant tris croissant/decroissant/non tries
	// les trois FOR sont calibr�s selon le nombre de cases du tableau tabTaille
	// Pour chaque tour de boucles le programme parcourt le tabTaille pour donner la tailles des tableaux
	// Pour chaque tour de boucles, le programme r�alise les estimations de temps pour tous les tris
	//01 - creation et remplissage du tableau selon ordonnancement
	//02 - demarrage du temps
	//03 - methode de tris appel�e
	//04 - fin du temps
	//05 - calcul et affichage du temps en ns
	//06 - suppression de l'allocation m�moire avec delete
	for (int i = 0; i < sizeof(tabTaille) / sizeof(tabTaille[0]); i++)
	{
		cout << "TAILLE : " << tabTaille[i] << " -----" << "  mesure en ns" << endl;
		//methode tri bulle
		int* tabTri = TabNonTri�(tabTaille[i]);
		auto start = chrono::steady_clock::now();
		triBulles(tabTri, tabTaille[i]);
		auto end = chrono::steady_clock::now();
		cout << "Tri bulle : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode tri selection
		tabTri = TabNonTri�(tabTaille[i]);
		start = chrono::steady_clock::now();
		triSelection(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri selection : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode tri insertion
		tabTri = TabNonTri�(tabTaille[i]);
		start = chrono::steady_clock::now();
		triInsertion(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri insertion : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode tri fusion
		tabTri = TabNonTri�(tabTaille[i]);
		start = chrono::steady_clock::now();
		triFusion(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri fusion : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode segmentation
		tabTri = TabNonTri�(tabTaille[i]);
		start = chrono::steady_clock::now();
		triSegmentation(tabTri, tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri Segmentation : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;

		//methode tri sort
		tabTri = TabNonTri�(tabTaille[i]);
		start = chrono::steady_clock::now();
		sort(tabTri, tabTri + tabTaille[i]);
		end = chrono::steady_clock::now();
		cout << "Tri STL/sort : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count() << endl;
		delete[] tabTri;
	}
	
	return 0;
}
