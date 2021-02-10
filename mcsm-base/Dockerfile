FROM ubuntu-cn-systemd:latest
RUN apt update \
    && apt install -y wget git \
    && rm -rf /var/lib/apt/lists/* \
    && wget -qO- https://gitee.com/Suwingser/MCSManager-installer/raw/master/install.sh | bash \
    && systemctl enable mcsm

