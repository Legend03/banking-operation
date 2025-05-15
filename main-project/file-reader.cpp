#include "file-reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

using namespace std;

Date convert_date(char* str)
{
    Date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.year = str_number;
    str_number = strtok_s(NULL, ".", &context);
    result.month = str_number;
    str_number = strtok_s(NULL, ".", &context);
    result.day = str_number;
    return result;
}

Time convert_time(char* str)
{
    Time result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.hours = str_number;
    str_number = strtok_s(NULL, ":", &context);
    result.minutes = str_number;
    return result;
}

void read(const char* file_name, Banking_operation* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            Banking_operation* item = new Banking_operation;
            file >> tmp_buffer;
            item->date = convert_date(tmp_buffer);
            file >> tmp_buffer;
            item->time = convert_time(tmp_buffer);
            file >> item->kindOperation;
            file >> item->bankAccount;
            file >> item->amount;
            file.get(); // чтения лишнего символа пробела
            getline(file >> ws, item->discription);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "Ошибка открытия файла";
    }
}