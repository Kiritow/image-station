FROM ubuntu-cn-systemd:latest
RUN apt update \
  && apt install -y wireguard iproute2 \
  && rm -rf /var/lib/apt/lists/* \
  && systemctl enable wg-quick@wg0

