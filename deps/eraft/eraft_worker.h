#include <stdbool.h>

#include "ev.h"
#include "libevcoro.h"

#include "eraft_tasker.h"

struct eraft_worker {
	struct evcoro_scheduler *scheduler;
	struct ev_loop *loop;

	struct eraft_tasker_once tasker;

	ERAFT_TASKER_ONCE_FCB fcb;
	void *usr;
	pthread_t pid;
	bool exit;
};

int eraft_worker_init(struct eraft_worker *worker, ERAFT_TASKER_ONCE_FCB fcb, void *usr);

int eraft_worker_free(struct eraft_worker *worker);

void eraft_worker_give(struct eraft_worker *worker, struct eraft_dotask *task);
