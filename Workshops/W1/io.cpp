/* Citation and Sources...
-----------------------------------------------------------
Workshop 01
Module: io
Filename: io.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "io.h"

#include <iostream>
#include <iomanip>
#include <cstdio>

using namespace std;

namespace seneca
{
	void read(char* name)
	{
		cout << "name>\n ";
		cin >> name;
	}
	void print(long long phone)
	{
		cout
			<< "("
			<< setw(3) << setfill('0') << phone / 10000000
			<< ") "
			<< setw(3) << setfill('0') << (phone / 10000) % 1000
			<< "-"
			<< setw(4) << setfill('0') << phone % 10000;
		
	}
	void print(const PhoneRec& rec, size_t& row, const char* filter)
	{
		bool matches = false;
		if (!filter) matches = true;
		else if (strstr(rec.first_name, filter) || strstr(rec.last_name, filter))
			matches = true;
		if (matches) {
			cout << row << ": "
				<< rec.first_name
				<< " "
				<< rec.last_name
				<< " ";
			print(rec.phone_number);
			cout << endl;
			row++;
		}
	}

	bool read(PhoneRec& rec, FILE* fp)
	{	int count = fscanf(fp, "%15s %25s %lld", rec.first_name, rec.last_name, &rec.phone_number);
		return count == 3;
	}

	void print(PhoneRec* recs[], size_t size, const char* filter)
	{
		size_t row = 1;
		for (size_t i = 0; i < size; i++)
		{
			print(*recs[i], row, filter);
		}
	
	}

	void setPointers(PhoneRec* ptrs[], PhoneRec recs[], size_t size)
	{
		for (size_t i = 0; i < size; i++)
		{
			ptrs[i] = &recs[i];
		}
	}

	void sort(PhoneRec* ptrs[], size_t size, bool byLastName)
	{
		for (size_t i = 0; i < size - 1; i++)
		{
			for (size_t j = i + 1; j < size; j++)
			{
				if (byLastName)
				{
					if (strcmp(ptrs[i]->last_name, ptrs[j]->last_name) > 0)
					{
						PhoneRec* temp = ptrs[i];
						ptrs[i] = ptrs[j];
						ptrs[j] = temp;
					}
				}
				else
				{
					if (strcmp(ptrs[i]->first_name, ptrs[j]->first_name) > 0)
					{
						PhoneRec* temp = ptrs[i];
						ptrs[i] = ptrs[j];
						ptrs[j] = temp;
					}
				}
			}
		}
	}

	
}