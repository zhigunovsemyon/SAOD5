#pragma once
#include <stdlib.h> /*size_t; free(); *alloc()*/

// Тип данных
#define DATATYPE int

/*Определение неполного типа данных*/
typedef struct _SortedVec SortedVec;

// Коды ошибок
enum ErrorCodes {
	ERR_NO,	    // Без ошибок
	ERR_MALLOC, // Ошибка malloc
	ERR_NOSUCHELEMENT // Нет места под новый сегмент
};

// Создание вектора в памяти
SortedVec *SortedVecInit(void);

// Очистка памяти
void SortedVecDeInit(SortedVec **const ptr);

// Устанавливает элемент по адресу ptr равным элементу структруры по переданному индексу
enum ErrorCodes SortedVecGet(SortedVec const *const, long index, DATATYPE *const ptr);

/*Вставка массива чисел Array размера ArrSize в вектор*/
size_t SortedVecInsertArray(SortedVec *const, size_t const ArrSize,
			    DATATYPE const *const Array);
