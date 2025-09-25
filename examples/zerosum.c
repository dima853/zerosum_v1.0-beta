#include <stdio.h>
#include <math.h>
#include "../include/zerosum.h"

int main()
{
    printf("=== РЕАЛЬНЫЙ ТЕСТ ZEROSUM ALGORITHM ===\n\n");

    int n = 23;
    double f0 = 0.932348924532723;
    double user_s0 = -n * f0;
    double sequence[n];

    printf("📋 Параметры теста:\n");
    printf("   Длина (n): %d\n", n);
    printf("   Фактор (f0): %.15f\n", f0);
    printf("   Ожидаемый s0: %.15f\n\n", user_s0);

    int result = _F10_(sequence, n, f0, user_s0);

    if (result != 0)
    {
        printf("❌ ОШИБКА: Не удалось сгенерировать последовательность (код: %d)\n", result);
        return 1;
    }

    printf("✅ Последовательность сгенерирована успешно!\n\n");

    double total_sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        total_sum += sequence[i];
    }

    double s0_error = fabs(sequence[0] - user_s0);

    printf("📊 РЕАЛЬНЫЕ РЕЗУЛЬТАТЫ:\n");
    printf("   Полученный s0: %.15f\n", sequence[0]);
    printf("   Ошибка s0: %.2e\n", s0_error);
    printf("   Общая сумма: %.15e\n", total_sum);
    printf("   Отклонение от нуля: %.2e\n\n", fabs(total_sum));
}