/*

Trong một project có multiple files:
    file .h (programming interface):
        -Chứa các lệnh khai báo hàm và các hằng số sẽ được sử dụng. 
        -Chứa định nghĩa những kiểu dữ liệu mới sẽ được dùng trong các tệp tin .cpp
    file .cpp (implementation):
        -Chứa mã nguồn chi tiết của các hàm đã được khai báo ở programming interface.
        -Tổ chức code thành nhiều file giúp chương trình dễ quản lý hơn, nhất là khi dự án lớn.
    file main.cpp:
        -Đây thường là file chính của dự án, nơi bắt đầu thực thi chương trình.
        -File duy nhất chứa chương trình chính (Hàm main() - Hàm duy nhất có thể gọi các hàm khác và không có ngược lại)
        -Bao gồm các file .h cần thiết để sử dụng các thành phần được khai báo ở các file khác.
        -Tích hợp và sử dụng các hàm, lớp, và logic đã được định nghĩa trong các file .cpp khác để thực hiện công việc cụ thể.
*/
