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
enum ErrorCodes SortedVecInsertArray(SortedVec *const, size_t const ArrSize,
			    DATATYPE const *const Array);

// Удаление элемента, равного Element
enum ErrorCodes SortedVecRemoveElement(SortedVec *const, DATATYPE const Element);

// Геттер размера вектора
long SortedVecSize(SortedVec const *const this);

// Добавление в один вектор элементов из другого
enum ErrorCodes SortedVecAddToThis(SortedVec *const this, SortedVec const *const other);