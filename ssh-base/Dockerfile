FROM ubuntu-cn-systemd:latest
RUN apt update \
	&& apt install openssh-server -y \
	&& rm -rf /var/lib/apt/lists/* \
	&& rm -f /run/nologin

# Default: No password login, No PAM
RUN sed -e 's/UsePAM yes/UsePAM no/g' -e 's/#PasswordAuthentication yes/PasswordAuthentication no/g' -i /etc/ssh/sshd_config

# Another method: Leave PAM on, but it needs a few more fixes.

# 1. PAM LoginUID fix. Otherwise user is kicked off after login.
# Or you might start container with --cap-add AUDIT_CONTROL
# RUN sed 's@session\s*required\s*pam_loginuid.so@session optional pam_loginuid.so@g' -i /etc/pam.d/sshd

# 2. systemd-logind hang 25s fix
# RUN sed 's/ProtectHostname=yes/ProtectHostname=no/g' -i /lib/systemd/system/systemd-logind.service

