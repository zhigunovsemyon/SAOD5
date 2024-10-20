#include "sortvec.h"
#include <stdlib.h> /*size_t; free(); *alloc()*/

#define DEFAULT_SIZE 100 //Размер по умолчанию

/*Сокрытая реализация типа данных*/
typedef struct _SortedVec {
	long max_size; // Максимальная вместимость набора
	long cur_size; // Текущий размер набора
	DATAYPE *data;
} SortedVec;

SortedVec *SortedVecInit(void) {
	// Выделение памяти под дескриптор и данные
	SortedVec *ptr = (SortedVec *)malloc(sizeof(SortedVec) +
					     sizeof(DATAYPE) * DEFAULT_SIZE);
	if (!ptr) // проверка памяти
		return NULL;
	// Задание максимального размера
	ptr->max_size = DEFAULT_SIZE;
	// Задание текущего нулевого размера
	ptr->cur_size = 0;
	// установка указателя на область данных
	ptr->data = (DATAYPE *)(ptr + 1);
	// Возврат памяти
	return ptr;
}

// Очистка памяти
void SortedVecDeInit(SortedVec **ptr) {
	// Освобождение памяти
	free(*ptr);
	// Перестановка указателя на NULL
	*ptr = NULL;
}
