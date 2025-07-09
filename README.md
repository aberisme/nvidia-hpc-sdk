# How to install NVIDIA HPC SDK on Windows using WSL

1. Install Ubuntu WSL distro
Open Microsoft Store and look for Ubuntu and install
![ms-store](https://github.com/user-attachments/assets/5c34f137-9791-4d6d-bd17-c33e4cbea8d1)

```
$  curl https://developer.download.nvidia.com/hpc-sdk/ubuntu/DEB-GPG-KEY-NVIDIA-HPC-SDK | sudo gpg --dearmor -o /usr/share/keyrings/nvidia-hpcsdk-archive-keyring.gpg
```
