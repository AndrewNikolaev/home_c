#ifndef TEMP_FUNCTIONS_H
#define TEMP_FUNCTIONS_H

#include <stdint.h>

typedef struct sensor
{
    uint8_t minute;
    uint8_t hour;
    uint8_t day;
    uint8_t month;
    uint16_t year;
    int8_t t;
} sensor;

extern const char *month_name[];

int min_temp_month(sensor *info, int number, uint8_t month);

int max_temp_month(sensor *info, int number, uint8_t month);

int average_temp_month(sensor *info, int number, uint8_t month);

int min_temp_year(sensor *info, int number);

int max_temp_year(sensor *info, int number);

int average_temp_year(sensor *info, int number);

void print_line(void);

void print_start_table(int show_month);

void print_report_month(sensor *info, int number, uint8_t month);

void print_report_year(sensor *info, int number);

void print_report(sensor *info, int number);

void print_temp(sensor *info, int number);

void print_stat_year(sensor *info, int number);

void print_stat_month(sensor *info, int number, uint8_t month);

void AddRecord(sensor *info, int number,
               uint16_t year, uint8_t month, uint8_t day, uint8_t hour, uint8_t minute, int8_t t);

int CompareByTemp(const void *a, const void *b);

int CompareByDate(const void *a, const void *b);

#endif