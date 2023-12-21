#pragma once

void resizeConsole(int width, int height); //kích thước hiển thị cmd
void SetColor(int backgound_color, int text_color); //màu
void gotoxy(int x, int y); //tới toạ độ
void clearScreen(); // xoá màn hình
void SetScreenBufferSize(short width, short height); //chỉnh độ rộng toàn bản đồ
void DisableResizeWindow(); //vô hiệu hoá kích thước cmd
void DisableCtrButton(bool Close, bool Min, bool Max); //vô hiệu hoá nút menu
void showScrollbar(bool Show); //ẩn hiện thanh cuộn 
void ShowCur(bool CursorVisibility); //ẩn hiện con trỏ
void DisableSelection(); //vô hiệu hoá bôi đen text
