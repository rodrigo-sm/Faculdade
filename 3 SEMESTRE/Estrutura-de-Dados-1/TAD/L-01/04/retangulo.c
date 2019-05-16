#include "retangulo.h"
#include <stdbool.h>

void ret_init(retangulo * r, int x, int y, int alt, int comp)
{
    r->p.x = x;
    r->p.y = y;
    r->alt = alt;
    r->comp = comp;
}

int ret_area(retangulo r)
{
    return (r.alt * r.comp);
}

bool ret_contains(retangulo r, ponto p)
{
    // Representa o ponto inferior direito
    ponto pid;
    pid.x = r.p.x - r.comp;
    pid.y = r.p.y - r.alt;
    if((pid.x <= p.x) && (r.p.x >= p.x) && (pid.y <= p.y) && (r.p.y >= p.y))
        return true;
    return false;
}
