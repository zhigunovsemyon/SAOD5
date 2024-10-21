#include "sortvec.h" //includes stdlib.h
#include <stdbool.h> // true, false

/*Сокрытая реализация типа данных*/
typedef struct _SortedVec {
	long max_size; // Максимальная вместимость набора
	long cur_size; // Текущий размер набора
	DATATYPE *data;
} SortedVec;

/*Возврат true при успехе, false при ошибке выделения памяти*/
static bool SortedVecResize_(SortedVec *const this, long const newsize) {
	if (this->max_size > newsize)
		return true;

	/*Перевыделение памяти, её проверка*/
	DATATYPE *newdata = (DATATYPE *)realloc(
		this->data, (size_t)(newsize * (long)sizeof(DATATYPE)));
	if (newdata == NULL)
		return false;

	/*Перестановка раземеров, указателей*/
	this->max_size = newsize;
	this->data = newdata;
	return true;
}

#define DEFAULT_SIZE 100 // Размер инита по умолчанию
SortedVec *SortedVecInit(void) {
	// Выделение памяти под дескриптор
	SortedVec *ptr = (SortedVec *)malloc(sizeof(SortedVec));
	if (!ptr) // проверка памяти
		return NULL;
	// выделение памяти под данные
	ptr->data = (DATATYPE *)calloc(DEFAULT_SIZE, sizeof(DATATYPE));
	if (!ptr->data) { // проверка памяти
		free(ptr);
		return NULL;
	}
	// Задание максимального размера
	ptr->max_size = DEFAULT_SIZE;
	// Задание текущего нулевого размера
	ptr->cur_size = 0;

	// Возврат памяти
	return ptr;
}

// Очистка памяти
void SortedVecDeInit(SortedVec **ptr) {
	// Освобождение памяти
	free((*ptr)->data);
	free(*ptr);
	// Перестановка указателя на NULL
	*ptr = NULL;
}

int SortedVecInsertArray(SortedVec *const this, size_t const ArrSize,
			 DATATYPE const *const Array) {
	return ArrSize;
}