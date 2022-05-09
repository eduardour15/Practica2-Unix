/*Hora.c*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// se definen las variables globales del tiempo
struct fecha_t
{
    int anio, mes, dia, hora, minutos;
};
struct fecha_t *fechactual;
// Declaramos la variable para los segundos transcurridos desde 1970
time_t segundos;
int result;
int obten_segundos(time_t *s)
{
    // Obtención de los segundos desde el sistema operativo
    time(s);
    if (s == NULL)
        return -1;
    else
        return 0;
}
struct fecha_t *obten_fecha(time_t *s)
{
    struct fecha_t *fecha;
    // Declaración de un puntero a un objeto con la información del tiempo
    struct tm *puntero_estructura_tiempo;
    fecha = (struct fecha_t *)malloc(sizeof(struct fecha_t));
    // Actualización del objeto estructura de tiempo con los segundos
    puntero_estructura_tiempo = localtime(s);
    // Estracción de la información desde la estructura tiempo
    fecha->hora = puntero_estructura_tiempo->tm_hour;
    fecha->minutos = puntero_estructura_tiempo->tm_min;
    return fecha;
}
void escribe_hora(struct fecha_t *fecha)
{
    printf("Son las %i:%s%i horas\n", fecha->hora, fecha->minutos < 10 ? "0" : " ", fecha->minutos);
}
int main()
{
    result = obten_segundos(&segundos);
    if (result == -1)
    {
        printf("Hora.c: error en la llamada time\n");
        exit(1);
    }
    fechactual = obten_fecha(&segundos);
    escribe_hora(fechactual);
}