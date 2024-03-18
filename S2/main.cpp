#include "NumberList.h"

int main() {
    NumberList S;
    S.Init();
    S.Add(3);
    S.Add(17);
    S.Add(1);
    S.Add(9);
    for(int i = 0; i < 10; i++) {
        S.Add(i * 4);
    }
    S.Print();
    S.Sort();
    S.Print();
    return 0;
}
