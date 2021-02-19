#!/bin/bash
sed "s/__server_addr__/$1/g; s/__server_port__/$2/g; s/__service_name__/$3/g; s/__type__/$4/g; s/__local_port__/$5/g; s/__remote_port__/$6/g" /opt/frp/frpc.ini.template > /opt/frp/frpc.ini
/opt/frp/frpc -c /opt/frp/frpc.ini
