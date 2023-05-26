#pragma once
#ifndef _Matran 
#define _Matran

#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std; 
class Matran
{
private:
	int col, row; // Số cột và số hàng của ma trận 
	int** p;  // con trỏ tới vùng nhớ đọng chứa các phần tử ma trận 
	// kiem tra so nguyen to 
	bool SNT(int n);
	bool SCP(int n); 
	bool SHT(int n) ;
	bool SDX(int n); 
public: 
	void ghiFile(const string&) const;
	void docFile( const string & ) ;
	Matran(); 
	Matran(int, int); 
	// ham thiet lap sao chep 
	Matran(const Matran&);
	~Matran(); 
	int getCol() const; 
	int getRow() const;
	int** getP() const; 
	void setCol(int); 
	void setRow(int); 
	void setColRow(int, int); 
	friend istream& operator >> (istream&, Matran&); 
	friend ostream& operator  << (ostream&,  const Matran&);
	Matran& operator = ( Matran&); // gan 
	void LietkecacSNT();
	int DemsoluongSCP() ; 
	int TongSHT_trendongK(int &) ; 
	double TBC_SDX_trencotK(int& ) ; 
	// Sap xep chon 
	void selectionSort(int & ); 
	void sapxeptang_trendongK(int & ); 
	void phatsinhtudong(); 
};
#endif ; 