# Stage 0
FROM ubuntu-cn:latest
RUN apt update \
    && apt install -y curl xz-utils \
    && rm -rf /var/lib/apt/lists/* \
    && rm -rf /tmp/* /var/tmp/*
RUN cd /root \
    && curl -vL https://factorio.com/get-download/stable/headless/linux64 -o factorio_headless_x64_latest_stable.tar.xz \
    && mkdir factorio \
    && tar --strip-components=1 -xJvf factorio_headless_x64_latest_stable.tar.xz -C factorio

# Stage 1
FROM mcsm-base:latest
COPY ./bg.jpg /opt/MCSManager/public/login/static/
COPY --from=0 /root/factorio /opt/factorio
