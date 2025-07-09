# How to install NVIDIA HPC SDK on Windows using WSL

<h3>1. Install Ubuntu WSL distro</h3>
Open Microsoft Store and look for Ubuntu and install
![ms-store](https://github.com/user-attachments/assets/5c34f137-9791-4d6d-bd17-c33e4cbea8d1)
To verify open Windows PowerShell run the command: <code>wsl -l -v</code>
![ps-wsl](https://github.com/user-attachments/assets/357b3762-bb7c-4c60-a422-e932a0711800)

<h3>2. Install Ubuntu WSL distro</h3>

```
$  curl https://developer.download.nvidia.com/hpc-sdk/ubuntu/DEB-GPG-KEY-NVIDIA-HPC-SDK | sudo gpg --dearmor -o /usr/share/keyrings/nvidia-hpcsdk-archive-keyring.gpg
```
