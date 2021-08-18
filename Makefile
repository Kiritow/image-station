ubuntu:
	echo 'base requirement'

clean:
	podman rmi $(shell podman images -f dangling=true -q)

ubuntu-cn: ubuntu
	cd ubuntu-cn && podman build . -t ubuntu-cn

ubuntu-cn-systemd: ubuntu-cn
	cd ubuntu-cn-systemd && podman build . -t ubuntu-cn-systemd

ssh-base: ubuntu-cn-systemd
	cd ssh-base && podman build . -t ssh-base

simple-wireguard: ubuntu-cn-systemd
	cd simple-wireguard && podman build . -t simple-wireguard
