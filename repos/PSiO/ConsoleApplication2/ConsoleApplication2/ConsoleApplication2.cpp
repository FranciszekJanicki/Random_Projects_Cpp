#include "Time.h"

int main() {
    Time t1(200);
    std::cout << t1 << std::endl; // wyswietli 03m:20s
    Time t2;
    std::cin >> t2; // uzytkownik wprowadza 10h:12m:01s
    std::cout << t2;
    Time t3 = t2 - t1; // 10h:8m:41s
    int t3s = t3; // 36521
    std::cout << t3s;

    return 0;
}
