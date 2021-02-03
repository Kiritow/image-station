# Stage 0
FROM ubuntu-cn:latest
RUN apt update && apt install -y curl && rm -rf /var/lib/apt/lists/*
RUN cd /root \
    && curl -vL https://github.com/fatedier/frp/releases/download/v0.35.1/frp_0.35.1_linux_amd64.tar.gz -o frp.tgz \
    && mkdir temp \
    && tar -xzvf frp.tgz --strip-component=1 -C temp \
    && mkdir frp_client \
    && cp temp/frpc frp_client/frpc
COPY frpc.ini frp_client/

# Stage 1
FROM ubuntu-cn:latest
COPY --from=0 frp_client /opt/frp
ENTRYPOINT sed -i "s/__server_addr__/$0/g; s/__server_port__/$1/g; s/__service_name__/$2/g; s/__type__/$3/g; s/__local_port__/$4/g; s/__remote_port__/$5/g" /opt/frp/frpc.ini && /opt/frp/frpc -c /opt/frp/frpc.ini
