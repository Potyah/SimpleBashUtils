# SimpleBashUtils

## Реализация утилит cat и grep

- Программы разработаны на языке Си
- Программа разработана в соответствии с принципами структурного программирования
- Сборка программ настроена с помощью Makefile

---

### Опции cat:
- -b (нумерует только непустые строки)
- -e (отображает символы конца строки как $)
- -n (нумерует все выходные строки)
- -s (сжимает несколько смежных пустых строк)
- -t (отображает табы как ^I)

### Опции grep:

- -e (шаблон)
- -i (игнорирование различия регистра)
- -v (инвертирование смысла поиска соответствий)
- -c (вывод количества совпадающих строк)
- -l (вывод совпадающих файлов)
- -n (предваряет каждую строку вывода номером строки из файла ввода)
- -h (вывод совпадающих строк, не предваряя их именами файлов)
- -s (подавление сообщения об ошибках о несуществующих или нечитаемых файлах)
- -f file (получение регулярных выражений из файла)
- -o (печатать только совпадающих (непустые) частей совпавшей строки)
