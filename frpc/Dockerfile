# Stage 0
FROM ubuntu-cn:latest
RUN apt update \
    && apt install -y curl jq build-essential \
    && rm -rf /var/lib/apt/lists/* \
    && rm -rf /tmp/* /var/tmp/*
RUN cd /root \
    && LATEST_TAG=`curl --silent "https://api.github.com/repos/fatedier/frp/releases/latest" | jq -r .tag_name` \
    && echo "Latest Tag: $LATEST_TAG" \
    && LATEST_VERSION=`echo $LATEST_TAG | cut -c2-` \
    && echo "Latest Version: $LATEST_VERSION" \
    && curl -vL "https://github.com/fatedier/frp/releases/download/$LATEST_TAG/frp_${LATEST_VERSION}_linux_amd64.tar.gz" -o frp.tgz \
    && mkdir temp \
    && tar -xzvf frp.tgz --strip-component=1 -C temp \
    && mkdir frp_client \
    && cp temp/frpc frp_client/frpc
COPY launcher.cpp /tmp/
RUN cd /tmp \
    && g++ launcher.cpp -Os -s -static -o /root/frp_client/launcher \
    && chmod +x /root/frp_client/frpc \
    && chmod +x /root/frp_client/launcher

# Stage 1
FROM scratch
COPY --from=0 /root/frp_client /
ENTRYPOINT ["/launcher"]
