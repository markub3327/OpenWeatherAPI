#include <iostream>
#include <fstream>
#include "downloader.hpp"
#include "nlohmann/json.hpp"

using std::cout;
using nlohmann::json;


void show (const Downloader& dl) {

	auto response = dl.download();

	cout << "Mesto: " << response["name"] << std::endl;
	cout << "Teplota: " << response["main"]["temp"] << std::endl;
	cout << "Pocitova teplota: " << response["main"]["feels_like"] << std::endl;
	cout << "Tlak: " << response["main"]["pressure"] << std::endl;
	cout << "Vlhkost: " << response["main"]["humidity"] << std::endl;
	cout << "Rychlost vetra: " << response["wind"]["speed"] << std::endl;
	cout << "Oblacnost: " << response["clouds"]["all"] << std::endl << std::endl;
}


int main(int argv, char** argc)
{
	Downloader dl("https://api.openweathermap.org/data/2.5/weather?lat=48.37775&lon=17.586211&appid=189a2ad660780f16934f49ac54c3007b&units=metric");
	
	show(dl);

	return 0;
}