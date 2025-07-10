#ifndef __SOGI_H
#define __SOGI_H

#define CENTER_FREQ 50
#define SOGI_K 1
#define SAMPLE_TIME 0.0001

#define LIMIT(x,min,max) (x)=(((x)<=(min))?(min):(((x)>=(max))?(max):(x)))

typedef struct SOGI_Structure
{
    float32_t Ug, Ua, Ub, k, W0, dt;
}SOGI_s;

void SOGI_init(*SOGI_s s);
void SOGI_calculate(*SOGI_s s);

#endif
