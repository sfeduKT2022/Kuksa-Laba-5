/******************************************************************************
Кукса Кирилл Сергеевич
КТбо1-2
Лабораторная работа №5 «Работа со структурами»
Вариант № 3
Задание: Написать программу, которая записывает с клавиатуры в файл структуру согласно выданному варианту задания.
         В качестве разделителя полей структуры использовать символ табуляции. В программе реализовать:
         а) дополнение  существующего массива структур новыми структурами;
         б) поиск структуры с заданным значением выбранного элемента;
         в) вывод на экран содержимого массива структур;
         г) упорядочение массива структур по заданному полю (элементу), например государство по численности.
         Поля структуры: фамилия, имя, отчество, год  рождения, телефон, адрес, номер медицинской карты, группа крови, резус - фактор, диагноз
*******************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
const int data = 15;
const int lenght = 102;

struct patient {
    char surname[lenght];
    char name[lenght];
    char patronym[lenght];
    int birth;
    long long int phoneNum;
    char address[lenght];
    long long int medCard;
    int bloodType;
    char rhFact;
    char diagnosis[lenght];
};

typedef patient* PointerToPatient;
patient database[data];
PointerToPatient ptp[data];

long long int Validator(char enter[lenght])
{
    char found[lenght];
    int i, k = 0;
    for (i = 0; enter[i] != '\n'; i++) {
        if (isdigit(enter[i])) {
            found[k] = enter[i];
            k++;
        }
    }
    found[k] = '\0';
    return strtoll(found, NULL, 10);
}

char rhValidator(char enter[lenght])
{
    char choice[lenght];
    char found = 'a';
    int i, rhOpt;
    for (i = 0; enter[i] != '\n'; i++) {
        if ((enter[i] == '-') || (enter[i] == '+')) {
            found = enter[i];
            break;
        }
    }
    if (found == '-') {
        printf("Найдено значение -. Это нужное значение?\n");
        printf("1 - да;\n");
        printf("2 - нет.\n");
        printf("Выбранная опция: ");
        fgets(choice, lenght, stdin);
        rhOpt = Validator(choice);
        choice[0] = '\0';
        while ((rhOpt < 1) || (rhOpt > 2)) {
            printf("Введите корректные данные: ");
            fgets(choice, lenght, stdin);
            rhOpt = Validator(choice);
            choice[0] = '\0';
        }
        switch (rhOpt) {
        case 1: { return '-'; }
        case 2: { return '+'; }
        default: { printf("Произошло божественное вмешательство\n"); break; }
        }
    }
    else if (found == '+') {
        printf("Найдено значение +. Это нужное значение?\n");
        printf("1 - да;\n");
        printf("2 - нет.\n");
        printf("Выбранная опция: ");
        fgets(choice, lenght, stdin);
        rhOpt = Validator(choice);
        choice[0] = '\0';
        while ((rhOpt < 1) || (rhOpt > 2)) {
            printf("Введите корректные данные: ");
            fgets(choice, lenght, stdin);
            rhOpt = Validator(choice);
            choice[0] = '\0';
        }
        switch (rhOpt) {
        case 1: { return '+'; }
        case 2: { return '-'; }
        default: { printf("Произошло божественное вмешательство\n"); break; }
        }
    }
    else { return found; }
    return found;
}

int DataInput(int p)
{
    int amount, i = 0, k, t, d, u = 0;
    if (p == 0) {
        printf("Введите количество пациентов, не более %d: ", data);
        scanf_s("%d", &amount);
        printf("\n");
    }
    else {
        i = p;
        amount = ++p;
    }
    if ((amount > data) || (amount < 1)) { puts("Некорректное количество пациентов, операции с базой данных невозможны."); return 0; }
    puts("Вводите только соответствующие полям данные, используйте английский язык:");
    for (i; i < amount; i++)
    {
        k = i + 1;
        char enter[lenght];
        printf("Введите фамилию %d пациента: ", k);
        if (i == 0) {
            fgets(enter, lenght, stdin);
            fgets(enter, lenght, stdin);
        }
        else { fgets(enter, lenght, stdin); }
        for (d = 0; enter[d] != '\n'; d++) {
            if (isalpha(enter[d])) {
                database[i].surname[u] = enter[d];
                u++;
            }
        }
        while (u == 0) {
            u = 0;
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            for (d = 0; enter[d] != '\n'; d++) {
                if (isalpha(enter[d])) {
                    database[i].surname[u] = enter[d];
                    u++;
                }
            }
        }
        database[i].surname[u] = '\0';
        enter[0] = '\0';
        u = 0;
        printf("Введите имя %d пациента: ", k);
        fgets(enter, lenght, stdin);
        for (d = 0; enter[d] != '\n'; d++) {
            if (isalpha(enter[d])) {
                database[i].name[u] = enter[d];
                u++;
            }
        }
        while (u == 0) {
            u = 0;
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            for (d = 0; enter[d] != '\n'; d++) {
                if (isalpha(enter[d])) {
                    database[i].name[u] = enter[d];
                    u++;
                }
            }
        }
        database[i].name[u] = '\0';
        enter[0] = '\0';
        u = 0;
        printf("Введите отчество %d пациента: ", k);
        fgets(enter, lenght, stdin);
        for (d = 0; enter[d] != '\n'; d++) {
            if (isalpha(enter[d])) {
                database[i].patronym[u] = enter[d];
                u++;
            }
        }
        while (u == 0) {
            u = 0;
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            for (d = 0; enter[d] != '\n'; d++) {
                if (isalpha(enter[d])) {
                    database[i].patronym[u] = enter[d];
                    u++;
                }
            }
        }
        database[i].patronym[u] = '\0';
        enter[0] = '\0';
        u = 0;
        printf("Введите год рождения %d пациента: ", k);
        fgets(enter, lenght, stdin);
        database[i].birth = Validator(enter);
        enter[0] = '\0';
        while (database[i].birth < 1900 || database[i].birth > 2022) {
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            database[i].birth = Validator(enter);
            enter[0] = '\0';
        }
        printf("Введите номер телефона %d пациента: ", k);
        fgets(enter, lenght, stdin);
        database[i].phoneNum = Validator(enter);
        enter[0] = '\0';
        while (database[i].phoneNum < 70000000000 || database[i].phoneNum >= 90000000000) {
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            database[i].phoneNum = Validator(enter);
            enter[0] = '\0';
        }
        printf("Введите адрес %d пациента: ", k);
        fgets(database[i].address, lenght, stdin);
        while (database[i].address[0] == '\n')
        {
            printf("Введите корректные данные: ");
            fgets(database[i].address, lenght, stdin);
        }
        for (t = 0; database[i].address[t] != '\n'; t++);
        database[i].address[t] = '\0';
        printf("Введите номер медицинской карты %d пациента: ", k);
        fgets(enter, lenght, stdin);
        database[i].medCard = Validator(enter);
        enter[0] = '\0';
        while (database[i].medCard <= 0 || database[i].medCard >= 10000000000) {
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            database[i].medCard = Validator(enter);
            enter[0] = '\0';
        }
        printf("Введите группу крови %d пациента: ", k);
        fgets(enter, lenght, stdin);
        database[i].bloodType = Validator(enter);
        enter[0] = '\0';
        while (database[i].bloodType < 1 || database[i].bloodType > 4) {
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            database[i].bloodType = Validator(enter);
            enter[0] = '\0';
        }
        printf("Введите резус-фактор %d пациента: ", k);
        fgets(enter, lenght, stdin);
        database[i].rhFact = rhValidator(enter);
        enter[0] = '\0';
        while ((database[i].rhFact != '-') && (database[i].rhFact != '+')) {
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            database[i].rhFact = rhValidator(enter);
            enter[0] = '\0';
        }
        printf("Введите диагноз %d пациента: ", k);
        fgets(database[i].diagnosis, lenght, stdin);
        while (database[i].diagnosis[0] == '\n')
        {
            printf("Введите корректные данные: ");
            fgets(database[i].diagnosis, lenght, stdin);

        }
        for (t = 0; database[i].diagnosis[t] != '\n'; t++);
        database[i].diagnosis[t] = '\0';
        printf("\n");
    }
    return i;
}

void DataOutput(FILE* fout, int i)
{
    fprintf(fout, "%s\t", database[i].surname);
    fprintf(fout, "%s\t", database[i].name);
    fprintf(fout, "%s\t", database[i].patronym);
    fprintf(fout, "%d\t", database[i].birth);
    fprintf(fout, "%lld\t", database[i].phoneNum);
    fprintf(fout, "%s\t", database[i].address);
    fprintf(fout, "%lld\t", database[i].medCard);
    fprintf(fout, "%d\t", database[i].bloodType);
    fprintf(fout, "%c\t", database[i].rhFact);
    fprintf(fout, "%s\n", database[i].diagnosis);
}

void DataOutputP(FILE* fout, int i)
{
    fprintf(fout, "%s\t", ptp[i]->surname);
    fprintf(fout, "%s\t", ptp[i]->name);
    fprintf(fout, "%s\t", ptp[i]->patronym);
    fprintf(fout, "%d\t", ptp[i]->birth);
    fprintf(fout, "%lld\t", ptp[i]->phoneNum);
    fprintf(fout, "%s\t", ptp[i]->address);
    fprintf(fout, "%lld\t", ptp[i]->medCard);
    fprintf(fout, "%d\t", ptp[i]->bloodType);
    fprintf(fout, "%c\t", ptp[i]->rhFact);
    fprintf(fout, "%s\n", ptp[i]->diagnosis);
}

void DataShow(int i)
{
    int k = i + 1;
    printf("Фамилия %d пациента: %s\n", k, database[i].surname);
    printf("Имя %d пациента: %s\n", k, database[i].name);
    printf("Отчество %d пациента: %s\n", k, database[i].patronym);
    printf("Год рождения %d пациента: %d\n", k, database[i].birth);
    printf("Номер телефона %d пациента: %lld\n", k, database[i].phoneNum);
    printf("Адрес %d пациента: %s\n", k, database[i].address);
    printf("Номер медицинской карты %d пациента: %lld\n", k, database[i].medCard);
    printf("Группа крови %d пациента: %d\n", k, database[i].bloodType);
    printf("Резус-фактор %d пациента: %c\n", k, database[i].rhFact);
    printf("Диагноз %d пациента: %s\n", k, database[i].diagnosis);
    printf("\n");
}

void SearchBySurname(int stop, FILE* fout)
{
    char search[lenght], enter[lenght];
    int u = 0, d, count = 0;
    printf("Введите искомое значение: ");
    fgets(enter, lenght, stdin);
    for (d = 0; enter[d] != '\n'; d++) {
        if (isalpha(enter[d])) {
            search[u] = enter[d];
            u++;
        }
    }
    search[u] = '\0';
    enter[0] = '\0';
    while (u == 0) {
        printf("Введите корректные данные: ");
        fgets(enter, lenght, stdin);
        for (d = 0; enter[d] != '\n'; d++) {
            if (isalpha(enter[d])) {
                search[u] = enter[d];
                u++;
            }
        }
    }
    search[u] = '\0';
    fprintf(fout, "%s", "Параметр поиска: фамилия. Искомое значение: "); fprintf(fout, "%s\n", search);
    for (int i = 0; i < stop; i++) {
        if (strcmp(search, database[i].surname) == 0) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchByName(int stop, FILE* fout)
{
    char search[lenght], enter[lenght];
    int u = 0, d, count = 0;
    printf("Введите искомое значение: ");
    fgets(enter, lenght, stdin);
    for (d = 0; enter[d] != '\n'; d++) {
        if (isalpha(enter[d])) {
            search[u] = enter[d];
            u++;
        }
    }
    search[u] = '\0';
    enter[0] = '\0';
    while (u == 0) {
        printf("Введите корректные данные: ");
        fgets(enter, lenght, stdin);
        for (d = 0; enter[d] != '\n'; d++) {
            if (isalpha(enter[d])) {
                search[u] = enter[d];
                u++;
            }
        }
    }
    search[u] = '\0';
    fprintf(fout, "%s", "Параметр поиска: имя. Искомое значение: "); fprintf(fout, "%s\n", search);
    for (int i = 0; i < stop; i++) {
        if (strcmp(search, database[i].name) == 0) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchByPatronym(int stop, FILE* fout)
{
    char search[lenght], enter[lenght];
    int u = 0, d, count = 0;
    printf("Введите искомое значение: ");
    fgets(enter, lenght, stdin);
    for (d = 0; enter[d] != '\n'; d++) {
        if (isalpha(enter[d])) {
            search[u] = enter[d];
            u++;
        }
    }
    search[u] = '\0';
    enter[0] = '\0';
    while (u == 0) {
        printf("Введите корректные данные: ");
        fgets(enter, lenght, stdin);
        for (d = 0; enter[d] != '\n'; d++) {
            if (isalpha(enter[d])) {
                search[u] = enter[d];
                u++;
            }
        }
    }
    search[u] = '\0';
    fprintf(fout, "%s", "Параметр поиска: отчество. Искомое значение: "); fprintf(fout, "%s\n", search);
    for (int i = 0; i < stop; i++) {
        if (strcmp(search, database[i].patronym)) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchByBirth(int stop, FILE* fout)
{
    int search, count = 0;
    char enter[lenght];
    printf("Введите искомое значение: ");
    fgets(enter, lenght, stdin);
    search = Validator(enter);
    enter[0] = '\0';
    while (!(search)) {
        printf("Введите корректные данные: ");
        fgets(enter, lenght, stdin);
        search = Validator(enter);
        enter[0] = '\0';
    }
    fprintf(fout, "%s", "Параметр поиска: год рождения. Искомое значение: "); fprintf(fout, "%d\n", search);
    for (int i = 0; i < stop; i++) {
        if (search == database[i].birth) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchByPhoneNum(int stop, FILE* fout)
{
    long long int search;
    char enter[lenght];
    int count = 0;
    printf("Введите искомое значение: ");
    fgets(enter, lenght, stdin);
    search = Validator(enter);
    enter[0] = '\0';
    while (!(search)) {
        printf("Введите корректные данные: ");
        fgets(enter, lenght, stdin);
        search = Validator(enter);
        enter[0] = '\0';
    }
    fprintf(fout, "%s", "Параметр поиска: номер телефона. Искомое значение: "); fprintf(fout, "%lld\n", search);
    for (int i = 0; i < stop; i++) {
        if (search == database[i].phoneNum) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchByAddress(int stop, FILE* fout)
{
    char search[lenght];
    int n, count = 0;
    printf("Введите искомое значение: ");
    fgets(search, lenght, stdin);
    for (n = 0; search[n] != '\n'; n++);
    search[n] = '\0';
    fprintf(fout, "%s", "Параметр поиска: адрес. Искомое значение: "); fprintf(fout, "%s\n", search);
    for (int i = 0; i < stop; i++) {
        if (strcmp(search, database[i].address) == 0) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchByMedCard(int stop, FILE* fout)
{
    long long int search;
    char enter[lenght];
    int count = 0;
    printf("Введите искомое значение: ");
    fgets(enter, lenght, stdin);
    search = Validator(enter);
    enter[0] = '\0';
    while (!(search)) {
        printf("Введите корректные данные: ");
        fgets(enter, lenght, stdin);
        search = Validator(enter);
        enter[0] = '\0';
    }
    fprintf(fout, "%s", "Параметр поиска: номер медицинской карты. Искомое значение: "); fprintf(fout, "%lld\n", search);
    for (int i = 0; i < stop; i++) {
        if (search == database[i].medCard) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchByBloodType(int stop, FILE* fout)
{
    int search, count = 0;
    char enter[lenght];
    printf("Введите искомое значение: ");
    fgets(enter, lenght, stdin);
    search = Validator(enter);
    enter[0] = '\0';
    while (!(search)) {
        printf("Введите корректные данные: ");
        fgets(enter, lenght, stdin);
        search = Validator(enter);
        enter[0] = '\0';
    }
    fprintf(fout, "%s", "Параметр поиска: группа крови. Искомое значение: "); fprintf(fout, "%d\n", search);
    for (int i = 0; i < stop; i++) {
        if (search == database[i].bloodType) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchByRhFact(int stop, FILE* fout)
{
    char search;
    char enter[lenght];
    int count = 0;
    printf("Введите искомое значение: ");
    fgets(enter, lenght, stdin);
    search = rhValidator(enter);
    enter[0] = '\0';
    while ((search != '-') && (search != '+')) {
        printf("Введите корректные данные: ");
        fgets(enter, lenght, stdin);
        search = rhValidator(enter);
        enter[0] = '\0';
    }
    fprintf(fout, "%s", "Параметр поиска: резус-фактор. Искомое значение: "); fprintf(fout, "%c\n", search);
    for (int i = 0; i < stop; i++) {
        if (search == database[i].rhFact) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchByDiagnosis(int stop, FILE* fout)
{
    char search[lenght];
    int n, count = 0;
    printf("Введите искомое значение: ");
    fgets(search, lenght, stdin);
    for (n = 0; search[n] != '\n'; n++);
    search[n] = '\0';
    fprintf(fout, "%s", "Параметр поиска: диагноз. Искомое значение: "); fprintf(fout, "%s\n", search);
    for (int i = 0; i < stop; i++) {
        if (strcmp(search, database[i].diagnosis) == 0) {
            DataOutput(fout, i);
            count++;
        }
    }
    if (count == 0) { puts("Пациент с искомым значением не найден.\n"); fprintf(fout, "%s", "Пациент с искомым значением не найден.\n"); }
    else { printf("Пациентов найдено: %d.\n\n", count); }
    fprintf(fout, "%c", '\n');
}

void SearchStart(int check, FILE* fout)
{
    int searchOpt = 1;
    char enter[lenght];
    while (searchOpt)
    {
        printf("Выберите опцию поиска:\n");
        printf("1 - фамилия;\n");
        printf("2 - имя;\n");
        printf("3 - отчество;\n");
        printf("4 - год рождения\n");
        printf("5 - номер телефона;\n");
        printf("6 - адрес;\n");
        printf("7 - номер медицинской карты;\n");
        printf("8 - группа крови.\n");
        printf("9 - резус-фактор;\n");
        printf("10 - диагноз.\n");
        printf("11 - завершение поиска.\n");
        printf("Выбранный элемент: ");
        fgets(enter, lenght, stdin);
        searchOpt = Validator(enter);
        enter[0] = '\0';
        while ((searchOpt < 1) || (searchOpt > 11)) {
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            searchOpt = Validator(enter);
            enter[0] = '\0';
        }
        printf("\n");
        switch (searchOpt) {
        case 1: { SearchBySurname(check, fout); break; }
        case 2: { SearchByName(check, fout); break; }
        case 3: { SearchByPatronym(check, fout); break; }
        case 4: { SearchByBirth(check, fout); break; }
        case 5: { SearchByPhoneNum(check, fout); break; }
        case 6: { SearchByAddress(check, fout); break; }
        case 7: { SearchByMedCard(check, fout); break; }
        case 8: { SearchByBloodType(check, fout); break; }
        case 9: { SearchByRhFact(check, fout); break; }
        case 10: { SearchByDiagnosis(check, fout); break; }
        case 11: { puts("Поиск завершен.\n"); searchOpt = 0; break; }
        default: { puts("Произошло божественное вмешательство\n"); break; }
        }
    }
}

void SortBySurname(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: фамилия.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (strcmp(ptp[j]->surname, ptp[j + 1]->surname) > 0) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortByName(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: имя.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (strcmp(ptp[j]->name, ptp[j + 1]->name) > 0) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortByPatronym(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: отчество.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (strcmp(ptp[j]->patronym, ptp[j + 1]->patronym) > 0) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortByBirth(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: год рождения.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (ptp[j + 1]->birth < ptp[j]->birth) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortByPhoneNum(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: номер телефона.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (ptp[j + 1]->phoneNum < ptp[j]->phoneNum) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortByAddress(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: адрес.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (strcmp(ptp[j]->address, ptp[j + 1]->address) > 0) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortByMedCard(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: номер медицинской карты.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (ptp[j + 1]->medCard < ptp[j]->medCard) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortByBloodType(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: группа крови.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (ptp[j + 1]->bloodType < ptp[j]->bloodType) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortByRhFact(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: резус-фактор.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (ptp[j]->rhFact < ptp[j + 1]->rhFact) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortByDiagnosis(PointerToPatient ptp[], int stop, FILE* fout)
{
    fprintf(fout, "%s", "Параметр сортировки: диагноз.\n");
    PointerToPatient temp;
    int i, j;
    for (i = 0; i < stop - 1; i++) {
        for (j = stop - 2; j >= i; j--) {
            if (strcmp(ptp[j]->diagnosis, ptp[j + 1]->diagnosis) > 0) {
                temp = ptp[j];
                ptp[j] = ptp[j + 1];
                ptp[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < stop; i++) { DataOutputP(fout, i); }
}

void SortStart(int check, FILE* fout)
{
    int sortOpt = 1;
    char enter[lenght];
    while (sortOpt)
    {
        printf("Выберите опцию сортировки:\n");
        printf("1 - фамилия;\n");
        printf("2 - имя;\n");
        printf("3 - отчество;\n");
        printf("4 - год рождения;\n");
        printf("5 - номер телефона;\n");
        printf("6 - адрес;\n");
        printf("7 - номер медицинской карты;\n");
        printf("8 - группа крови;\n");
        printf("9 - резус-фактор;\n");
        printf("11 - завершить сортировку.\n");
        printf("10 - диагноз;\n");
        printf("11 - завершение сортировки.\n");
        printf("Выбранная опция: ");
        fgets(enter, lenght, stdin);
        sortOpt = Validator(enter);
        enter[0] = '\0';
        while ((sortOpt < 1) || (sortOpt > 11)) {
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            sortOpt = Validator(enter);
            enter[0] = '\0';
        }
        printf("%c", '\n');
        switch (sortOpt) {
        case 1: { SortBySurname(ptp, check, fout); break; }
        case 2: { SortByName(ptp, check, fout); break; }
        case 3: { SortByPatronym(ptp, check, fout); break; }
        case 4: { SortByBirth(ptp, check, fout); break; }
        case 5: { SortByPhoneNum(ptp, check, fout); break; }
        case 6: { SortByAddress(ptp, check, fout); break; }
        case 7: { SortByMedCard(ptp, check, fout); break; }
        case 8: { SortByBloodType(ptp, check, fout); break; }
        case 9: { SortByRhFact(ptp, check, fout); break; }
        case 10: { SortByDiagnosis(ptp, check, fout); break; }
        case 11: { puts("Сортировка завершена.\n"); sortOpt = 0; break; }
        default: { puts("Произошло божественное вмешательство\n"); break; }
        }
        if (sortOpt != 0) { fprintf(fout, "%c", '\n'); }
    }
}

void OptionSelection(int check, FILE* fout)
{
    int opt = 1, i;
    char enter[lenght];
    while (opt)
    {
        printf("Выберите опцию:\n");
        printf("1 - добавление пациента в базу данных;\n");
        printf("2 - поиск пациента с заданным значением выбранного элемента;\n");
        printf("3 - вывод на экран содержимого базы данных;\n");
        printf("4 - упорядочение базы данных по заданному элементу;\n");
        printf("5 - завершение работы.\n");
        printf("Выбранная опция: ");
        fgets(enter, lenght, stdin);
        opt = Validator(enter);
        enter[0] = '\0';
        while ((opt < 1) || (opt > 5))
        {
            printf("Введите корректные данные: ");
            fgets(enter, lenght, stdin);
            opt = Validator(enter);
            enter[0] = '\0';
        }
        printf("\n");
        switch (opt) {
        case 1: {
            if (check >= data) { puts("База данных переполнена, невозможно внести нового пациента.\n"); }
            else { DataInput(check); check++; }
            break; }
        case 2: {
            SearchStart(check, fout);
            fprintf(fout, "%c", '\n');
            break; }
        case 3: {
            for (i = 0; i < check; i++) { DataShow(i); }
            break; }
        case 4: {
            for (int i = 0; i < check; i++) { ptp[i] = &database[i]; }
            SortStart(check, fout);
            fprintf(fout, "%c", '\n');
            break; }
        case 5: { puts("Работа завершена."); opt = 0; break; }
        default: { puts("Произошло божественное вмешательство\n"); break; }
        }
    }
    fprintf(fout, "%s", "Пациенты:\n");
    for (i = 0; i < check; i++) { DataOutput(fout, i); }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    FILE* fout = fopen("list.txt", "w");
    if (fout == NULL) { puts("Ошибка работы с файлом"); return 0; }
    int check = DataInput(0);
    if (check == 0) return 0;
    OptionSelection(check, fout);
    fclose(fout);
    return 0;
}
