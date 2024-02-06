//Електронні Пристрої :
//	Базовий клас : ЕлектроннийПристрій
//		Похідний клас : Смартфон
//			Похідний клас : ФлагманськийСмартфон
//		Похідний клас : Ноутбук
//			Похідний клас : ГеймерськийНоутбук
//				Похідний клас : ПрофесійнийГеймерськийНоутбук

#include <iostream>
using namespace std;

class Electronics {
	private:
		string name;
		bool isTurned;
	public:
		Electronics(string name) {
			this->name = name;
			this->isTurned = 0;
		}
		void displayName() {
			cout << "This device`s name is " << this->name << endl;
		}
		void on(){
			if (this->isTurned == 0) {
				this->isTurned = 1;
				cout << this->name << " is turned now" << endl;
			}
			else {
				cout << this->name << " is already turned" << endl;
			}
		}
		void off() {
			if (this->isTurned == 1) {
				this->isTurned = 0;
				cout << this->name << " is turned off now" << endl;
			}
			else {
				cout << this->name << " is already turned off" << endl;
			}
		}
};
class Smartphone : public Electronics {
	private:
		string model;
	public:
		Smartphone (string name, string model)
			: Electronics(name) {
			this->model = model;
		}
		void displayModel() {
			cout << "This device is " << this->model << " model" << endl;
		}
};
class Flagman : public Smartphone {
	private:
		int fpsInBrawlStars;
	public:
		Flagman(string name, string model, int fps)
			:Smartphone(name, model) {
			this->fpsInBrawlStars = fps;
		}
		void displayFps() {
			cout << "This device has " << this->fpsInBrawlStars << " fps in Brawl Stars";
		}
};
class Notebook : public Electronics {
	private:
		int resolution;
	public:
		Notebook(string name, int res)
			: Electronics(name) {
			this->resolution = res;
		}
		void displayResolution() {
			cout << "This device`s resolution is " << this->resolution << endl;
		}
};
class GamerNotebook : public Notebook {
	private:
		int fpsInGenshinImpact;
	public:
		GamerNotebook(string name, int res, int fps)
			: Notebook(name, res) {
			this->fpsInGenshinImpact = fps;
		}
		void displayFps() {
			cout << "This device has " << this->fpsInGenshinImpact << " in Genshin Impact" << endl;
		}
};
class ProfNotebook : public GamerNotebook {
	private:
		int amoutOfRam;
		int cpuCores;
	public:
		ProfNotebook(string name, int res, int fps, int ram, int cores)
			: GamerNotebook(name, res, fps) {
			this->amoutOfRam = ram;
			this->cpuCores = cores;
		}
		void specs() {
			cout << "This device has " << this->amoutOfRam << " amount gigs of ram" << endl;
			cout << "This device has " << this->cpuCores << " amount of cpu cores" << endl;
		}
};
int main() {
	Flagman Poco("Poco", "X3 Pro", 120);
	Poco.on();
	Poco.on();
	Poco.off();
	Poco.off();
	Poco.displayName();
	Poco.displayModel();
	Poco.displayFps();
	cout << endl << endl;
	ProfNotebook Asus("Asus Zenbook 5", 1920, 60, 32, 8);
	Asus.displayName();
	Asus.displayResolution();
	Asus.displayFps();
	Asus.specs();
}