#include "kernel/res/qsocket.h"
#include "genos/container/hashtable.h"


char hashbuf[sizeof(hlist_head) * 20];
hashtable<qsocket, &qsocket::hlnk, id_t, &qsocket::id> qsocket_table;

void qsocket_table_init() {
	qsocket_table.init(hashbuf, sizeof(hlist_head) * 20, idhash, idcmp);
};

void qsocket_open(id_t id) {

};

void qsocket_close(id_t id) {

};