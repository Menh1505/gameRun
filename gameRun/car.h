#pragma once

struct playerCar;
void printPlayerCar(); // in xe người chơi
void movePlayerCar(char c); // vị trí hiện tại xe người chơi

struct enemyCar;
void spawnEnemyCar(); //khởi tạo vị trí xe địch
void downEnemyCar(); // xe địch trôi xuống màn hình
void printEnemyCar(int x, int y); // in xe địch
void enemyList(); // danh sách xe địch