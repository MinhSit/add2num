# add2num

Chương trình cộng 2 số lớn dạng chuỗi, cộng giống như cách cộng tay: từ phải sang trái, có nhớ, và in ra từng bước.

Hàm chính: `MyBigNumber::sum(stn1, stn2)`

## Môi trường

- g++ (em dùng bản 14.2.0, cài bằng MSYS2 trên Windows)
- make (không bắt buộc). Trên Windows thì dùng `mingw32-make`, chạy trong Git Bash.

## Các thư mục

- `include/MyBigNumber.h`: khai báo class MyBigNumber
- `src/MyBigNumber.cpp`: code hàm sum
- `tests/test_MyBigNumber.cpp`: code test

## Cách build và chạy test

Windows (PowerShell):

```
g++ -std=c++17 -Wall -Wextra -Iinclude src/MyBigNumber.cpp tests/test_MyBigNumber.cpp -o test_runner
./test_runner
```

Windows (Git Bash):

```
mingw32-make test
```

Linux / Mac:

```
make test
```

Nếu đúng hết sẽ thấy:

```
PASS: 1234 + 897 = 2131
PASS: 897 + 1234 = 2131
PASS: 0 + 0 = 0
PASS: 123 + 0 = 123
PASS: 5 + 5 = 10
PASS: 999 + 1 = 1000
PASS: 1 + 999 = 1000
PASS: 99999999999999999999 + 1 = 100000000000000000000
PASS: 1 + 99999 = 100000
PASS: 999 + 999 = 1998
PASS: 1050 + 60 = 1110
PASS: 12345678901234567890 + 1 = 12345678901234567891
PASS: 007 + 5 = 012
PASS: 0 + 123456789 = 123456789
TAT CA PASS
```

(giữa các dòng PASS sẽ có thêm các dòng in ra từng bước cộng)

## Ví dụ

```cpp
#include "MyBigNumber.h"
#include <iostream>

int main() {
    MyBigNumber mbn;
    std::cout << mbn.sum("1234", "897") << std::endl;
}
```

Kết quả:

```
Buoc 1: Lay 4 cong voi 7 duoc 11.
Luu 1 vao ket qua duoc ket qua moi la "1". Ghi nho 1.
Buoc 2: Lay 3 cong voi 9 duoc 12.
Cong tiep voi nho 1 duoc 13.
Luu 3 vao ket qua duoc ket qua moi la "31". Ghi nho 1.
Buoc 3: Lay 2 cong voi 8 duoc 10.
Cong tiep voi nho 1 duoc 11.
Luu 1 vao ket qua duoc ket qua moi la "131". Ghi nho 1.
Buoc 4: Lay 1 cong voi 0 duoc 1.
Cong tiep voi nho 1 duoc 2.
Luu 2 vao ket qua duoc ket qua moi la "2131". Ghi nho 0.
2131
```

## Ghi chú

- Theo đề thì input luôn đúng (chỉ có chữ số) nên em không kiểm tra lỗi input.
- Số 0 ở đầu thì em giữ nguyên, ví dụ "007" + "5" = "012".
- Em không đổi chuỗi sang int hay long long nên cộng được số dài bao nhiêu cũng được.
- Mỗi bước em thêm chữ số mới vào đầu chuỗi kết quả, nên lúc in ra kết quả đã đúng thứ tự, không cần đảo ngược.
- Em in log bằng cout. Các bước đều in theo cùng một kiểu câu. Dòng "Cong tiep voi nho" chỉ in khi bước trước có nhớ.
- Log viết không dấu để không bị lỗi font trên terminal Windows.
