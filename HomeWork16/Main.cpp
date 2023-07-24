# include <iostream>
# include <cstdlib>
# include <ctime>
# include <algorithm>

// Глобальные переменные
int A, B; // Переменные для хранения начала и конца диапазона значений элементов массива
const short level = 3, rows = 5, cols = 5; // Размеры 3D-матрицы (уровни, строки, столбцы)
int matrix[level][rows][cols]{}; // Объявляем и инициализируем 3D-матрицу нулями

int Range() { // Функция для ввода и проверки значений начала и конца диапазона
	std::cout << "Range start -> ";
	std::cin >> A;
	std::cout << "End of range -> ";
	std::cin >> B;
	while (B < A) { // Цикл проверки введённого пользователем диапазона
		std::cout << "Input error!\nThe end of the range cannot be less than the start\nRange start -> ";
		std::cin >> A;
		std::cout << "End of range -> ";
		std::cin >> B;
	}
	return A, B;
}

void matrix_Output(short k, short i, short j) { // Функция вывода элемента матрицы в строку
	switch (j) {
	case 0:
		std::cout << "{\t" << matrix[k][i][j] << '\t';
		break;
	case rows - 1:
		std::cout << matrix[k][i][j] << "\t}";
		break;
	default:
		std::cout << matrix[k][i][j] << '\t';
	}
}

int main() {
	// Задача 1. Среднеарифметическое элементов массива
	std::cout << "Task 1. Arithmetic mean of array elements\n\n";
	const short size = 10; // Размер массива
	int array[size]{}; // Объявление и инициализация массива
	double arithmetic_Mean; // Переменная для хранения значения среднего арифметического элеменотов массива
	short couter = 0; // Переменная для хранения кол-ва элементов массива, меньших среднего арифметического
	int sum = 0; // Переменная для хранения суммы элементов массива
	std::cout << "Enter a range of array element values:\n";
	Range();
	std::cout << "\nSource array:\n";
	srand(time(NULL));
	for (short i = 0; i < size; i++) {
		array[i] = rand() % (B + 1 - A) + A;
		std::cout << array[i] << ", ";
		sum += array[i];
	}
	std::cout << "\b\b.\n";
	arithmetic_Mean = sum / double(size);
	//std::cout << arithmetic_Mean;
	for (short i = 0; i < size; i++)
		if (array[i] < arithmetic_Mean)
			couter++;
	std::cout << "\nArithmetic mean of array elements is " << arithmetic_Mean << "\nArray have " << couter << " elements less than the arithmetic mean\n\n";

	// Задача 2. Сложение матриц
	std::cout << "Task 2. Matrix sum\n\n";
	for (short k = 0; k < level; k++) {
		if (k < level - 1) { // Конструкция для формирования и вывода 2-ух слагаемых 2D-матриц (первые 2 уровня 3D-матрицы)
			std::cout << "Matrix No " << k + 1 << "\nEnter a range of element values:\n";
			Range();
			std::cout << "\nMatrix No " << k + 1 << ":\n";
			srand(time(NULL));
			for (short i = 0; i < rows; i++) { // Вложенный цикл формирования и вывода 2-ух слагаемых матриц
				for (short j = 0; j < cols; j++) {
					matrix[k][i][j] = rand() % (B + 1 - A) + A;
					matrix_Output(k, i, j);
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
		else { // Конструкция для формирования и вывода суммы первых двух матриц (3-ий уровень 3D-матрицы)
			std::cout << "The sum of matrices (No 1 and No 2) is:\n";
			for (short i = 0; i < rows; i++) {
				for (short j = 0; j < cols; j++) {
					matrix[k][i][j] = matrix[k-2][i][j] + matrix[k-1][i][j];
					matrix_Output(k, i, j);
				}
				std::cout << std::endl;
			}
		}
	}
	std::cout << std::endl;

	// Задача 3. Шестизначное число в одномерный массив
	std::cout << "Task 3. Six digit number to array[6]\n\nEnter a six digit number ->";;
	int number, n, result; // Переменные для хранения введённого пользователем шестизначного числа и результата деления
	short number_Counter = 0; // Переменная для хранения кол-ва разрядов числа number
	const short size_Arr = 6; // Размер массива Arr
	short Arr[size_Arr]{}; // Объявление и инициализация нулями массива Arr	
	std::cin >> number;
	n = number;
	do { // Цикл расчёта кол-ва разрядов числа number
		number_Counter++;
		n /= 10;
	} while (n);
	if (number_Counter != size_Arr) // Проверка кол-ва разрядов
		std::cout << "The entered number " << number << " is not a six-digit number!\n";
	else {
		if (number < 0) {
			std::cout << "Entered negative number " << number << " converted to positive number ";
			number *= -1;
			std::cout << number << '\n';
		}
		for (short i = 0; i < size_Arr; i++) { // Цикл формирования массива цифр из шестизначного числа
			result = 0;
			for (short j = 0; j < i; j++) {
				result += Arr[j] * pow(10, i - j);
			}
			Arr[i] = (number / pow(10, size_Arr - i)) * 10 - result;
		}		
		for (short i = 0; i < size_Arr; i++)
			std::cout << Arr[i] << ", ";
		std::cout << "\b\b.\n";
	}

	return 0;
}