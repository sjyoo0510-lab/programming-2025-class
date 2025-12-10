#include <stdio.h>
// [구조체]: 가방 (Inventory)
// 사과와 물약은 각각 다른 주머니에 있어서 동시에 가질 수 있음
struct Inventory {
    int apple;  // 사과 개수
    int potion; // 물약 개수
};

// [공용체]: 내 손 (MyHand)
// 한 손에는 칼이나 방패 중 하나만 들 수 있음 (메모리 공간 공유)
union MyHand {
    int sword;  // 칼 공격력
    int shield; // 방패 방어력
};

int main() {
    // 1. 구조체 (가방) 테스트
    struct Inventory myBag;

    myBag.apple = 10;   // 사과 10개 넣음
    myBag.potion = 5;   // 물약 5개 넣음

    printf("=== [구조체: 가방] ===\n");
    printf("메모리 크기: %d 바이트 (4 + 4)\n", sizeof(myBag));
    printf("사과: %d개, 물약: %d개\n", myBag.apple, myBag.potion);
    printf(">> 서로 다른 공간이라 둘 다 멀쩡함!\n\n");


    // 2. 공용체 (내 손) 테스트
    union MyHand myHand;

    printf("=== [공용체: 내 손] ===\n");
    printf("메모리 크기: %d 바이트 (가장 큰 멤버 크기인 4)\n", sizeof(myHand));

    myHand.sword = 100; // 칼(공격력 100)을 쥐어줌
    printf("1. 칼 장착! (Sword: %d)\n", myHand.sword);

    myHand.shield = 500; // 방패(방어력 500)로 바꿔 듦
    printf("2. 방패 장착! (Shield: %d)\n", myHand.shield);

    // 핵심 포인트: 방패를 들었더니 칼의 값은 어떻게 되었을까?
    printf("3. 이때 칼의 값은? (Sword: %d) <-- 값이 500으로 바뀜!\n", myHand.sword);
    printf(">> 같은 메모리 공간을 쓰기 때문에 방패 값이 칼 값을 덮어씀!\n");

    return 0;
}