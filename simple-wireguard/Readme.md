# wireguard

Use with Pod. Example command line:

```bash
sudo podman run --pod=test -d --cap-add=NET_ADMIN -v /etc/wireguard:/etc/wireguard --sysctl="net.ipv4.conf.all.src_valid_mark=1" simple-wireguard
```

