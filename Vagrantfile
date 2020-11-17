# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.

DR_VERSION = "8.0.18523"
DR_RELEASES_URL = "https://github.com/DynamoRIO/dynamorio/releases/download"
DR_TAR = "DynamoRIO-Linux-#{DR_VERSION}.tar.gz"
DR_URL = "#{DR_RELEASES_URL}/cronbuild-#{DR_VERSION}/#{DR_TAR}"

HALIDE_VERSION = "10.0.0"
HALIDE_RELEASES_URL = "https://github.com/halide/Halide/releases/download"
HALIDE_PLATFORM = "x86-64-linux"
HALIDE_HASH = "db901f7f7084025abc3cbb9d17b0f2d3f1745900"
HALIDE_TAR = "Halide-#{HALIDE_VERSION}-#{HALIDE_PLATFORM}-#{HALIDE_HASH}.tar.gz"
HALIDE_URL = "#{HALIDE_RELEASES_URL}/v#{HALIDE_VERSION}/#{HALIDE_TAR}"

WGET_CACHE = "/var/cache/wget"

Vagrant.configure("2") do |config|
  config.ssh.forward_agent = true

  config.vm.box = "generic/ubuntu2004"
  config.vm.synced_folder ".", "/vagrant"

  if Vagrant.has_plugin?("vagrant-cachier")
    config.cache.scope = :box
    config.cache.enable :apt
    config.cache.enable :generic, {
      "wget" => { cache_dir: "/var/cache/wget" },
    }
  end

  config.vm.provider "virtualbox" do |vb|
    vb.memory = 4096
    vb.cpus = 4
  end

  config.vm.provision "shell", inline: <<-SHELL
    apt-get update
    apt-get install -y \
      build-essential \
      cmake \
      git \
      libjpeg-dev \
      libpng-dev \
      ninja-build \
      python3 \
      wget
  SHELL

  config.vm.provision "shell", privileged: false, inline: <<-SHELL
    echo 'source $HOME/env.sh' >> $HOME/.profile
  SHELL

  config.vm.provision "shell", privileged: false, inline: <<-SHELL
    wget --quiet -N -P #{WGET_CACHE} #{DR_URL}
    mkdir -p $HOME/dynamorio
    tar xf #{WGET_CACHE}/#{DR_TAR} -C $HOME/dynamorio --strip-components 1

    touch $HOME/env.sh
    echo 'export DR_ROOT=$HOME/dynamorio' >> $HOME/env.sh
  SHELL

  config.vm.provision "shell", privileged: false, inline: <<-SHELL
    wget --quiet -N -P #{WGET_CACHE} #{HALIDE_URL}
    mkdir -p $HOME/halide
    tar xf #{WGET_CACHE}/#{HALIDE_TAR} -C $HOME/halide --strip-components 1

    touch $HOME/env.sh
    echo 'export HALIDE_ROOT=$HOME/halide' >> $HOME/env.sh
  SHELL

  config.vm.provision "shell", privileged: false, inline: <<-SHELL
    git clone git@github.com:mob-group/grey-benchmarks.git
    cd grey-benchmarks
    mkdir build
    cd build
    cmake -GNinja ..
    ninja
  SHELL
end
