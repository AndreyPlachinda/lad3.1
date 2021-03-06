// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

class Parquet {
public:
	void setParquet() {
		length = 1 + rand() % 50;
		width = 1 + rand() % 50;
	}

	void getParquet() {
		cout << "\nПаркет\n" << "\n Длина паркета: " << length << ", ширина: " << width;
	}

	double areaParquet() {
		areaParq = length * width;
		return areaParq;
	}
private:
	double length;
	double width;
	double areaParq;
};


class Window {
public:
	void setWindow() {
		width = 1 + rand() % 2;
		height = 1 + rand() % 2;
	}

	void getWindow() {
		cout << "\nОкно\n" << "\n Ширина окна: " << width << ", высота: " << height;
	}

	double areaWindow() {
		areaWind = height * width;
		return areaWind;
	}

private:
	double width;
	double height;
	double areaWind;
};

class Room {
public:
	int countColor[3] = { 0,0,0 };
	string colors[3] = { "green", "red", "yellow" };

	void setRoom() {
		length = 1 + rand() % 100;
		width = 1 + rand() % 100;
		height = 3;
		int index = rand() % 3;
		color = colors[index];
		litr = 1 + rand() % 100;
		colculateCountColor(index, litr);
		countWindows = 1 + rand() % 5;
		parquet.setParquet();
		for (int i = 0; i < countWindows; ++i) {
			windows[i].setWindow();
		}
	}

	void getRoom() {
		cout << "\nКомната:\n" << " Длина: " << length << ", ширина: " << width << ", высота: " << height << "\n Цвет: " << color << "\n Количество литров на m2: " << litr << "\n Количество окон: " << countWindows;
		parquet.getParquet();
		for (int i = 0; i < countWindows; ++i) {
			windows[i].getWindow();
		}
	}

	void colculateCountColor(int index, int litrm2) {
		for (int i = 0; i < sizeof(countColor); ++i) {
			if (i == index) {
				countColor[i] = countColor[i] + litrm2;
			}
		}
	}

	int roomVolume() {
		volume = length * width*height;
		return volume;
	}

	int countParquet() {
		areaRoom = length * width;
		countParq = int(areaRoom / parquet.areaParquet());
		return countParq;
	}

private:
	double length;
	double width;
	double height;
	double areaRoom;
	int countParq;
	double volume;
	Window windows[5];
	string color;
	double litr;
	int countWindows;
	Parquet parquet;

};

class Flat {
public:
	void setFlat() {
		cout << "Введите количество комнат в квартире:\n";
		cin >> countRoom;
		room = new Room[countRoom];
		for (int i = 0; i < countRoom; ++i) {
			room[i].setRoom();
		}
	}

	void getFlat()
	{
		cout << "\nКоличество комнат: " << countRoom << "\n";
		for (int i = 0; i < countRoom; ++i)
		{
			cout << "\nКомната №:" << i + 1;
			room[i].getRoom();
		}
	}

	int flatVolume() {
		for (int i = 0; i < countRoom; ++i) {
			volumeFlat += room[i].roomVolume();
		}
		return  volumeFlat;
	}

	int countParquetFlat() {
		for (int i = 0; i < countRoom; ++i) {
			countParquetFl += room[i].countParquet();
		}
		return  countParquetFl;
	}

public:
	int countRoom;
	double volumeFlat = 0;
	int countParquetFl;
	Room *room;
};

class House {
public:
	void setHouse() {
		cout << "\nКоличество этажей:\n";
		cin >> countFloor;
		cout << "\nКоличество квартир на этаже:\n";
		cin >> countFlat;
		flats = new Flat[countFlat*countFloor];
		for (int i = 0; i < countFlat*countFloor; ++i) {
			flats[i].setFlat();
		}
	}

	void getHouse() {
		cout << "Количество квартир в доме:\n" << countFlat * countFloor;
		for (int i = 0; i < countFlat*countFloor; ++i) {
			cout << "\nКвартира № " << i + 1;
			flats[i].getFlat();
		}
		for (int i = 0; i < countFlat*countFloor; ++i) {
			volumeHouse += flats[i].flatVolume();
		}
		for (int i = 0; i < countFlat*countFloor; ++i) {
			countParqHouse += flats[i].countParquetFlat();
		}
		for (int i = 0; i < countFloor; ++i) {
			heigthHouse = heigthHouse + 3;
		}
		cout << "\n Высота дома:\n" << heigthHouse;
		cout << "\nОбъем дома:\n" << volumeHouse;
		cout << "\nКоличество паркета на дом:\n" << countParqHouse;
	}
private:
	int countFloor;
	int countFlat;
	int heigthHouse = 0;
	int volumeHouse = 0;
	int countParqHouse = 0;
	Flat *flats;
};

class Street {
public:
	void setStreet() {
		cout << "Количество домов на улице: \n";
		cin >> countHouse;
		houses = new House[countHouse];
		for (int i = 0; i < countHouse; ++i) {
			houses[i].setHouse();
		}
	}

	void getStreet() {
		for (int i = 0; i < countHouse; ++i) {
			cout << "\nДом № " << i + 1;
			houses[i].getHouse();
		}
	}

private:
	int countHouse;
	House *houses;
};

int main(int argc, const char * argv[]) {
	setlocale(LC_CTYPE, "rus");
	Street street;
	street.setStreet();
	street.getStreet();
	return 0;
}