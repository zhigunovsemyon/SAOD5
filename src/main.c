#include <stdio.h>
#include <stdlib.h>
/*Задание: сделать упорядоченный набор элементов на массиве
Перечень операций:
	получение элемента по индексу;
	принадлежность элемента вектору
	изменение элемента;
	арифметические операции над векторами: поэлементное
		сложение, вычитание, умножение, деление;
	операции определения нижней и верхней границ индекса;
	размер вектора;
	инициализация вектора и его очистка;
	слияние векторов;
	//
	случайное заполнение структуры данных;
	заполнение из файла;
	сохранение структуры в файл;
	необходимо уметь обосновать выбранные размеры переменных
		и временных буферов.
*/

// Тип данных
#define DATAYPE int

typedef struct {
	size_t max_size; // Максимальная вместимость набора
	size_t cur_size; // Текущий размер набора
	DATAYPE *data;
} SortedVec;

//Коды ошибок
enum ErrorCodes {
	ERR_NO, //Без ошибок
	ERR_MALLOC,//Ошибка malloc
	ERR_SPACE //Нет места под новый сегмент
};

// Создание вектора в памяти
SortedVec *SortedVecInit(size_t const max_size) {
	// Выделение памяти под дескриптор и данные
	SortedVec *ptr = (SortedVec *)malloc(sizeof(SortedVec) +
					     sizeof(DATAYPE) * max_size);
	if (!ptr) // проверка памяти
		return nullptr;
	// Задание максимального размера
	ptr->max_size = max_size;
	// Задание текущего нулевого размера
	ptr->cur_size = 0;
	// установка указателя на область данных
	ptr->data = (DATAYPE *)(ptr + 1);
	// Возврат памяти
	return ptr;
}

//Очистка памяти
void SortedVecDeInit(SortedVec **ptr) {
	// Освобождение памяти
	free(*ptr);
	// Перестановка указателя на NULL
	*ptr = nullptr;
}



int main(void) {
	SortedVec *vec = SortedVecInit(100);
	if (vec == nullptr)
		return ERR_MALLOC;
	SortedVecDeInit(&vec);
	return ERR_NO;
}
