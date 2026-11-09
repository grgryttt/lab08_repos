#pragma once
#include <string>

// Пошук першого входження пари сусідніх букв "aa", "bb" або "cc" у рядку s,
// починаючи з позиції pos. Повертає позицію пари або string::npos, якщо пари немає
size_t FindPair(const std::string& s, const size_t pos = 0);

// З'ясовує, чи є у рядку s пара сусідніх букв "aa" або "bb" або "cc"
bool HasPair(const std::string& s);

// Заміна кожної пари сусідніх букв "aa" або "bb" або "cc" трійкою зірочок "***".
// Рядок s не змінюється; результат повертається як новий рядок
std::string Change(const std::string& s);
