#!/bin/bash
wg syncconf wg0 <(wg-quick strip /etc/wireguard/wg0.conf)
