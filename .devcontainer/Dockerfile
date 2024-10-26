FROM mcr.microsoft.com/devcontainers/cpp:debian-12

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        python3-pip pipx \
    && apt-get clean

# oj-verify
RUN pipx install online-judge-verify-helper
