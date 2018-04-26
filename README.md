# Assignment 01

## Mô tả
Với sự phát triển không ngừng của nghành khoa học dữ liệu, chúng ta thấy 
sự xuất hiện ngày càng nhiều của các thiết bị thông minh và các hệ thống 
IoT. Với một lượng lớn các thiết bị xuất hiện ngày càng nhiều thì nhu cầu 
xử lý và thao tác trên dữ liệu ngày càng lớn.

Trong bài tập lớn này sinh viên được yêu cầu thực hiện các thao tác 
trên một bộ dữ liệu thực được thu thập từ các thiết bị gởi về cho máy chủ. 
Sinh viên vận dụng các cấu trúc dữ liệu phù hợp để thực hiện, giới hạn 
đến danh sách liên kết.

### Dữ liệu nhập

Dữ liệu nhập của chương trình được chứa trong file input như sau:

| Header | |
|---|:---------|
| 12 bytes | VRecord data |
|  4 bytes | number of records |
| Content |
|  1| VRecord |
|  2| VRecord |
|  3| VRecord |
|...| ... |

Thông tin chi tiết về record được đặc tả trong cấu trúc VRecord.
Cấu trúc này gồm ID của thiết bị, vị trí (x là longitude, y là latitude),
và timestamp cứa thời gian dữ liệu được gởi đến.
Hàm `distanceVR` được cho sẵn để tính khoảng cách giữa 2 thiết bị, giá 
trị trả về là khoảng cách tính theo km.

### Dữ liệu xuất

Dữ liệu sinh viên xuất ra cần tuân thủ các quy tắc sau:
 + Số nguyên: không cần định dạng
 + Số thực: độ chính xác *12* chữ số, đã được cài trong `main.cpp`.
 + Các dòng dữ liệu: với mỗi request, sinh viên xuất ra
 thông tin trên cùng một dòng, cách nhau bởi khoảng trắng.
 + Nếu request là dạng command, sinh viên xuất 
 ra `<request>`: `Succeed`/`Failed`.

## Các yêu cầu

Các yêu cầu có thể được xử lý trên database.

| Mã         | Mô tả |
| ---------- | ------- |
| CNV        | Tính số lượng thiết bị trong database |
| VFF        | Tìm thiết bị được lưu trữ đầu tiên   |
| VFL        | Tìm thiết bị được lưu trữ cuối cùng  |
| VFY`<ID>`  | Tìm tọa độ `y` được lưu trữ đầu tiên của thiết bị `<ID>` |
| VFX`<ID>`  | Tìm tọa độ `x` được lưu trữ đầu tiên của thiết bị `<ID>` |
| VLY`<ID>`  | Tìm tọa độ `y` được lưu trữ cuối cùng của thiết bị `<ID>` |
| VLX`<ID>`  | Tìm tọa độ `x` được lưu trữ cuối cùng của thiết bị `<ID>` |
| VFT`<ID>`  | Tìm thời điểm bắt đầu lưu trữ của thiết bị `<ID>` |
| VLT`<ID>`  | Tìm thời điểm kết thúc lưu trữ của thiết bị `<ID>` |
| VCR`<ID>`  | Tính số lượng record của thiết bị `<ID>` |
| VCL`<ID>`  | Tính độ dài hành trình của thiết bị `<ID>` |
| VMT`<ID>`  | Tính thời gian di chuyển của thiết bị `<ID>` |
| VFS`<ID>`  | Tìm điểm dừng đầu tiên của thiết bị `<ID>`, xuất `(x y)` |
| VLS`<ID>`  | Tìm điểm dừng cuối cùng của thiết bị `<ID>` |
| VMS`<ID>`  | Tìm thời gian dừng lâu nhất của thiết bị `<ID>` |
| VAS`<ID>`  | Tìm khoảng cách trung bình giữa 2 lần thu thập dữ liệu của thiết bị `<ID>` |
| MST        | Tìm thời lượng dừng lâu nhất của tất cả các thiết bị |
| CNR        | Tính số lượng record trong database |
| MRV        | Tìm thiết bị có số lượng record nhiều nhất |
| LRV        | Tìm thiết bị có số lượng record ít nhất |
| MTV        | Tìm thiết bị có tổng thời gian di chuyển lâu nhất |
| MVV        | Tìm thiết bị có vận tốc di chuyển trung bình nhanh nhất |
| CNS        | Tính số lượng thiết bị luôn di chuyển và không dừng |
| CAS        | Tính khoảng cách trung bình khi thu thập dữ liệu của tất cả các thiết bị |
| LPV        | Tìm thiết bị có hành trình dài nhất |
| SPV        | Tìm thiết bị có hành trình ngắn nhất |
| RVR`<ID>`  | Xóa các record của thiết bị `<ID>` |

**Lưu ý: nếu có nhiều kết quả có thể trả về thì chọn kết quả đầu tiên theo thứ tự lưu 
trong dữ liệu đầu vào.**


## Hiện thực

**Sinh viên được cung cấp các file sau:**
 - `main.cpp`: mã nguồn chính của chương trình
 - `listLib.h`: file chứa định nghĩa thư viện danh sách liên kết
 - `dbLib.h`: file header chứa prototype cần thiết để quản lý database
 - `dbLib.cpp`: mã nguồn hiện thực các chức năng quản lý database
 - `requestLib.h`: file header chứa các prototype cần thiết để quản lý các sự kiện
 - `requestLib.cpp`: mã nguồn hiện thực các hàm xử lý sự kiện
 - `processData.cpp`: mã hiện thực của sinh viên

__Sinh viên được cho các hàm sau:__
 - `distanceVR`: tính khoảng cách giữa 2 điểm trên mặt đất với 
 toạ độ (latitude (y), longitude (x)) cho trước.
 - `loadVDB`: đọc file và tải dữ liệu vào danh sách
 - `strPrintTime`: in thời gian ra một chuỗi theo định dạng yêu cầu

Đối với file thư viện `listLib.h`, sinh viên được cung cấp sẵn định 
nghĩa cơ bản. Ngoài ra, _để build được chương trình hoàn chỉnh, sinh viên
cần hoàn thiện các hàm còn lại trong danh sách_. Sinh viên có thể thêm các 
tính năng vào thư viện nếu thấy cần thiết.

__processData.cpp__
Sinh viên hiện thực việc xử lý các yêu cầu thông qua hàm __*processRequest*__.
Không được thay đổi prototype của hàm này.

Sinh viên được phép tuỳ biến, chỉnh sửa các file mã nguồn trừ file 
`main.cpp` vì nó sẽ được ghi đè lúc chấm.

**Sinh viên không được sử dụng các thư viện nào khác ngoài các thư viện đã được 
dùng trong framework.**

## Build
Sinh viên thực hiện build bằng lệnh `make` từ command line trên Linux
và chạy file `a01`. Cú pháp trên linux như sau:
> `./dsa172a1 request.txt sampleData.dat`

trong đó `request.txt` là file chứa danh sách các sự kiện, cách nhau bởi 
khoảng trắng hoặc ký tự xuống dòng.
`sampleData.dat` là file dữ liệu. 

Đối với các bạn dùng VisualStudio trên Windows, các bạn có thể tạo một 
project và thêm các file mã nguồn vào. Nếu không bạn có thể sử dụng hệ 
thống CMake để tự sinh project VS cho mình.
 