#include "main.h"
#include "sogi.h"
#include "arm_math.h"

void SOGI_init(SOGI_s * s)
{
    s -> Ug = 0;
    s -> Ua = 0;
    s -> Ub = 0;
    s -> k = SOGI_K;
    s -> W0 = CENTER_FREQ * 2 * PI;
    s -> dt = SAMPLE_TIME;
}

void SOGI_calculate(SOGI_s * s)
{
    s -> Ua += ((s -> Ug - s -> Ua) * s -> k - s -> Ub) * s -> W0 * s -> dt;
    LIMIT(s -> Ua, -1.0, 1.0);
    s -> Ub += s -> Ua * s -> W0 * s -> dt;
    LIMIT(s -> Ub, -1.0, 1.0);
}
