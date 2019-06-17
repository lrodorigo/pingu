
Fork of pingu
=====

Pingu is a daemon that takes care of policy routing and fail-over in
multi ISP setups.

**This fork is born to overcome some stupid features of the router installed by the major Italian ISP (aka TIM==Telecom Italia).**

Seems that, after a  disconnection of the carrier, these routers block all the ICMP responses with an `Identifier` field already seen before the disconnection. 

This version changes the `Identifier` (which, by Linux convention, reports the PID of the process sending the ICMP request). The modified `Identifier` field is placed to  the same value of the `Sequence number`, and the processing of the incoming ICMP request has been modified to compare the `Indentifier` field with the `Sequence number`.




Features
--------
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


