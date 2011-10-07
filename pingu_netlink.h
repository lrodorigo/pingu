#ifndef PINGU_NETLINK_H
#define PINGU_NETLINK_H

#include <ev.h>
#include "pingu_iface.h"

int kernel_init(struct ev_loop *loop);
int kernel_route_modify(int action, struct pingu_route *route,
			struct pingu_iface *iface, int table);
int kernel_route_multipath(int action, struct list_head *iface_list, int table);
void kernel_cleanup_iface_routes(struct pingu_iface *iface);
void kernel_close(void);

#endif
