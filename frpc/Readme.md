# frpc

[frp](https://github.com/fatedier/frp) is a fast reverse proxy written in Go.

Use with Podman Pods.

Example: The following command expose port 8080 inside pod to frp server 192.168.0.1:28080, which listens on port 7000.

```shell
podman run --pod=... -d frpc 192.168.0.1 7000 test-service tcp 8080 28080
```

With token:

```bash
podman run --pod=... -d -v tokenFile:/tmp/token frpc -f /tmp/token 192.168.0.1 7000 test-service tcp 8080 28080
```

## Usage

**launcher** [-ezkn] [-p _PoolSize_] [-f _TokenFile_] _ServerIP_ _ServerPort_ _ProxyName_ _ProxyType_ _LocalPort_ _RemotePort_

`-e` Use encryption

`-z` Use compression

`-k` Use KCP protocol

`-n` Don't start frpc. (dry-run)

`-p PoolSize` Frp worker pool size

`-f TokenFile` Use Token

`-m Key=Value` Define metadata
