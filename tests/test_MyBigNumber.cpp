#include "MyBigNumber.h"
#include <iostream>
using namespace std;

int soLanSai = 0;

void kiemTra(string a, string b, string kyVong)
{
    MyBigNumber mbn;
    string ketQua = mbn.sum(a, b);
    if (ketQua == kyVong) {
        cout << "PASS: " << a << " + " << b << " = " << ketQua << endl;
    } else {
        cout << "FAIL: " << a << " + " << b << " ky vong " << kyVong << ", nhan duoc " << ketQua << endl;
        soLanSai++;
    }
}

int main()
{
    kiemTra("1234", "897", "2131"); // vi du cua de
    kiemTra("897", "1234", "2131"); // doi thu tu
    kiemTra("0", "0", "0");
    kiemTra("123", "0", "123");
    kiemTra("5", "5", "10");        // nho tao them chu so
    kiemTra("999", "1", "1000");    // nho lan het
    kiemTra("1", "999", "1000");
    kiemTra("99999999999999999999", "1", "100000000000000000000"); // vuot qua long long
    // Them 1 so testcase khac
    kiemTra("1", "99999", "100000");                                  // so ngan ben trai, nho lan nhieu chu so
    kiemTra("999", "999", "1998");                                    // dai bang nhau, buoc nao cung nho
    kiemTra("1050", "60", "1110");                                    // nho o giua, khong lan toi cuoi
    kiemTra("12345678901234567890", "1", "12345678901234567891");     // so dai, khong nho
    kiemTra("007", "5", "012");                                       // so 0 o dau giu nguyen
    kiemTra("0", "123456789", "123456789");                           // cong 0 voi so dai

    if (soLanSai == 0) {
        cout << "TAT CA PASS" << endl;
        return 0;
    }
    cout << soLanSai << " test FAIL" << endl;
    return 1;
}
