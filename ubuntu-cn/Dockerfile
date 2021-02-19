FROM ubuntu:20.04
RUN sed -i 's/archive.ubuntu.com/mirrors.aliyun.com/g; s/security.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list \
    && rm -f /etc/apt/apt.conf.d/docker-gzip-indexes
