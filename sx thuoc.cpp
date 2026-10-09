#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

class Thuoc {
private:
    string mathuoc;
    string tenthuoc;
    string hoatchat;
    string donvitinh;
    float giaban;
    int soluongtonkho;
    string hansudung;

public:

    void nhap() {
        cout << "Ma thuoc: ";
        cin >> mathuoc;
        cin.ignore();

        cout << "Ten thuoc: ";
        getline(cin, tenthuoc);

        cout << "Hoat chat: ";
        getline(cin, hoatchat);

        cout << "Don vi tinh: ";
        getline(cin, donvitinh);

        cout << "Gia ban: ";
        cin >> giaban;

        cout << "So luong ton kho: ";
        cin >> soluongtonkho;
        cin.ignore();

        cout << "Han su dung (dd/mm/yyyy): ";
        getline(cin, hansudung);
    }

    void xuat() {
        cout << "Ma thuoc: " << mathuoc << endl;
        cout << "Ten thuoc: " << tenthuoc << endl;
        cout << "Hoat chat: " << hoatchat << endl;
        cout << "Don vi tinh: " << donvitinh << endl;
        cout << "Gia ban: " << giaban << endl;
        cout << "So luong ton kho: " << soluongtonkho << endl;
        cout << "Han su dung: " << hansudung << endl;
    }

    void sapXepTang(Thuoc ds[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                int d1, m1, y1;
                int d2, m2, y2;

                sscanf(ds[i].hansudung.c_str(),
                       "%d/%d/%d", &d1, &m1, &y1);

                sscanf(ds[j].hansudung.c_str(),
                       "%d/%d/%d", &d2, &m2, &y2);

                int ngay1 = y1 * 10000 + m1 * 100 + d1;
                int ngay2 = y2 * 10000 + m2 * 100 + d2;

                if (ngay1 > ngay2) {
                    Thuoc tam = ds[i];
                    ds[i] = ds[j];
                    ds[j] = tam;
                }
            }
        }
    }
};

int main() {

    Thuoc ds[200];
    int n;

    cout << "Nhap so luong thuoc (0 < n < 200): ";
    cin >> n;

    if (n <= 0 || n >= 200) {
        cout << "So luong thuoc khong hop le!";
        return 0;
    }

    cout << "\n========== NHAP DANH SACH THUOC ==========\n";

    for (int i = 0; i < n; i++) {
        cout << "\nNhap thong tin thuoc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    cout << "\n========== DANH SACH THUOC BAN DAU ==========\n";

    for (int i = 0; i < n; i++) {
        cout << "\n--- Thuoc thu " << i + 1 << " ---\n";
        ds[i].xuat();
    }

    Thuoc t;
    t.sapXepTang(ds, n);

    cout << "\n========== DANH SACH SAU KHI SAP XEP ==========\n";

    for (int i = 0; i < n; i++) {
        cout << "\n--- Thuoc thu " << i + 1 << " ---\n";
        ds[i].xuat();
    }

    return 0;
}
