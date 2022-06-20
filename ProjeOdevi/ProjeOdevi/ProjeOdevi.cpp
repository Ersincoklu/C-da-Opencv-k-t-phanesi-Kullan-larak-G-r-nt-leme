#include <opencv2\opencv.hpp>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <conio.h>
#include <thread>

using namespace cv;
using namespace std;

vector<string> gorselList; //Resim isimlerini tutan vektor�m� tan�mlad�m
int secilenVersion = 1; //Program versiyonlar� i�in bir versiyon tan�mlad�m

void parlaklikDurumu(int version, string gorsel, int durum)  //resim parlakl��� i�in bir fonksiyon tan�mlad�m bu fonksiyonda versiyon,g�rsel ve 
{															 //durum kontrolleri i�in parametreler olu�turdum
	Mat img = imread(gorsel + ".jpg");
	if (img.empty())
	{
		cout << "Resim yuklenemedi" << endl;
		system("Pause");
	}

	Mat img1;
	namedWindow("Orjinal Resim", CV_WINDOW_AUTOSIZE);
	imshow("Orjinal Resim", img);

	if (version == 1) {
		switch (durum)
		{
		case 1:
			img1 = img + Scalar(100, 100, 100);
			namedWindow("Daha Parlak", CV_WINDOW_AUTOSIZE);
			imshow("Daha Parlak", img1);
			break;
		case 2:
			img1 = img - Scalar(75, 75, 75);
			namedWindow("Daha Koyu", CV_WINDOW_AUTOSIZE);
			imshow("Daha Koyu", img1);
			break;
		}
	}

	else if (version == 2) {
		switch (durum)
		{
		case 1:
			img1 = img + Scalar(50, 50, 50);
			namedWindow("Daha Parlak", CV_WINDOW_AUTOSIZE);
			imshow("Daha Parlak", img1);
			break;
		case 2:
			img1 = img - Scalar(50, 50, 50);
			namedWindow("Daha Koyu", CV_WINDOW_AUTOSIZE);
			imshow("Daha Koyu", img1);
			break;
		}
	}

	else if (version == 3) {
		switch (durum)
		{
		case 1:
			img1 = img + Scalar(25, 25, 25);
			namedWindow("Daha Parlak", CV_WINDOW_AUTOSIZE);
			imshow("Daha Parlak", img1);
			break;
		case 2:
			img1 = img - Scalar(25, 25, 25);
			namedWindow("Daha Koyu", CV_WINDOW_AUTOSIZE);
			imshow("Daha Koyu", img1);
			break;
		}
	}


	waitKey(0);
	destroyAllWindows();
}

void kontrastDurumu(int version, string gorsel, int durum)
{
	Mat img = imread(gorsel + ".jpg");
	if (img.empty())
	{
		cout << "Resim yuklenemedi" << endl;
		system("Pause");
	}

	Mat img1;
	namedWindow("Orjinal Resim", CV_WINDOW_AUTOSIZE);
	imshow("Orjinal Resim", img);

	if (version == 1)
	{
		switch (durum)
		{
		case 1:
			img.convertTo(img1, -1, 2, 0);
			namedWindow("Y�ksek Kontrast", CV_WINDOW_AUTOSIZE);
			imshow("Y�ksek Kontrast", img1);
			break;
		case 2:
			img.convertTo(img1, -1, 0.5, 0);
			namedWindow("Alcak Kontrast", CV_WINDOW_AUTOSIZE);
			imshow("Alcak Kontrast", img1);
			break;
		}
	}
	else if (version == 2)
	{
		switch (durum)
		{
		case 1:
			img.convertTo(img1, -1, 4, 0);
			namedWindow("Y�ksek Kontrast", CV_WINDOW_AUTOSIZE);
			imshow("Y�ksek Kontrast", img1);
			break;
		case 2:
			img.convertTo(img1, -1, 0.2, 0);
			namedWindow("Alcak Kontrast", CV_WINDOW_AUTOSIZE);
			imshow("Alcak Kontrast", img1);
			break;
		}
	}
	else if (version == 3)
	{
		switch (durum)
		{
		case 1:
			img.convertTo(img1, -1, 6, 0);
			namedWindow("Y�ksek Kontrast", CV_WINDOW_AUTOSIZE);
			imshow("Y�ksek Kontrast", img1);
			break;
		case 2:
			img.convertTo(img1, -1, 0.1, 0);
			namedWindow("Alcak Kontrast", CV_WINDOW_AUTOSIZE);
			imshow("Alcak Kontrast", img1);
			break;
		}
	}
	waitKey(0);
	destroyAllWindows();
}

void Thread_ResimKontrolEt(string imagepath) //resim kontrol i�in thread olu�turdum
{
	cout << imagepath + " alindi " << endl;
	Mat img = imread(imagepath);
	if (img.empty())
	{
		cout << "Resim yuklenemedi (Resim ismini kontrol ediniz)" << endl;
		system("Pause");
	}
	else
	{
		cout << imagepath + " yuklendi " << endl;
		imshow("", img);
		waitKey(0);
	}
}

int main()
{
	gorselList.push_back("Manzara"); //tan�mlad���m vekt�r�me resim isimlerini ekledim (pushback ile veriyi dizinin sonuna ekliyorum)
	gorselList.push_back("Bebek");
	gorselList.push_back("Galatasaray");
	gorselList.push_back("Memleket");

	int islem;
	string dosyaAdi = ""; //dosyan�n ad�n� tutmak i�in string tipinde de�i�ken tutuyoruz

	cout << "Lutfen 1 , 2 veya 3 'uncu versiyondan birini seciniz..." << endl;
	cin >> secilenVersion;

	while (dosyaAdi == "") { //dosya ad� girilene kadar tekrar d�n

		cout << "Acmak istediginiz resim adini (GALATASARAY,MANZARA,BEBEK,MEMLEKET) virgulle ayirarak birden fazla dosya adi girebilirsiniz" << endl;
		cin >> dosyaAdi;
	}

sor:
	cout << endl;
	cout << endl << "Resim Acmak icin 1'e basiniz....\n" << endl;
	cout << "Resim Parlaklik Ayari icin 2'ye basiniz....\n" << endl;
	cout << "Resim Kontrast Ayari icin 3'e basiniz....\n\n" << endl;
	cin >> islem;

	if (islem < 1 || islem > 3) //i�lemler 1-3 aras� de�ilse tekrar sor
	{
		goto sor;
	}

	if (islem == 1)
	{
		string bolme = ","; // dosya isimlerini ay�rmak i�in kullan�lan simge
		size_t pos = 0; // simgenin pozisyonunu tutan de�er
		string token; // dosya ismini tutan de�er

		while ((pos = dosyaAdi.find(bolme)) != string::npos) { // dosyaAdi'nda simge pozisyonu varken d�n

			token = dosyaAdi.substr(0, pos); // dosyaAdi'ndan kar��la��lan ilk dosya ad�n� ��kart

			std::cout << token << std::endl; // bilgi ama�l� ekrana yazd�r

			dosyaAdi.erase(0, pos + bolme.length()); // kar��la��lan ilk dosya ad�n� dosyaAdi'ndan ��kar

			thread t1(Thread_ResimKontrolEt, token + ".jpg"); // dosya ad�n� thread'e g�nder
			t1.join(); // thead'i �al��t�r
		}

		waitKey(0);
		goto sor; // men�ye d�n
	}

	else if (islem == 2)
	{
		int ParlaklikIslem;
		cout << endl;
		cout << "Daha Parlak Icin 1'e basiniz....\n" << endl;
		cout << "Daha Koyu icin 2'ye basiniz....\n" << endl;
		cin >> ParlaklikIslem;

		if (ParlaklikIslem == 1)
		{

		parlakl�ksor:

			int resimSec;

			cout << "\n\n" << endl;

			for (int i = 0; i < gorselList.size(); i++) { //yapt���m bu d�ng�de size komutu ile vect�rdeki eleman boyutunu okudum
				cout << gorselList.operator[](i) << " icin " << (i + 1) << "'e Basiniz....\n" << endl; //operator ile vekt�rdeki belirli bir elamana eri�mek i�in kulland�m
			}
			cout << "Ana Menuye Donmek Icin 5'e Basiniz...." << endl;
			cin >> resimSec;

			if (resimSec > 0 && resimSec <= gorselList.size())
			{
				string gorsel = gorselList.operator[](resimSec - 1);
				parlaklikDurumu(secilenVersion, gorsel, 1);
			}

			if (resimSec == 5)
			{
				goto sor;
			}

			if (resimSec >= 1 && resimSec <= gorselList.size())
			{
				goto parlakl�ksor;
			}
		}

		else if (ParlaklikIslem == 2)
		{

		parlakl�ksor2:

			int resimSec;

			cout << "\n\n" << endl;

			for (int i = 0; i < gorselList.size(); i++) {
				cout << gorselList.operator[](i) << " icin " << (i + 1) << "'e Basiniz....\n" << endl;
			}

			cout << "Ana Menuye Donmek Icin 5'e Basiniz...." << endl;
			cin >> resimSec;


			if (resimSec > 0 && resimSec <= gorselList.size())
			{
				string gorsel = gorselList.operator[](resimSec - 1);
				parlaklikDurumu(secilenVersion, gorsel, 2);
			}

			if (resimSec == 5)
			{
				goto sor;
			}


			if (resimSec >= 1 && resimSec <= gorselList.size())
			{
				goto parlakl�ksor2;
			}
		}
		goto sor;
		return 0;
	}

	else if (islem == 3)
	{
		int KontrastIslem;
		cout << endl;
		cout << "Yuksek Kontrast Icin 1'e basiniz....\n" << endl;
		cout << "Alcak Kontrast Icin 2'ye basiniz....\n" << endl;
		cin >> KontrastIslem;

		if (KontrastIslem == 1)
		{
		KontrastSor:

			int resimSec;
			cout << "\n\n" << endl;

			for (int i = 0; i < gorselList.size(); i++) {
				cout << gorselList.operator[](i) << " icin " << (i + 1) << "'e Basiniz....\n" << endl;
			}
			cout << "Ana Menuye Donmek Icin 5'e Basiniz...." << endl;
			cin >> resimSec;

			if (resimSec > 0 && resimSec <= gorselList.size())
			{
				string gorsel = gorselList.operator[](resimSec - 1);
				kontrastDurumu(secilenVersion, gorsel, 1);
			}

			if (resimSec == 5)
			{
				goto sor;
			}

			if (resimSec >= 1 && resimSec <= gorselList.size())
			{
				goto KontrastSor;
			}

		}

		if (KontrastIslem == 2)
		{
		KontrastSor2:

			int resimSec;

			cout << "\n\n" << endl;

			for (int i = 0; i < gorselList.size(); i++) {
				cout << gorselList.operator[](i) << " icin " << (i + 1) << "'e Basiniz....\n" << endl;
			}
			cout << "Ana Menuye Donmek Icin 5'e Basiniz...." << endl;
			cin >> resimSec;

			if (resimSec > 0 && resimSec <= gorselList.size())
			{
				string gorsel = gorselList.operator[](resimSec - 1);
				kontrastDurumu(secilenVersion, gorsel, 2);
			}

			if (resimSec == 5)
			{
				goto sor;
			}

			if (resimSec >= 1 && resimSec <= gorselList.size())
			{
				goto KontrastSor2;
			}

		}
	}
}