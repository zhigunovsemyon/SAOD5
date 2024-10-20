#include "sortvec.h"
#include <stdlib.h> /*size_t; free(); *alloc()*/

SortedVec *SortedVecInit(size_t const max_size) {
	// Выделение памяти под дескриптор и данные
	SortedVec *ptr = (SortedVec *)malloc(sizeof(SortedVec) +
					     sizeof(DATAYPE) * max_size);
	if (!ptr) // проверка памяти
		return NULL;
	// Задание максимального размера
	ptr->max_size = max_size;
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
