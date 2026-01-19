/* Citation and Sources...
-----------------------------------------------------------
Workshop 01
Module: io
Filename: io.h
-----------------------------------------------------------
Author: Josh Oppong
Student number: 118395201
Email: joppong5@myseneca.ca
Subject: OOP244NCC
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my work for function whatever.
-----------------------------------------------------------
*/
#pragma once
#ifndef SENECA_IO_H
#define SENECA_IO_H
#include <cstdio>
namespace seneca {
	struct PhoneRec
	{
		char first_name[15];
		char last_name[25];
		long long phone_number;

	};

	void read(char*);
	void print(long long);
	void print(const PhoneRec& rec, size_t& row, const char* filter = nullptr);
	bool read(PhoneRec& rec, FILE* fp);
	void print(PhoneRec* recs[], size_t size, const char* filter = nullptr);
	void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size);
	void sort(PhoneRec* ptrs[], size_t size, bool byLastName);
}
#endif // !SENECA_IO_H