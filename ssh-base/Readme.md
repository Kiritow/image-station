# ssh-base

This is the base image of ssh server, bundled with systemd.

By default, `UsePAM` and `PasswordAuthentication` are both set to `no`.

The Dockerfile contains an alternative way to setup sshd, which could leave `UsePAM` set to `yes`.

The following fixes are included:

1. `/etc/pam.d/sshd` fix

    `pam_loginuid.so` is set to optional, otherwise user will be kicked off after login.
    
    https://stackoverflow.com/questions/28134239/how-to-ssh-into-docker

2. `/run/nologin` removed

    Prevents ssh login from printing `System is booting up. Unprivileged users are not permitted to log in yet. Please come back later. For technical details, see pam_nologin(8).`

    https://stackoverflow.com/questions/58682387/error-while-trying-to-ssh-a-docker-container-system-is-booting-up

3. `systemd-logind.service` fix

    `ProtectHostname` is set to `no`. This fixes 25 second of hang up every login.

    https://bugzilla.redhat.com/show_bug.cgi?id=1841139

