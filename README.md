# How to install NVIDIA HPC SDK on Windows using WSL

<h3>1. Install Ubuntu WSL distro</h3>
Open Microsoft Store and look for Ubuntu and install

![ms-store](https://github.com/user-attachments/assets/5c34f137-9791-4d6d-bd17-c33e4cbea8d1)

To verify open Windows PowerShell run the command: <code>wsl -l -v</code>

![ps-wsl](https://github.com/user-attachments/assets/357b3762-bb7c-4c60-a422-e932a0711800)


<h3>2. Install NVIDIA graphics driver</h3>
Go to the offical NVIDIA website for driver downloads and download the driver for your graphics card model (https://www.nvidia.com/en-us/drivers/).

![nvidia-drivers](https://github.com/user-attachments/assets/b53aea65-cf90-442d-8162-1006b973bf4a)

To verify open Windows PowerShell or Command Prompt and run the command: <code>nvidia-smi</code>

![ps-nvidia](https://github.com/user-attachments/assets/bbc0e7e6-0ce5-414e-8bfe-9b80b89e0878)

You will also have the NVIDIA App and NVIDIA Control Panel if you installed it properly. Search it in your Windows Explorer.

![nvidia-apps](https://github.com/user-attachments/assets/725d290f-63cb-4a47-b0ef-5cf6859e3082)

<h3>3.	Install CUDA Toolkit for Windows from NVIDIA</h3>
Go to NVIDIA website and download the CUDA Toolkit for Windows (https://developer.nvidia.com/cuda-downloads). Make sure to select proper OS, architecture, version, installer type.

![cuda-toolkit](https://github.com/user-attachments/assets/e5607da5-edb0-472b-8c89-478e2b86a714)

<h3>4. Update WSL distro</h3>
Open the WSL (i.e. Ubuntu) you installed from the MS Store and update distro package and versions using the commands:

```
$  sudo apt update
$  sudo apt upgrade
```

<h3>5. Install CUDA Toolkit for Ubuntu </h3>
In your WSL, install CUDA Toolkit for Ubuntu distro using the command:

```
$  sudo apt install nvidia-cuda-toolkit
```

```
$  curl https://developer.download.nvidia.com/hpc-sdk/ubuntu/DEB-GPG-KEY-NVIDIA-HPC-SDK | sudo gpg --dearmor -o /usr/share/keyrings/nvidia-hpcsdk-archive-keyring.gpg
```
