FROM mcr.microsoft.com/devcontainers/cpp:debian-12

RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends \
        pipx \
    && apt-get clean

USER vscode

RUN pipx install online-judge-tools
RUN pipx install online-judge-verify-helper
