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

    if (soLanSai == 0) {
        cout << "TAT CA PASS" << endl;
        return 0;
    }
    cout << soLanSai << " test FAIL" << endl;
    return 1;
}
