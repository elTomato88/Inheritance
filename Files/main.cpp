#include <iostream>
#include <fstream>
using std::cin;
using std::cout;
using std::endl;
//#define WRITE_TO_FILE
#define READ_FROM_FILE
void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	//1 создаем поток
	std::ofstream fout;
	//2 открываем поток
	fout.open("file.txt", std::fstream::app);// app append
	//3 пишем в поток
	fout << "Hello Files!";
	//4 потоки как холодильник. Если он был открыт, надо обязательно закрыть
	fout.close();
	system("notepad file.txt");
#endif // WRITE_TO_FILE
	//1 Создаем и открываем поток
	std::ifstream fin("File.txt");
	//2 Проверяем открылся ли поток
	if (fin.is_open())
	{
		while (!fin.eof()) //eof - end of file
		{
			const int SIZE = 256;
			char sz_buffer[SIZE] = {};
			//fin >> sz_buffer;
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
		fin.close(); // закрываем
	}
	else
	{
		std::cerr << "Error: file nod found" << endl;
	}
}