#include <iostream>
#include <vector>

struct SubstringIndices {
    int* arr;
    int length;
    SubstringIndices(int* arr, int length)
        :arr(arr), length(length) {}
};

bool palindrome(char* str);
SubstringIndices find_substring(const char* str, const char* substr);
bool equals(const char* str1, const char* str2);
void print_string(const char* str);
void encrypt(char* str_to_encrypt, int key);
static void task1();
static void task2();
static void task3();
static void task4();

void lab41() {
    while (true) {
        int user_input;
        std::cin >> user_input;
        std::cin.ignore();
        switch (user_input) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                return;
        }
    }
}

static void task1() {
    char buffer[256];

    printf("Enter a string (up to 255 characters): ");
    fgets(buffer, sizeof(buffer), stdin);
    size_t length = strlen(buffer);
    if (buffer[length - 1] == '\n') buffer[length - 1] = '\0';

    if (palindrome(buffer)) std::cout << "It's a palindrome!\n";
    else std::cout << "It's not a palindrome!\n";
}

// на вход подается массив из символов, возвращает тру или фолз в зависимости от того 
// является данный массив палиндромом или нет
bool palindrome(char* str) {
    for (int i = 0, j = strlen(str) - 1; i < j; ++i, --j) {
        if (str[i] == ' ') ++i;
        if (str[j] == ' ') --j;

        if (str[i] >= 65 and str[i] <= 90)
            str[i] += 32;

        if (str[j] >= 65 and str[j] <= 90)
            str[j] += 32;

        if (str[i] != str[j])
            return false;
    }
    return true;
}

static void task2() {
    char str[256], substr[256];
    printf("Enter a string(up to 255 characters): ");
    fgets(str, sizeof(str), stdin);
    str[strlen(str) - 1] = '\0';
    printf("Enter a substring(up to 255 characters): ");
    fgets(substr, sizeof(substr), stdin);
    substr[strlen(substr) - 1] = '\0';

    if (strlen(str) < strlen(substr)) {
        std::cout << "Invalid input\n";
        return;
    }

    SubstringIndices out = find_substring(str, substr);
    for (int i = 0; i < out.length; ++i) {
        std::cout << out.arr[i] << ' ';
    }
    std::cout << '\n';
}

// на вход подается два массива из чаров, которые представляют из себя основную строку и 
// подстроку. возвращается структура, которая в себе содержит массив из всех индексов 
// с позиции которых начинается подстрока а также длина данного массива.
SubstringIndices find_substring(const char* str, const char* substr) {
    int length = strlen(str);
    int* tmp_array = new int[length];
    for (int i = 0; i < length; ++i) tmp_array[i] = -1;
    int return_array_length = 0;

    char* current_substr = new char[strlen(substr)+1];
    current_substr[strlen(substr)] = '\0';
    for (int i = 0; i < length-strlen(substr)+1; ++i) {
        for (int j = 0; j < strlen(substr); ++j)
            current_substr[j] = str[i + j];
        
        if (equals(current_substr, substr)) {
            tmp_array[return_array_length] = i;
            ++return_array_length;
        }
    }

    int* return_array = new int[return_array_length];
    int k = 0;
    for (int i = 0; i < length; ++i) {
        if (tmp_array[i] > -1) {
            return_array[k] = tmp_array[i];
            ++k;
        }
    }
    return SubstringIndices(return_array, return_array_length);
}

// на вход подается два массива, возвращается тру или фолз в зависимости от того равны данные массивы
// или нет. равенство в данном случае опеределяется как полное совпадение содержимого данных массивов
bool equals(const char* str1, const char* str2) {
    if (strlen(str1) != strlen(str2))
        return false;

    for (int i = 0; i < strlen(str1); ++i)
        if (str1[i] != str2[i]) return false;

    return true;
}

// выводит массив из чаров, переданный как аргумент
void print_string(const char* str) {
    for (int i = 0; i < strlen(str); ++i)
        std::cout << str[i];
    std::cout << '\n';
}

static void task3() {
    char buffer[256];
    printf("Enter a string to encypt(up to 255 characters): ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    int key;
    std::cout << "Enter the key: ";
    std::cin >> key;
    encrypt(buffer, key);
    print_string(buffer);
}

// передается ключ и строка для зашифровки. к каждому элементу массива добавляется данных ключ
void encrypt(char* str_to_encrypt, int key) {
    for (int i = 0; i < strlen(str_to_encrypt); ++i) {
        if (str_to_encrypt[i] != ' ')
            str_to_encrypt[i] += key;
    }
}

static void task4() {
    char buffer[256];
    printf("Enter a string to encypt(up to 255 characters): ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strlen(buffer) - 1] = '\0';
    print_string(buffer);
    bool is_open = false;
    char current_string[256];
    int length = 0;
    for (int i = 0; i < strlen(buffer); ++i) {
        if (buffer[i] == '"') {
            if (is_open == true) {
                is_open = false;
                current_string[length - 1] = '\0';
                length = 0;
                print_string(current_string);
            }
            else if (is_open == false) is_open = true;
        }
        else {
            if (is_open) {
                current_string[length] = buffer[i];
                ++length;
            }
        }
    }
}