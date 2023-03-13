#include "ImpTimer.h"
#include "CommonFunction.h"

void ImpTimer_init(ImpTimer* timer) {
	timer->start_tick = 0;
	timer->paused_tick = 0;
	timer->is_paused = 0;
	timer->is_started = 0;
}

void ImpTimer_start(ImpTimer* timer) {
	timer->is_started = 1;
	timer->is_paused = 1;
	timer->start_tick = SDL_GetTicks();
}

void ImpTimer_stop(ImpTimer* timer) {
	timer->is_paused = 0;
	timer->is_started = 0;
}

void ImpTimer_paused(ImpTimer* timer) {
	if (timer->is_started && !timer->is_paused) {
		timer->is_paused = 1;
		timer->paused_tick = SDL_GetTicks() - timer->start_tick;
	}
}

void ImpTimer_unpaused(ImpTimer* timer) {
	if (timer->is_paused) {
		timer->is_paused = 0;
		timer->start_tick = SDL_GetTicks() - timer->paused_tick;
		timer->paused_tick = 0;
	}
}

int ImpTimer_get_ticks(ImpTimer* timer) {
	if (timer->is_started) {
		if (timer->is_paused) {
			return timer->paused_tick;
		}
		else {
			return SDL_GetTicks() - timer->start_tick;
		}
	}
	return 0;
}

int ImpTimer_is_started(ImpTimer* timer) {
	return timer->is_started;
}

int ImpTimer_is_paused(ImpTimer* timer) {
	return timer->is_paused;
}