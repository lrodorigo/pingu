
Fork of pingu
=====

Pingu is a daemon that takes care of policy routing and fail-over in
multi ISP setups.

**This fork is born to overcome some stupid features of the router installed by the major Italian ISP (aka TIM==Telecom Italia).**

Seems that, after a  disconnection of the phone carrier,  these routers block all the ICMP responses with an `Identifier` field already seen before the disconnection. 

You can verify if your router is affected by this problem with the following easy test:
1. `ping 8.8.8.8`
2. Disconnect the RJ11 phone cable from your router and wait 10 seconds
3. When you start receiving ICMP `No route to host` messages, reconnect the cable
4. When the router correctly reconnects to the Internet, the previous `ping` command does not receive ICMP Echo Replies.
5. *But* a new `ping 8.8.8.8` command properly works.

This version changes the `Identifier` (which, by Linux convention, reports the PID of the process sending the ICMP request) and the modified `Identifier` field is placed to the same value of the `Sequence number`. The processing of the incoming ICMP replies has been modified to compare the `Indentifier` field with the `Sequence number`.




Features
--------
- **Fights again TIM routers stupid features**
- Support for DHCP
- Support for PPP
- ISP failover
- Load-balancing (nexthop)
- Optional route rule based on fwmark
- run script when ISP goes up/down


Build requirements
------------------
- libev 3 or newer (http://software.schmorp.de/pkg/libev.html)
- asciidoc (optional for creating man pages)

To build pingu without man pages run configure --disable-doc


