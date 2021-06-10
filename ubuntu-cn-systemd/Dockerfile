FROM ubuntu-cn:latest
RUN apt update \
  && echo 'tzdata tzdata/Areas select Asia' >> /root/preseed.cfg \
  && echo 'tzdata tzdata/Zones/Asia select Shanghai' >> /root/preseed.cfg \
  && debconf-set-selections /root/preseed.cfg \
  && rm -f /etc/timezone /etc/localtime \
  && DEBIAN_FRONTEND=noninteractive DEBCONF_NONINTERACTIVE_SEEN=true apt install -y systemd \
  && rm -rf /var/lib/apt/lists/* \
  && rm -rf /tmp/* /var/tmp/* \
  && rm /root/preseed.cfg \
  && sed 's/ProtectHostname=yes/ProtectHostname=no/g' -i /lib/systemd/system/systemd-logind.service \
  && cd /lib/systemd/system/sysinit.target.wants/ \
  && ls | grep -v systemd-tmpfiles-setup | xargs rm -f $1 \
  && rm -f /lib/systemd/system/multi-user.target.wants/* \
    /etc/systemd/system/*.wants/* \
    /lib/systemd/system/local-fs.target.wants/* \
    /lib/systemd/system/sockets.target.wants/*udev* \
    /lib/systemd/system/sockets.target.wants/*initctl* \
    /lib/systemd/system/basic.target.wants/* \
    /lib/systemd/system/anaconda.target.wants/* \
    /lib/systemd/system/plymouth* \
    /lib/systemd/system/systemd-update-utmp*
ENTRYPOINT ["/bin/systemd"]
