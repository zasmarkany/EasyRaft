#include "eraft_taskis.h"

struct eraft_taskis_group_add *eraft_taskis_group_add_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	struct eraft_group *group, struct etask *etask)
{
	struct eraft_taskis_group_add *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_GROUP_ADD, identity, _fcb, _usr);

	/*设置属性*/
	object->group = group;
	object->etask = etask;
	return object;
}

void eraft_taskis_group_add_free(struct eraft_taskis_group_add *object)
{
	eraft_dotask_free(&object->base);
	free(object);
}

struct eraft_taskis_group_del *eraft_taskis_group_del_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr, struct etask *etask)
{
	struct eraft_taskis_group_del *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_GROUP_DEL, identity, _fcb, _usr);

	object->etask = etask;
	return object;
}

void eraft_taskis_group_del_free(struct eraft_taskis_group_del *object)
{
	eraft_dotask_free(&object->base);
	free(object);
}

struct eraft_taskis_request_write *eraft_taskis_request_write_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	struct iovec *request, struct etask *etask)
{
	struct eraft_taskis_request_write *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_REQUEST_WRITE, identity, _fcb, _usr);

	object->request = request;
	object->etask = etask;
	object->efd = -1;
	object->idx = -1;
	return object;
}

void eraft_taskis_request_write_free(struct eraft_taskis_request_write *object)
{
	eraft_dotask_free(&object->base);

	free(object);
}

struct eraft_taskis_request_read *eraft_taskis_request_read_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	struct iovec *request, struct etask *etask)
{
	struct eraft_taskis_request_read *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_REQUEST_READ, identity, _fcb, _usr);

	object->request = request;
	object->etask = etask;
	return object;
}

void eraft_taskis_request_read_free(struct eraft_taskis_request_read *object)
{
	eraft_dotask_free(&object->base);

	free(object);
}

struct eraft_taskis_log_retain *eraft_taskis_log_retain_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	struct eraft_evts *evts, struct eraft_journal *journal, raft_batch_t *batch, raft_index_t start_idx, void *usr)
{
	struct eraft_taskis_log_retain *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_LOG_RETAIN, identity, _fcb, _usr);

	object->evts = evts;
	object->journal = journal;
	object->batch = batch;
	object->start_idx = start_idx;
	object->usr = usr;
	return object;
}

void eraft_taskis_log_retain_free(struct eraft_taskis_log_retain *object)
{
	eraft_dotask_free(&object->base);

	free(object);
}

struct eraft_taskis_log_retain_done *eraft_taskis_log_retain_done_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	raft_batch_t *batch, raft_index_t start_idx, void *usr)
{
	struct eraft_taskis_log_retain_done *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_LOG_RETAIN_DONE, identity, _fcb, _usr);

	/*设置属性*/
	object->batch = batch;
	object->start_idx = start_idx;
	object->usr = usr;
	return object;
}

void eraft_taskis_log_retain_done_free(struct eraft_taskis_log_retain_done *object)
{
	eraft_dotask_free(&object->base);

	free(object);
}

struct eraft_taskis_log_remind *eraft_taskis_log_remind_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	struct eraft_evts *evts, raft_batch_t *batch, raft_index_t start_idx, void *usr)
{
	struct eraft_taskis_log_remind *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_LOG_REMIND, identity, _fcb, _usr);

	object->evts = evts;
	object->batch = batch;
	object->start_idx = start_idx;
	object->usr = usr;
	return object;
}

void eraft_taskis_log_remind_free(struct eraft_taskis_log_remind *object)
{
	eraft_dotask_free(&object->base);

	free(object);
}

struct eraft_taskis_log_append *eraft_taskis_log_append_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	struct eraft_evts *evts, struct eraft_journal *journal, raft_batch_t *batch, raft_index_t start_idx,
	raft_node_t *node, raft_index_t leader_commit, raft_index_t rsp_first_idx)
{
	struct eraft_taskis_log_append *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_LOG_APPEND, identity, _fcb, _usr);

	/*设置属性*/
	object->evts = evts;
	object->journal = journal;
	object->batch = batch;
	object->start_idx = start_idx;
	object->raft_node = node;
	object->leader_commit = leader_commit;
	object->rsp_first_idx = rsp_first_idx;
	return object;
}

void eraft_taskis_log_append_free(struct eraft_taskis_log_append *object)
{
	eraft_dotask_free(&object->base);

	free(object);
}

struct eraft_taskis_log_append_done *eraft_taskis_log_append_done_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	struct eraft_evts *evts, raft_batch_t *batch, raft_index_t start_idx,
	raft_node_t *node, raft_index_t leader_commit, raft_index_t rsp_first_idx)
{
	struct eraft_taskis_log_append_done *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_LOG_APPEND_DONE, identity, _fcb, _usr);

	/*设置属性*/
	object->evts = evts;
	object->batch = batch;
	object->start_idx = start_idx;
	object->raft_node = node;
	object->leader_commit = leader_commit;
	object->rsp_first_idx = rsp_first_idx;
	return object;
}

void eraft_taskis_log_append_done_free(struct eraft_taskis_log_append_done *object)
{
	eraft_dotask_free(&object->base);

	free(object);
}

struct eraft_taskis_log_apply *eraft_taskis_log_apply_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	struct eraft_evts *evts, raft_batch_t *batch, raft_index_t start_idx)
{
	struct eraft_taskis_log_apply *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_LOG_APPLY, identity, _fcb, _usr);

	/*设置属性*/
	object->evts = evts;
	object->batch = batch;
	object->start_idx = start_idx;
	return object;
}

void eraft_taskis_log_apply_free(struct eraft_taskis_log_apply *object)
{
	eraft_dotask_free(&object->base);

	free(object);
}

struct eraft_taskis_log_apply_done *eraft_taskis_log_apply_done_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	raft_batch_t *batch, raft_index_t start_idx)
{
	struct eraft_taskis_log_apply_done *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_LOG_APPLY_DONE, identity, _fcb, _usr);

	/*设置属性*/
	object->batch = batch;
	object->start_idx = start_idx;
	return object;
}

void eraft_taskis_log_apply_done_free(struct eraft_taskis_log_apply_done *object)
{
	eraft_dotask_free(&object->base);

	free(object);
}

struct eraft_taskis_net_append *eraft_taskis_net_append_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	msg_appendentries_t *ae, raft_node_t *node)
{
	struct eraft_taskis_net_append *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_NET_APPEND, identity, _fcb, _usr);

	object->node = node;
	object->ae = malloc(sizeof(msg_appendentries_t));
	memcpy(object->ae, ae, sizeof(msg_appendentries_t));
	return object;
}

void eraft_taskis_net_append_free(struct eraft_taskis_net_append *object)
{
	eraft_dotask_free(&object->base);

	free(object->ae);
	free(object);
}

struct eraft_taskis_net_append_response *eraft_taskis_net_append_response_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	msg_appendentries_response_t *aer, raft_node_t *node)
{
	struct eraft_taskis_net_append_response *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_NET_APPEND_RESPONSE, identity, _fcb, _usr);

	object->node = node;
	object->aer = malloc(sizeof(msg_appendentries_response_t));
	memcpy(object->aer, aer, sizeof(msg_appendentries_response_t));
	return object;
}

void eraft_taskis_net_append_response_free(struct eraft_taskis_net_append_response *object)
{
	eraft_dotask_free(&object->base);

	free(object->aer);
	free(object);
}

struct eraft_taskis_net_vote *eraft_taskis_net_vote_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	msg_requestvote_t *rv, raft_node_t *node)
{
	struct eraft_taskis_net_vote *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_NET_VOTE, identity, _fcb, _usr);

	object->node = node;
	object->rv = malloc(sizeof(msg_requestvote_t));
	memcpy(object->rv, rv, sizeof(msg_requestvote_t));
	return object;
}

void eraft_taskis_net_vote_free(struct eraft_taskis_net_vote *object)
{
	eraft_dotask_free(&object->base);

	free(object->rv);
	free(object);
}

struct eraft_taskis_net_vote_response *eraft_taskis_net_vote_response_make(char *identity, ERAFT_DOTASK_FCB _fcb, void *_usr,
	msg_requestvote_response_t *rvr, raft_node_t *node)
{
	struct eraft_taskis_net_vote_response *object = calloc(1, sizeof(*object));

	eraft_dotask_init(&object->base, ERAFT_TASK_NET_VOTE_RESPONSE, identity, _fcb, _usr);

	object->node = node;
	object->rvr = malloc(sizeof(msg_requestvote_response_t));
	memcpy(object->rvr, rvr, sizeof(msg_requestvote_response_t));
	return object;
}

void eraft_taskis_net_vote_response_free(struct eraft_taskis_net_vote_response *object)
{
	eraft_dotask_free(&object->base);

	free(object->rvr);
	free(object);
}

