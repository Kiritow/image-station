mkdir -p temp
cd temp
wget https://factorio.com/get-download/stable/headless/linux64 -O factorio_headless_x64_latest_stable.tar.xz
mkdir -p factorio
tar --strip-components=1 -xJvf factorio_headless_x64_latest_stable.tar.xz -C factorio

