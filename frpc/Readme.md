# frp client

Start container with pod (using podman):

```shell
podman run --pod=... -itd frpc 192.168.0.1 7000 test-service tcp 8080 28080
```
