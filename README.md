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

<h3>6. Install NVIDIA HPC SDK</h3>
Go to NVIDIA HPC SDK download site (https://developer.nvidia.com/hpc-sdk-downloads) and choose Linux x86_64 Ubuntu(apt). Run the given commands.

![nvidia-hpc](https://github.com/user-attachments/assets/9c4c02e7-4681-411b-baea-44b61b264040)
Commands from the website:
```
$  curl https://developer.download.nvidia.com/hpc-sdk/ubuntu/DEB-GPG-KEY-NVIDIA-HPC-SDK | sudo gpg --dearmor -o /usr/share/keyrings/nvidia-hpcsdk-archive-keyring.gpg
$  echo 'deb [signed-by=/usr/share/keyrings/nvidia-hpcsdk-archive-keyring.gpg] https://developer.download.nvidia.com/hpc-sdk/ubuntu/amd64 /' | sudo tee /etc/apt/sources.list.d/nvhpc.list
$  sudo apt-get update -y
$  sudo apt-get install -y nvhpc-25-5
```

<h3>7. Verify your NVIDIA HPC SDK installation</h3>
To verify NVIDIA HPC SDK installation, use the commad: <code>nvaccelinfo -v</code>
For successful installation you get this output:

![nvidia-hpc-sdk](https://github.com/user-attachments/assets/74c8788e-1edb-4057-aff5-cb1417306d61)

If you got the message <code style='color:red'>command not found</code>  as shown below proceed with the following steps to path the SDK to environment.

![not-found](https://github.com/user-attachments/assets/dac20c89-c424-49c3-8183-6bca1077379f)

Add the following <code>export</code> to your bash:

```
sudo nano ~/.bashrc

export LD_LIBRARY_PATH="/usr/lib/wsl/lib/"
export PATH=/opt/nvidia/hpc_sdk/Linux_x86_64/25.5/compilers/bin:$PATH

source ~/.bashrc
```
<b style = 'color:red'>• IMPORTANT:</b> Make sure to check the path first using <code>cd</code> and <code>ls</code> before <code>export</code>

<h3>8. Verify NVIDIA Compiler</h3>
To verify NVIDIA Compiler for C++, use the given command in your WSL terminal: <code>nvc++ --version</code>

![nvcpp](https://github.com/user-attachments/assets/fbaae7f4-c6de-4b53-8b2e-c05ae5e40752)

<h3>9. Compile your code</h3>
You are now ready to go. Compiling commands below:
<br/>
<br/>

Compile using g++

```g++ [filename.cpp] -o [output-filename]```

Compile using NVIDIA Compiler

```nvc++ [filename.cpp] -o [output-filename]```

Compile using NVIDIA Compiler with OpenAcc

```nvc++ -acc=host [filename.cpp] -o [output-filename]```

Compile using NVIDIA Compiler with OpenAcc and dedicated GPU (e.g. cc89)

```nvc++ -acc=gpu -gpu=cc89 [filename.cpp] -o [output-filename]```

---
<h3>Link to video tutorial below:</h3>

[![NVIDIA HPC SDK](https://img.youtube.com/vi/GEjm7NKiY70/0.jpg)](https://youtu.be/GEjm7NKiY70)
