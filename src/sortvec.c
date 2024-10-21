#include "sortvec.h" //includes stdlib.h
#include <stdbool.h> // true, false
#include <stdlib.h>

/*Сокрытая реализация типа данных*/
typedef struct _SortedVec {
	long max_size; // Максимальная вместимость набора
	long cur_size;	 // Текущий размер набора
	DATATYPE *data;	 // Область памяти
	DATATYPE *begin; // Указатель на первый действительный элемент
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
	// Массив пустой -- начала нет
	ptr->begin = NULL;

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

// Внутренняя функция вставки элемента в массив достаточного размера
static void SortedVecInsert_(SortedVec *const this, DATATYPE const Element) {
	/*Если вектор пустой, обозначается начало посреди области памяти*/
	if (this->cur_size == 0) {
		this->cur_size++;
		this->begin = this->data + this->max_size / 2;
		*this->begin = Element;
	}
}

int SortedVecInsertArray(SortedVec *const this, size_t const ArrSize,
			 DATATYPE const *const Array) {
	/*Если места в массиве не было достаточно, а расширение не удалось,
	 * ни один элемент не был вставлен, что и возвращается*/
	if (!SortedVecResize_(this, this->cur_size + (long)ArrSize))
		return 0;

	/*Перебор массива, вставка каждого элемента*/
	for (size_t i = 0; i < ArrSize; ++i)
		SortedVecInsert_(this, Array[i]);
	return ArrSize; // Возврат числа вставленных элементов
}
