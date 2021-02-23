FROM ubuntu-cn-systemd:latest
RUN apt update \
  && apt install -y wireguard iproute2 \
  && rm -rf /var/lib/apt/lists/*
COPY ./scripts /opt/wireguard
RUN mv /opt/wireguard/wg0.service /lib/systemd/system && systemctl enable wg0
