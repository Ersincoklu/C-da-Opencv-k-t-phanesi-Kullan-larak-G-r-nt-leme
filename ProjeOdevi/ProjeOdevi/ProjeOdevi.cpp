#include <opencv2\opencv.hpp>
#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <conio.h>
#include <thread>

using namespace cv;
using namespace std;

vector<string> gorselList; //Resim isimlerini tutan vektorümü tanýmladým
int secilenVersion = 1; //Program versiyonlarý için bir versiyon tanýmladým

void parlaklikDurumu(int version, string gorsel, int durum)  //resim parlaklýðý için bir fonksiyon tanýmladým bu fonksiyonda versiyon,görsel ve 
{															 //durum kontrolleri için parametreler oluþturdum
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
			namedWindow("Yüksek Kontrast", CV_WINDOW_AUTOSIZE);
			imshow("Yüksek Kontrast", img1);
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
			namedWindow("Yüksek Kontrast", CV_WINDOW_AUTOSIZE);
			imshow("Yüksek Kontrast", img1);
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
			namedWindow("Yüksek Kontrast", CV_WINDOW_AUTOSIZE);
			imshow("Yüksek Kontrast", img1);
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

void Thread_ResimKontrolEt(string imagepath) //resim kontrol için thread oluþturdum
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
	gorselList.push_back("Manzara"); //tanýmladýðým vektörüme resim isimlerini ekledim (pushback ile veriyi dizinin sonuna ekliyorum)
	gorselList.push_back("Bebek");
	gorselList.push_back("Galatasaray");
	gorselList.push_back("Memleket");

	int islem;
	string dosyaAdi = ""; //dosyanýn adýný tutmak için string tipinde deðiþken tutuyoruz

	cout << "Lutfen 1 , 2 veya 3 'uncu versiyondan birini seciniz..." << endl;
	cin >> secilenVersion;

	while (dosyaAdi == "") { //dosya adý girilene kadar tekrar dön

		cout << "Acmak istediginiz resim adini (GALATASARAY,MANZARA,BEBEK,MEMLEKET) virgulle ayirarak birden fazla dosya adi girebilirsiniz" << endl;
		cin >> dosyaAdi;
	}

sor:
	cout << endl;
	cout << endl << "Resim Acmak icin 1'e basiniz....\n" << endl;
	cout << "Resim Parlaklik Ayari icin 2'ye basiniz....\n" << endl;
	cout << "Resim Kontrast Ayari icin 3'e basiniz....\n\n" << endl;
	cin >> islem;

	if (islem < 1 || islem > 3) //iþlemler 1-3 arasý deðilse tekrar sor
	{
		goto sor;
	}

	if (islem == 1)
	{
		string bolme = ","; // dosya isimlerini ayýrmak için kullanýlan simge
		size_t pos = 0; // simgenin pozisyonunu tutan deðer
		string token; // dosya ismini tutan deðer

		while ((pos = dosyaAdi.find(bolme)) != string::npos) { // dosyaAdi'nda simge pozisyonu varken dön

			token = dosyaAdi.substr(0, pos); // dosyaAdi'ndan karþýlaþýlan ilk dosya adýný çýkart

			std::cout << token << std::endl; // bilgi amaçlý ekrana yazdýr

			dosyaAdi.erase(0, pos + bolme.length()); // karþýlaþýlan ilk dosya adýný dosyaAdi'ndan çýkar

			thread t1(Thread_ResimKontrolEt, token + ".jpg"); // dosya adýný thread'e gönder
			t1.join(); // thead'i çalýþtýr
		}

		waitKey(0);
		goto sor; // menüye dön
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

		parlaklýksor:

			int resimSec;

			cout << "\n\n" << endl;

			for (int i = 0; i < gorselList.size(); i++) { //yaptýðým bu döngüde size komutu ile vectördeki eleman boyutunu okudum
				cout << gorselList.operator[](i) << " icin " << (i + 1) << "'e Basiniz....\n" << endl; //operator ile vektördeki belirli bir elamana eriþmek için kullandým
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
				goto parlaklýksor;
			}
		}

		else if (ParlaklikIslem == 2)
		{

		parlaklýksor2:

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
				goto parlaklýksor2;
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