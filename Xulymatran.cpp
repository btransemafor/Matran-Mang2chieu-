#include "matran.h" 
Matran::Matran()
{
	this->row = 0; 
	this->col = 0; 
	p = NULL; 
}
Matran::Matran(int c , int d )
{
	while (c <= 0 || d <= 0) {
		cout << "Nhap lai so luong dong va cot ( lon hon 0 ): ";
		cin >> c >> d;
	}
	this->col = c; 
	this->row = d; 
	p = new int* [row]; 
	for (int i = 0; i < row; i++)
	{
		p[i] = new int[col]; 
		for (int j = 0; j < col; j++)
		{
			p[i][j] = 0; 
		}
	}
}
// ham thiet lap sao chep 
Matran::Matran(const Matran& mt)
{
	col = mt.col; 
	row = mt.row; 
	p = new int*[row]; 
	for (int i = 0; i < row; i++)
	{
		p[i] = new int[col];
		for (int j = 0; j < col; j++)
		{
			p[i][j] = mt.p[i][j]; 
		}
	}
}
Matran::~Matran()
{
	if (p != NULL)
	{
		for (int i = 0; i < row; i++)
		{
			delete[] p[i];
		}
		delete[] p;
	}
}
istream& operator >> (istream& is , Matran& mt ){
	if (mt.p != NULL)
	{
		mt.~Matran();
	}
	do {
		cout << "Nhap so cot ma tran: "; cin >> mt.col;
		cout << "Nhap so dong ma tran: "; cin >> mt.row;
	} while (mt.row <= 0 || mt.col <= 0); 
	mt.p = new int* [mt.row]; 
	for (int i = 0; i < mt.row; i++)
	{
		mt.p[i] = new int[mt.col];
		for (int j = 0; j < mt.col; j++)
		{
			cout << "P[" << i << "][" << j << "] = ";
			is >> mt.p[i][j];
		}
	}
	return is; 
}
ostream& operator<<(ostream& os, const Matran& mt) {
	if (mt.p == NULL) {
		os << "Mang Rong.\n";
	}
	else {
		for (int i = 0; i < mt.row; i++) {
			for (int j = 0; j < mt.col; j++) {
				os << setw(4) << left << mt.p[i][j];
			}
			os << endl;
		}
	}
	return os;
}


bool Matran::SNT(int n)
{
	bool SNT = true; 
	if (n < 2) SNT = false; 
	else 
	
		for (int i = 2; i <= n / 2; i++)
			if (n % i == 0)
			{
				SNT = false;
				break;
			}
		return SNT; 
}
bool Matran::SHT(int n)
{
	bool sht; 
	if (n < 6) sht = false; 
	else
	{
		int tongus = 0;
		for (int i = 1; i <= n / 2; i++)
			if (n % i == 0) tongus += i;
		sht = (tongus == n) ? true : false;
	}
	return sht; 
}
bool Matran::SCP(int n)
{
	bool scp = false;
	if (n < 1) scp = false;
	else
		for (int i = 1; i <= sqrt(n); i++)
			if (i * i == n) {
				scp = true;
				break;
			}
	return scp;
}
bool Matran::SDX(int n)
{
	bool sdx; 
	if (n < 1) sdx = false; 
	else
	{
		int m = n; int dao = 0, dv; 
		while (m > 0)
		{
			dv = m % 10;
			dao = dao * 10 + dv;
			m /= 10;
		}
		sdx = (dao == n) ? true : false; 
	}
	return sdx; 
}
void Matran::LietkecacSNT() 
{
	int demsnt = 0; 
	for ( int i = 0 ; i< row  ; i++)
		for (int j = 0; j < col; j++)
		{
			if (SNT(p[i][j])) {
				cout << p[i][j] << " ";
				demsnt++;
			}
		}
	cout << endl; 
	if (demsnt == 0) cout << "Ma tran khong chua so nguyen to nao!\n"; 
}
int  Matran ::  DemsoluongSCP()
{
	int demSCP = 0; 
	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			if (SCP(p[i][j]))
				demSCP++; 
	 return demSCP;  
}
int Matran::TongSHT_trendongK(int& k)
{
	int tongK = 0;
	int demSHT = 0;

	for (int i = 0; i < col; i++)
	{
		if (SHT(p[k-1][i])) {
			tongK += p[k-1][i];
			demSHT++;
		}
	}

	if (demSHT != 0)
		return tongK;

	return -1;
}


double Matran :: TBC_SDX_trencotK(int &k)
{
	int demSDXk = 0; 
	int tongK = 0; 
	for (int i = 0; i < row; i++)
		if (SDX(p[i][k-1])) {
			tongK += p[i][k -1 ];
			demSDXk++;
		}
	if (demSDXk != 0 )
	return float(tongK) / demSDXk; 
	return -1; 
}
void Matran :: selectionSort(int &k )
{
	int min; 
	for (int i = 0; i < col - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < col; j++)
			if (p[k-1][j] < p[k-1][min]) min = j;
		swap(p[k-1][min], p[k-1][i]);
	}
}
void Matran :: sapxeptang_trendongK(int &k )
{
	selectionSort(k); 
}
int Matran::getCol() const
{
	return col; 
}
int Matran::getRow() const
{
	return row; 
}
int** Matran::getP() const
{
	return p; 
}
void Matran::setCol(int socot )
{
	while (socot <= 0) 
	{
		cout << "thiet lap lai so cot: "; cin >> socot;
	}
	col = socot; 
}
void Matran::setRow(int sohang )
{
	while (sohang <= 0)
	{
		cout << "thiet lap lai so hang: "; cin >> sohang;
	}
	col = sohang;
}
void Matran::setColRow(int socot , int sohang)
{
	setCol(socot); 
	setRow(sohang); 
}
void Matran::phatsinhtudong()
{
	if (p != NULL) this->~Matran();
	do
	{
		cout << "Nhap so luong cot va hang cua ma tran (lon hon 0): "; cin >> col >> row; 
	} while (row <= 0 || col <= 0);
	p = new int* [row]; 
	for (int i = 0; i < row; i++)
	{
		p[i] = new int[col]; 
	}
	int mi, ma; 
	cout << "Nhap mien gia tri phat sinh: "; 
	cin >> mi >> ma;  
	// khoi dong bo phat sinh so ngau nhien
	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			p[i][j] = mi + rand() % (ma - mi + 1); 
		}
	}

}
void Matran::docFile( const string &fileName) {
	ifstream file(fileName);
	if (file.is_open()) {
		file >> row >> col;
		p = new int* [row];
		for (int i = 0; i < row; i++) {
			p[i] = new int[col];
			for (int j = 0; j < col; j++) {
				file >> p[i][j];
			}
		}
		file.close();
		cout << "Doc file thanh cong.\n";
	}
	else {
		cout << "Khong the mo file de doc.\n";
	}
}
void Matran::ghiFile(const string& fileName) const {
	ofstream file(fileName);
	if (file.is_open()) {
		file << row << " " << col << endl;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				file << p[i][j] << " ";
			}
			file << endl;
		}
		file.close();
		cout << "Ghi file thanh cong.\n";
	}
	else {
		cout << "Khong the mo file de ghi.\n";
	}
}
Matran& Matran ::operator = ( Matran& mt )
{
	if (mt.col == 0 && mt.row == 0)
	{
		this->col = 0; 
		this->row = 0; 
		p = NULL; 
	}
	else
	{
		col = mt.col;
		row = mt.row;
		p = new int* [mt.row];
		for (int i = 0; i < row; i++)
		{
			mt.p[i] = new int[col];
		}
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
				p[i][j] = mt.p[i][j];
	}
	return *this; 
}
