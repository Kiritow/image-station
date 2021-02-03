FROM ubuntu:20.04
RUN sed 's/archive.ubuntu.com/mirrors.aliyun.com/g; s/security.ubuntu.com/mirrors.aliyun.com/g' /etc/apt/sources.list > /etc/apt/sources.list.new && mv /etc/apt/sources.list.new /etc/apt/sources.list && rm -f /etc/apt/apt.conf.d/docker-gzip-indexes
