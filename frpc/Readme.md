# frpc

[frp](https://github.com/fatedier/frp) is a fast reverse proxy written in Go.

Use with Podman Pods.

Example: The following command expose port 8080 inside pod to 192.168.0.1:28080

```shell
podman run --pod=... -itd frpc 192.168.0.1 7000 test-service tcp 8080 28080
```
