# ubuntu-cn

apt源更换为 [腾讯云 Ubuntu镜像](http://mirrors.cloud.tencent.com/), 加速大陆用户镜像构建.

移除了 [`docker-gzip-indexes`](https://github.com/moby/moby/blob/9a9fc01af8fb5d98b8eec0740716226fadb3735c/contrib/mkimage/debootstrap#L118-L130) 解决部分场景下apt拉取失败的问题.
