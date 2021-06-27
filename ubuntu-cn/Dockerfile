FROM ubuntu:20.04
RUN sed -i 's/archive.ubuntu.com/mirrors.cloud.tencent.com/g; s/security.ubuntu.com/mirrors.cloud.tencent.com/g' /etc/apt/sources.list \
    && rm -f /etc/apt/apt.conf.d/docker-gzip-indexes
