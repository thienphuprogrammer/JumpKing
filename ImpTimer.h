#ifndef IMP_TIMER_H_
#define IMP_TIMER_H_

typedef struct ImpTimer {
	int start_tick;
	int paused_tick;
	int is_paused;
	int is_started;
} ImpTimer;

void ImpTimer_init(ImpTimer* timer);
void ImpTimer_start(ImpTimer* timer);
void ImpTimer_stop(ImpTimer* timer);
void ImpTimer_paused(ImpTimer* timer);
void ImpTimer_unpaused(ImpTimer* timer);
int ImpTimer_get_ticks(ImpTimer* timer);
int ImpTimer_is_started(ImpTimer* timer);
int ImpTimer_is_paused(ImpTimer* timer);

#endif