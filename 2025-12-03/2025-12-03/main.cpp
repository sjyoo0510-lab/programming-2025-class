#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

//입력 버퍼를 비우는 함수
//scanf 등을 사용 후 버퍼에 남아있는 개행문자 (\n) 등을 제거하기 위함

void clear_input_buffer(void)
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
	{
		; //버퍼가 빌 때까지 읽어서 버림
	}
}

int main(void)
{
    // 변수 선언
    char str1[100];
    char str2[100];
    char copy[100];
    char sentence[200];
    char temp[200];

    char* pos;
    char ch;

    // 포인터 변수 선언 및 초기화
    char* p_str1 = str1;
    char* p_str2 = str2;
    char* p_copy = copy;
    char* p_sentence = sentence;
    char* p_temp = temp;

    // 문자열 입력 (공백 없이)
    printf("Enter first string (no spaces): ");
    scanf("%99s", p_str1);

    printf("Enter second string (no spaces): ");
    scanf("%99s", p_str2);

    printf("\n--- Printed strings (using puts) ---\n");
    puts(p_str1);
    puts(p_str2);

    // strlen 실습
    printf("\n--- strlen practice ---\n");
    printf("Length of str1: %zu\n", strlen(p_str1));
    printf("Length of str2: %zu\n", strlen(p_str2));

    // 입력 버퍼 비우기 및 문장 입력
    // 이유: 위에서 scanf로 입력받을 때 엔터키(\n)가 버퍼에 남아있어서 
    // 이를 지우지 않으면 fgets가 그 엔터를 읽고 바로 종료되어 버림.
    clear_input_buffer();

    printf("\nEnter one sentence (can include spaces): ");
    fgets(p_sentence, sizeof(sentence), stdin);

    // fgets는 개행문자까지 읽어오므로, 필요하다면 여기서 제거하는 코드가 추가될 수 있음
 
    printf("\nYou entered (sentence) = ");
    puts(p_sentence);

    // Practice #1: strcpy (문자열 복사)
    printf("\n--- Practice #1: strcpy practice ---\n");
    strcpy(p_copy, p_str1);
    printf("copy = ");
    puts(p_copy);

    // Practice #2: strcat (문자열 이어붙이기)
    printf("\n--- Practice #2: strcat practice ---\n");
    // 버퍼 오버플로우 방지 검사
    if (strlen(p_str1) + strlen(p_str2) < sizeof(str1)) {
        strcat(p_str1, p_str2);
        printf("After concatenation, str1 = ");
        puts(p_str1);
    }
    else {
        printf("str1 buffer is too small; cannot perform strcat!\n");
    }

    // Practice #3: strcmp (문자열 비교)
    printf("\n--- Practice #3: strcmp practice ---\n");
    {
        int cmp = strcmp(p_str1, p_str2);
        if (cmp == 0) {
            printf("str1 and str2 are equal.\n");
        }
        else if (cmp < 0) {
            printf("In lexicographical order, str1 comes before str2.\n");
        }
        else {
            printf("In lexicographical order, str1 comes after str2.\n");
        }
    }

    //  Practice #4: strchr (문자 검색)
    printf("\n--- Practice #4: strchr practice ---\n");
    printf("\nEnter a character to search for: ");
    scanf(" %c", &ch); // %c 앞의 공백은 이전 입력의 엔터 무시용

    pos = strchr(p_str1, ch);
    if (pos != NULL) {
        // 포인터 연산으로 인덱스 계산
        printf("'%c' is at index %ld (0-based) in str1.\n", ch, (long)(pos - p_str1));
    }
    else {
        printf("'%c' is not found in str1.\n", ch);
    }

    //  Practice #5: strstr (문자열 포함 여부 검색)
    // 원래 코드 흐름상 하단 주석이 상단 코드와 연결됨
    printf("\n--- Practice #5: strstr practice ---\n");

    // strstr은 sentence 안에 str2가 있는지 찾습니다.
    // 주의: str1은 위에서 strcat으로 변경되었으므로, 원래 입력값과는 다를 수 있음.
    pos = strstr(p_sentence, p_str2);

    if (pos != NULL) {
        printf("Found \"%s\" inside sentence.\n", p_str2);
        printf("Substring starting from the found position: ");
        puts(pos);
    }
    else {
        printf("Could not find \"%s\" in sentence.\n", p_str2);
    }

    //Practice #6: strtok (문자열 토큰 분리)
    printf("\n--- Practice #6: strtok practice: split sentence by spaces ---\n");

    // 왜 이 실습에서는 temp에 문자열을 복사하는가?
    // strtok 함수는 원본 문자열의 구분자(공백 등)를 NULL 문자(\0)로 바꿔버려서
    //      원본 데이터(sentence)를 훼손하기 때문입니다. 보존을 위해 복사본을 씁니다.
    strcpy(p_temp, p_sentence);

    char* token = strtok(p_temp, " "); // 첫 번째 토큰 추출 (구분자: 공백)
    int i = 1;

    while (token != NULL) {
        // fgets로 읽은 경우 마지막 토큰에 개행문자(\n)가 붙어있을 수 있어 처리가 필요할 수 있으나
        // 실습 코드 그대로 작성함
        printf("Token %d: ", i++);
        puts(token);

        token = strtok(NULL, " "); // 다음 토큰 추출
    }

    printf("\nProgram finished.\n");
    return 0;
}