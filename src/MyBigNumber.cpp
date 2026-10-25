#include "MyBigNumber.h"
#include <iostream>

using namespace std;

string MyBigNumber::sum(const string &stn1, const string &stn2)
{
    string result = "";
    int carry = 0;
    int i = (int)stn1.size() - 1;
    int j = (int)stn2.size() - 1;
    int count = 0;
    while(i >= 0 || j >= 0 || carry == 1)
    {
        int d1 = i < 0 ? 0 : stn1[i] - '0';
        int d2 = j < 0 ? 0 : stn2[j] - '0';
        int temp = d1 + d2 + carry;
        count++;
        cout << "Buoc " << count << ": Lay " << d1 << " cong voi " << d2 << " duoc " << d1 + d2 << "." << endl;
        if(carry > 0){
            cout << "Cong tiep voi nho " << carry << " duoc " << temp << "." << endl;
        }
        carry = temp / 10;
        temp = temp % 10;
        result = char(temp + '0') + result;
        cout << "Luu " << temp << " vao ket qua duoc ket qua moi la \"" << result << "\". Ghi nho " << carry << "." << endl;
        i--;
        j--;
    }
    return result;
}
