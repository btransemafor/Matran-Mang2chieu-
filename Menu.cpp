#include "matran.h"
int main()
{
	
	int choice;
	Matran mt;
	do
	{
		
		
		cout << "-------------MENU MAXTRI------------" << endl;
		cout << "0. Thoat\n";
		cout << "1. Nhap ma tran\n";
		cout << "2. Phat sinh ma tran tu dong\n";
		cout << "3. Xuat ma tran\n";
		cout << "4. Liet ke cac so nguyen to cua ma tran\n";
		cout << "5. Tinh tong cac so hoan thien tren dong thu k\n";
		cout << "6. Tinh trung binh cong So Doi Xung tren cot thu k\n";
		cout << "7. Sap xep tang dan cac phan tu tren dong thu k\n";
		cout << "8. Diem so luong so chinh phuong\n";
		cout << "9. Ghi file\n"; 
		cout << "10.Doc file\n"; 
		cout << "------------------------------------\n";
		cout << "Enter your choice: "; cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "Dang thoat......\n";
			break;
		case 1:
			cin >> mt;
			break;
		case 2:
			mt.phatsinhtudong();
			cout << "Ma tran phat sinh tu dong: " << endl;
			cout << mt;
			break;
		case 3:
			if (mt.getCol() == 0 || mt.getRow() == 0)
				cout << "Matrix Empty.\n";
			else
			{
				cout << mt;
			}
			break;
		case 4:
		{
			if (mt.getCol() != 0 && mt.getRow() != 0)
				mt.LietkecacSNT();
			else
			{
				cout << "Matrix Empty.\n";
			}

		}
		break;
		case 5:
		{
			if (mt.getCol() != 0 && mt.getRow() != 0)
			{
				int k;
				cout << "Nhap dong thu k can tinh, k = "; cin >> k;
				if (k <=0 || k > mt.getRow()) // Kiểm tra giá trị hợp lệ của k
					cout << "K khong hop le\n";
				else 
				{ 
					if (mt.TongSHT_trendongK(k) != -1)
						cout << "Tong cac so hoan thien tren dong thu " << k << "la: " << mt.TongSHT_trendongK(k) << endl;

					else cout << "Khong co so hoan thien nao\n";
				}
			}
			else
				cout << "Matrix Empty.\n";
		}
		break;
		case 6:
		{
			if (mt.getCol() != 0 && mt.getRow() != 0)
			{
				int k;
				cout << "Nhap cot thu k can tinh, k = "; cin >> k;
				if (k <= 0 || k > mt.getCol()) // Kiểm tra giá trị hợp lệ của k
					cout << "K khong hop le\n";
				else {
					if (mt.TBC_SDX_trencotK(k) != -1)
						cout << "Trung binh cong cac So Doi Xung tren cot thu " << k << " la: " << mt.TBC_SDX_trencotK(k) << endl;
					else cout << "Khong co So Doi Xung nao tren cot thu  " << k << endl;
				}
			}
			else
				cout << "Matrix Empty.\n";
		}
		break;
		case 7:
		{
			if (mt.getCol() != 0 && mt.getRow() != 0)
			{
				int k;
				cout << "Nhap dong thu k can sap xep, k = "; cin >> k;
				if (k <= 0 || k > mt.getRow()) // Kiểm tra giá trị hợp lệ của k
					cout << "K khong hop le\n"; 
				else
				{
					mt.sapxeptang_trendongK(k);
					cout << mt;
				}
			}
			else cout << "Matrix Empty.\n";
		}
		break;
		case 8:
		{
			if (mt.getCol() != 0 && mt.getRow() != 0)
				cout << "So luong so chinh phuong trong ma tran la: " << mt.DemsoluongSCP() << endl;
			else cout << "Matrix Empty.\n";
		}
		break; 
		case 9:
		{
			string s; 
			cout << "Nhap ten FILE: "; 
			cin >> s; 
			mt.ghiFile(s); 
			break; 
		}
		case 10:
		{
			cout << "Nhap ten FILE da tao tren may tinh: "; 
			string s; 
			cin >> s; 
			mt.docFile(s); 
			break; 
		}
		
		break;
		default:
			cout << "Nhap lai lua chon phu hop \n";
			break;
		}
	}
		while (choice != 0);
}
